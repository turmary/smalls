ENTRY(current)
SECTIONS {
	. = 0x1000;
	SECTIONX : AT(0) {
		LONG(0x12345600)
		. = 0x100;
		sx_size = .;
	} = 0x5005A00A
	current = .;
	sx_size -= ADDR(SECTIONX);
	SECTION1 0x2000 : AT(0x100) {
		LONG(1)
		LONG(2)
		BYTE(3)
		BYTE(4)
		BYTE(5)
		. = ALIGN(20);
	} = 0xABCDEF01
	SECTION2 : AT (0x120) {
		LONG(0x12345678)
		LONG(0x55AA55AA)
		BYTE(8)
		FILL(0x5A5A5A5A)
	} = 0xA5A5A5A5
}
