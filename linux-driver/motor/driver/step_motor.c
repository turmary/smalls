// tary, 18:13 2011-6-29
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/jiffies.h>
#include <linux/cdev.h>
#include <linux/timer.h>

#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/io.h>


#define DEVICE_NAME	"step_motor"

#define level_high()	
#define level_low()
	

static dev_t dev_no;
static struct cdev *pst_motor;

static atomic_t wheel_counts = ATOMIC_INIT(0);


static int timer_start(int msecs, void (*tim_func)(unsigned long data)) {
	static struct timer_list step_timer;
	
	if (msecs <= 0 || tim_func == NULL) {
		return -1;
	}
	init_timer(&step_timer);

	step_timer.expires = jiffies + msecs * HZ / 1000 ;
	step_timer.data = 0;
	step_timer.function = tim_func;

	add_timer(&step_timer);
	return 0;
}

static void step_wheel_callback(unsigned long id) {
	int cnt;

	cnt = atomic_dec_return(&wheel_counts);
	if (cnt == 0) {
		level_low();
		return;
	}
	if (cnt & 0x01) {
		level_low();
	} else {
		level_high();
	}

	dump_stack();
	// timer_start(10, step_wheel_callback);
	return;
}

static int step_wheel(int times) {
	int this_times;

	if (times == 0) {
		return -1;
	}

	this_times = atomic_read(&wheel_counts);
	if (this_times != 0) {
		atomic_set(&wheel_counts, 2 * times);
		return -1;
	}
	atomic_set(&wheel_counts, 2 * times);
	timer_start(10, step_wheel_callback);
	return 0;
}

static void step_motor_init(void)
{
	level_low();
	printk("step motor init.\n");
	return;
}

static ssize_t motor_read(struct file *file, char __user *buf, 
			  size_t count, loff_t *ppos)
{
	int angle;

	angle = atomic_read(&wheel_counts);
	angle = 18 * (angle / 2) / 10;
	if(copy_to_user(buf, &angle, sizeof angle))
		return -EFAULT;
	return (sizeof(int));
}

static ssize_t motor_write(struct file *filp, const char *buf,
			   size_t count, loff_t * offp)
{
	int angle;

	if (count > 4)
		count = 4;
	if (copy_from_user(&angle, buf, count))
		return -EFAULT;

	// only for debug
	// printk("angle = %d\n", angle);
	if (angle > 0) {	//每周期转动1.8度
		step_wheel(angle * 10 / 18);
	}
	return count;
}

static atomic_t st_motor_ref = ATOMIC_INIT(1);

static int motor_open(struct inode *inode, struct file *filp)
{
	//filp->private_data = inode->i_cdev;

	// 步进电机硬件初使化只做一次
	if (atomic_dec_return(&st_motor_ref) == 0) {
		step_motor_init();
		return 0;
	}
	atomic_inc(&st_motor_ref);
	return -EFAULT;
}


static int motor_release(struct inode *inode, struct file *filp)
{
	atomic_set(&st_motor_ref, 1);
	return 0;
}

static struct file_operations motor_fops = {

	.owner = THIS_MODULE,
	.write = motor_write,
	.read  = motor_read,
	.open = motor_open,
	.release = motor_release,
};

static int __init motor_init(void)
{
	struct cdev *pdev;

	alloc_chrdev_region(&dev_no, 0, 1, DEVICE_NAME);
	pdev = cdev_alloc();
	cdev_init(pdev, &motor_fops);
	pdev->dev = dev_no;
	if (cdev_add(pdev, dev_no, 1)) {
		printk("steping motor: can't add device.\n");
		goto err1;
	}
	pst_motor = pdev;

	printk("steping motor driver initial\n");
	return 0;

err1:
	unregister_chrdev_region(dev_no, 1);
	return 0;
}

static void __exit motor_exit(void)
{
	cdev_del(pst_motor);
	unregister_chrdev_region(dev_no, 1);

	printk("steping motor driver removed\n");
}

module_init(motor_init);
module_exit(motor_exit);

MODULE_ALIAS("step motor");
MODULE_DESCRIPTION("STEPING MOTOR Driver For EDUK4");
MODULE_AUTHOR("tary, turmary@126.com");
MODULE_LICENSE("GPL");

