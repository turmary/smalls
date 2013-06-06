/*
 *  sii9022a.c - Linux kernel modules for SiI9022A HDMI transmitter
 *
 *  Copyright (C) 2012 turmary <turmary@126.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/mutex.h>
#include <linux/delay.h>
#include <linux/fb.h>

#define I2C_RETRY_CNT		(5)

struct sii9022a_data {
	struct i2c_client *client;
};

static int sii9022a_write(struct sii9022a_data* data, u8* buf, u8 len) {
	int r;
	struct i2c_msg msg[] = {
		{
			.addr = data->client->addr,
			.flags = data->client->flags,
			.len = len,
			.buf = buf,
		},
	};

	r = i2c_transfer(data->client->adapter, msg, ARRAY_SIZE(msg));

	return r == ARRAY_SIZE(msg)? 0: -EIO;
}

static int sii9022a_read(struct sii9022a_data* data, u8 addr, u8* buf, u8 len) {
	int r;

	struct i2c_msg msg[] = {
		{
			.addr = data->client->addr,
			.flags = data->client->flags,
			.len = sizeof addr,
			.buf = &addr,
		},
		{
			.addr = data->client->addr,
			.flags = data->client->flags | I2C_M_RD,
			.len = len,
			.buf = buf,
		},
	};

	r = i2c_transfer(data->client->adapter, msg, ARRAY_SIZE(msg));

	return r == ARRAY_SIZE(msg)? 0: -EIO;
}

#define CHK_ACC()	if (r < 0) {						\
		printk("%s() acess error in line %d\n", __func__, __LINE__);	\
		return r;							\
	}

#define LO_BYTE(x)	((u8)((x) & 0xFF))
#define HI_BYTE(x)	((u8)((x) >> 0x8))
#define GET_WORD(l, h)	(((u16)(h) << 8) | (l))

static int sii9022a_write_reg(struct sii9022a_data* data, u8 addr, u8 val) {
	int r;
	u8 w_reg[2];

	w_reg[0] = addr;
	w_reg[1] = val;

	r = sii9022a_write(data, w_reg, sizeof w_reg);
	if (r < 0) {
		printk("%s() write [0x%.2X] error\n", __func__, addr);
	}
	return r;
}

static int sii9022a_write_word(struct sii9022a_data* data, u8 addr, unsigned word) {
	int r;
	u8 w_reg[3];

	w_reg[0] = addr;
	w_reg[1] = LO_BYTE(word);
	w_reg[2] = HI_BYTE(word);

	r = sii9022a_write(data, w_reg, sizeof w_reg);
	if (r < 0) {
		printk("%s() write [0x%.2X] error\n", __func__, addr);
	}
	return r;
}

static int sii9022a_read_reg(struct sii9022a_data* data, u8 addr) {
	int r;
	u8 w_reg[1];

	r = sii9022a_read(data, addr, w_reg, sizeof w_reg);
	if (r < 0) {
		printk("%s() read [0x%.2X] error\n", __func__, addr);
		return r;
	}
	return w_reg[0];
}

static int sii9022a_read_word(struct sii9022a_data* data, u8 addr) {
	int r;
	u8 w_reg[2];

	r = sii9022a_read(data, addr, w_reg, sizeof w_reg);
	if (r < 0) {
		printk("%s() read [0x%.2X] error\n", __func__, addr);
		return r;
	}
	return ((u16)w_reg[1] << 8) | w_reg[0];
}

#define DE_DLY		(48 + 1)
#define DE_CNT		800
#define H_RES		(DE_DLY + DE_CNT + 1)
#define DE_TOP		(3 + 25)
#define DE_LIN		480
#define V_RES		(DE_TOP + DE_LIN + 12)
#define PXL_CLK		26520000

#define ASPECT_RATIO_NONE	0x08
#define ASPECT_RATIO_4_3	0x18
#define ASPECT_RATIO_16_9	0x28

struct video_mode_map {
	u16 xres;
	u16 yres;
	u8	video_code;
	u8	refresh;
	u8	aspect_ratio;
};

#define MAX_XRES	2048
#define MAX_YRES	2048
#define DIFF(a,b) (a>b ? a-b : b-a)

static struct video_mode_map vmode_map[] = {
	{ 1, 1, 0, 60, ASPECT_RATIO_NONE },
	{ 640, 480, 1, 60, ASPECT_RATIO_4_3 },
	{ 720, 480, 3, 50, ASPECT_RATIO_16_9 },
	{ 720, 576, 17, 50, ASPECT_RATIO_4_3 },
/*
	{ 800, 600, 0, 60, ASPECT_RATIO_4_3 },
	{ 1024, 768, 0, 60, ASPECT_RATIO_4_3 },
*/
	{ 1280, 720, 4, 60, ASPECT_RATIO_16_9 },
	{ 1280, 720, 19, 50, ASPECT_RATIO_16_9 },
	{ 1280, 768, 0, 60, ASPECT_RATIO_16_9 },
	{ 1360, 768, 0, 60, ASPECT_RATIO_16_9 },
	{ 1680, 1050, 0, 60, ASPECT_RATIO_16_9 },
	{ 1920, 1080, 33, 25, ASPECT_RATIO_16_9 },
	{ 1920, 1080, 34, 30, ASPECT_RATIO_16_9 },
	{ MAX_XRES+1, MAX_YRES+1, 0, 0, ASPECT_RATIO_NONE},
};

int video_mode_map_get(__u32 x, __u32 y, u32 refresh)
{
	int i=0; 
	
	for (i = 0; (vmode_map[i].xres < MAX_YRES); i++ ) {
		if ( x > vmode_map[i].xres )
			continue;
		/* so that 1124x644 will be become 720p to avoid overscan issue */
		if (i && (x <= vmode_map[i].xres) && (y <= vmode_map[i].yres)) {
			/* refresh rate diff < 3Hz */
			if( DIFF(refresh, vmode_map[i].refresh) < 3 )
				return i;
			else
				continue;
		}

		if ( y > vmode_map[i].yres ) /* no similar found */
			return 0;
	}
	return 0;
}

static int sii9022a_video_init(struct sii9022a_data* data) {
	unsigned char avi_info[14] = { 
		0x00, 0x12, 0x28, 0x00,
		0x04, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00 
	}; 
	struct i2c_client* client = data->client;
	int vmap_idx = 0;
	int refresh_rate = 6000;
	int i;
	u8 cksum;


	// burst write 720p60 AVI infoframe to Reg 0c-19 
	vmap_idx = video_mode_map_get( DE_CNT, DE_LIN, refresh_rate/100 );
	cksum = 0x82 + 0x02 + 0x0d;
	avi_info[2] = vmode_map[vmap_idx].aspect_ratio; //16:9 , 4:3 
	avi_info[4] = vmode_map[vmap_idx].video_code; //video code 720p@60: 4, 720p@50: 19  
	for( i=0; i < 14; i++ )
		cksum += avi_info[i];
	avi_info[0] = 0x100 - cksum;

	i2c_smbus_write_i2c_block_data(client, 0x0C, 14, avi_info );

	dev_printk( KERN_INFO, &client->dev, "idx %d pclk %lu refresh %u total x %u y %u\n", 
		vmap_idx,
		((PICOS2KHZ(PXL_CLK)/10)), 
		refresh_rate,
		H_RES,V_RES );

	return 0;
}


static int __devinit sii9022a_init_hw(struct sii9022a_data* data) {
	int i, r;
	u8 reset[] = { 0xC7, 0x00 };
	u8 id[3];

	/* Reset and Initialize */
	for (i = 0; i < 10; i++) {
		r = sii9022a_write(data, reset, sizeof reset);
		if (r >= 0) break;
		msleep(50);
	}
	if (r < 0) {
		printk("%s() Reset Failed\n", __func__);
		return r;
	}
	printk("%s() Reset OK\n", __func__);

	/* Detect Revision */
	for (i = 0; i < 20; i++) {
		r = sii9022a_read(data, 0x1B, id, sizeof id);
		if (r >= 0) break;
		msleep(50);
	}
	if (r < 0) {
		printk("%s() Detect Revision Failed\n", __func__);
		return r;
	}
	printk("%s() Revision %.2X %.2X %.2X\n", __func__,
		id[0], id[1], id[2]);

	/* Enable Source Termination */
	r = sii9022a_write_word(data, 0xBC, 0x8201);
	CHK_ACC();
	r = sii9022a_read_reg(data, 0xBE);
	CHK_ACC();
	r = sii9022a_write_reg(data, 0xBE, r & ~0x01);
	CHK_ACC();

	/* Power up transmitter */
	r = sii9022a_read_reg(data, 0x1E);
	CHK_ACC();
	r = sii9022a_write_reg(data, 0x1E, r & ~0x03);
	CHK_ACC();

	/* Configure Input Bus and Pixel Repetition */
	r = sii9022a_write_reg(data, 0x08, 0x60);
	CHK_ACC();

	/* Select YC Input Mode */
	r = sii9022a_write_reg(data, 0x0B, 0x04);
	CHK_ACC();

	/* Configure Sync Methods */
	r = sii9022a_write_word(data, 0x60, GET_WORD(0x04, 0x02 | 0x01));
	CHK_ACC();


	/* Configure Explicit Sync DE Generation */
	r = sii9022a_write_word(data, 0x62, DE_DLY | 0x7000);
	CHK_ACC();
	r = sii9022a_write_reg(data, 0x64, DE_TOP);
	CHK_ACC();
	r = sii9022a_write_word(data, 0x66, DE_CNT);
	CHK_ACC();
	r = sii9022a_write_word(data, 0x68, DE_LIN);
	CHK_ACC();


	/* Input Setup Operations */
	r = sii9022a_write_word(data, 0x0, PXL_CLK / 10000);
	CHK_ACC();
	r = sii9022a_write_word(data, 0x2, PXL_CLK / (H_RES * V_RES));
	CHK_ACC();
	printk("%s() rate = %d\n", __func__, PXL_CLK / (H_RES * V_RES));
	r = sii9022a_write_word(data, 0x4, H_RES);
	CHK_ACC();
	r = sii9022a_write_word(data, 0x6, V_RES);
	CHK_ACC();

	r = sii9022a_write_reg(data, 0x09, 0x00);
	CHK_ACC();
	r = sii9022a_write_reg(data, 0x0A, 0x00);
	CHK_ACC();
	r = sii9022a_write_reg(data, 0x19, 0x00);
	CHK_ACC();

	sii9022a_write_reg(data, 0x1A, 0x11);
	msleep(128);
	sii9022a_write_reg(data, 0x1E, 0x00);
	sii9022a_write_reg(data, 0x26, 0x50);
	sii9022a_write_reg(data, 0x25, 0x03);
	sii9022a_write_reg(data, 0x27, 0x00);
	sii9022a_write_reg(data, 0x26, 0x40);
	sii9022a_video_init(data);
	sii9022a_write_reg(data, 0x1A, 0x01);

	return 0;
}

static int __devinit sii9022a_probe(struct i2c_client* client,
				const struct i2c_device_id* id)
{
	struct sii9022a_data* data;
	int ret;

	printk("~~~t~~~%s()\n", __func__);

	if ((data = kzalloc(sizeof(*data), GFP_KERNEL)) == NULL) {
		return -ENOMEM;
	}
	data->client = client;
	i2c_set_clientdata(client, data);

	if ((ret = sii9022a_init_hw(data)) < 0) {
		dev_err(&client->dev, "sii9022a initial failed\n");
		goto err_init;
	}

	printk("%s() Initialization complete\n", __func__);

err_init:
	kfree(data);
	return ret;
}

static int __devexit sii9022a_remove(struct i2c_client* client) {
	struct sii9022a_data* data = i2c_get_clientdata(client);
	kfree(data);
	return 0;
}

static const struct i2c_device_id sii9022a_idtable[] = {
	{ "sii9022a-tpi", 0 },
	{}
};

MODULE_DEVICE_TABLE(i2c, sii9022a_idtable);

static struct i2c_driver sii9022a_driver = {
	.driver = {
		.owner	= THIS_MODULE,
		.name	= "sii9022a-tpi"
	},
	.id_table	= sii9022a_idtable,
	.probe		= sii9022a_probe,
	.remove		= __devexit_p(sii9022a_remove),
};

static int __init sii9022a_init(void) {
	return i2c_add_driver(&sii9022a_driver);
}

static void __exit sii9022a_exit(void) {
	i2c_del_driver(&sii9022a_driver);
}

module_init(sii9022a_init);
module_exit(sii9022a_exit);

MODULE_AUTHOR("tary, Embest Tech Co.Ltd <turmary@126.com>");
MODULE_DESCRIPTION("SiI 9022A HDMI transmitter driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
