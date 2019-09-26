/*
 * Sniffer the i2c bus transfer
 *
 * turmary <turmary@126.com>
 * 12:17 2019/9/25 Initial version
 */

#define SCLpin 2
#define SDApin 3
#define I2C_MASK (_BV(SCLpin) | _BV(SDApin))

#define QUEUE_SIZE	128
#define QUEUE_ELEM_T	uint8_t
QUEUE_ELEM_T queue[QUEUE_SIZE];
volatile uint8_t queue_front = 0, queue_rear = 0;

static inline
int8_t queue_in(uint8_t data) {
	uint8_t front;

	front = (queue_front + 1) % QUEUE_SIZE;
	if (front == queue_rear ) {
		return -1;
	}

	queue[queue_front] = data;

	// noInterrupts();
	queue_front = front;
	// interrupts();
	return 0;
}

static inline
int8_t queue_out(QUEUE_ELEM_T* pdata) {
	QUEUE_ELEM_T data;

	if (queue_rear == queue_front) {
		return -1;
	}

	data = queue[queue_rear];

	noInterrupts();
	queue_rear = (queue_rear + 1) % QUEUE_SIZE;
	interrupts();

	if (pdata) {
		*pdata = data;
	}
	return 0;
}

volatile uint8_t last_level;

#define TIMEOUT	255
volatile uint8_t timeout;
// return whether timeout
static inline
int8_t wait_transition(uint8_t level) {
  // Wait a level changing
  timeout = TIMEOUT;
  do {
    last_level = PIND;
    if ((last_level ^ level) & _BV(SCLpin)) {
      break;
    }
  } while (--timeout > 0);
  if (timeout == 0) {
    queue_in('*');
  }
  return timeout == 0;
}

static inline
int8_t wait_scl_high() {
  timeout = TIMEOUT;
  do {
    last_level = PIND;
    if (last_level & _BV(SCLpin)) {
      break;
    }
  } while (--timeout > 0);
  if (timeout == 0) {
    queue_in('@');
  }
  return timeout == 0;
}

volatile uint8_t last_byte;

static inline
int8_t wait_a_byte() {
  uint8_t i;
  uint8_t val;

  val = 0;
  for (i = 0; i < 8; i++) {
    if (wait_scl_high()) {
      return -1;
    }
    val = (val << 1);
    if (last_level & _BV(SDApin))
      val |= 0x1;

    if (wait_transition(last_level)) {
      return -1;
    }
  }
  last_byte = val;
  return 0;
}

void i2c_sniffer() {
  last_level = PIND;
  if (wait_transition(last_level)) {
    return;
  }
  if (last_level & _BV(SCLpin)) {
    // a broken start
    return;
  }
  queue_in('S');

__next_byte:
  if (wait_a_byte()) {
    return;
  }

  queue_in((uint8_t)last_byte >> 4);
  // wait ACK
  if (wait_scl_high()) {
    return;
  }
  queue_in(last_byte & 0xF);
  if (0 == (last_level & _BV(SDApin))) {
    wait_transition(last_level);
    // Some body ACK
    goto __next_byte;
  }
  // No body ACK
  wait_transition(last_level);

  timeout = TIMEOUT;
__wait_stop:
  if ((PIND & I2C_MASK) != I2C_MASK) {
    if (--timeout == 0) {
      queue_in('#');
      return;
    }
    goto __wait_stop;
  }
  queue_in('P');
  return;
}

void setup() {
  // initialize serial communication
  Serial.begin(1000000);

  // PORT-D all pins as input
  DDRD = 0x00;
  // PORT-D all pins except SCL/SDA enable pullup
  PORTD = 0xF3;

  // initialize the SCL pin as a input
  pinMode(SCLpin, INPUT);
  // initialize the SDA pin as a input
  pinMode(SDApin, INPUT);

  // attach the interrupt handler
  attachInterrupt(digitalPinToInterrupt(SDApin), i2c_sniffer, FALLING);

  Serial.println("I2C Sniffer:");
}

void loop() {
  uint8_t data;

  if (queue_out(&data)) {
    return;
  }
  if (data < 0x10) {
    if (data < 10) {
      data += '0' -  0;
    } else {
      data += 'A' - 10;
    }
  }
  Serial.print((char)data);
  if (data == 'P')
    Serial.println();
}
