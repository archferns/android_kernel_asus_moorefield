/*
 * platform_scu_flis.c: scu_flis platform data initilization file
 *
 * (C) Copyright 2013 Intel Corporation
 * Author: Ning Li <ning.li@intel.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <linux/input.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <asm/intel-mid.h>
#include <asm/intel_mid_remoteproc.h>
#include <asm/intel_scu_flis.h>
#include "platform_scu_flis.h"

/* Cloverview Pin Table */
struct pinstruct_t ctp_pin_table[CTP_PIN_NUM] = {
	[i2s_2_clk]			 = { true,	0x01,	0x30,	0,	0x10,	2,	0x51,    0 },
	[i2s_2_fs]			 = { true,	0x01,	0x30,	6,	0x10,	6,	0x51,    1 },
	[i2s_2_rxd]			 = { true,	0x01,	0x30,	12,	0x10,	10,	0x51,    2 },
	[i2s_2_txd]			 = { true,	0x01,	0x30,	18,	0x10,	14,	0x51,    3 },
	[msic_reset_b]			 = { true,	0x01,	0x30,	24,	0x10,	18,	0x51,    4 },
	[spi_0_clk]			 = { true,	0x01,	0x31,	0,	0x10,	22,	0x51,    5 },
	[spi_0_sdi]			 = { true,	0x01,	0x31,	6,	0x10,	26,	0x51,    6 },
	[spi_0_sdo]			 = { true,	0x01,	0x31,	12,	0x11,	0,	0x51,    7 },
	[spi_0_ss]			 = { true,	0x01,	0x31,	18,	0x11,	4,	0x51,    8 },
	[svid_clkout]			 = { true,	0x01,	0x31,	24,	0x11,	8,	0x51,    9 },
	[svid_clksynch]			 = { true,	0x01,	0x32,	0,	0x11,	12,	0x51,    10 },
	[svid_din]			 = { true,	0x01,	0x32,	6,	0x11,	16,	0x51,    11 },
	[svid_dout]			 = { true,	0x01,	0x32,	12,	0x11,	20,	0x51,    12 },
	[usb_ulpi_clk]			 = { true,	0x01,	0x32,	18,	0x11,	24,	0x51,    13 },
	[usb_ulpi_data0]		 = { true,	0x01,	0x32,	24,	0x11,	28,	0x51,    14 },
	[usb_ulpi_data1]		 = { true,	0x01,	0x33,	0,	0x12,	0,	0x51,    15 },
	[usb_ulpi_data2]		 = { true,	0x01,	0x33,	6,	0x12,	4,	0x51,    16 },
	[usb_ulpi_data3]		 = { true,	0x01,	0x33,	12,	0x12,	8,	0x51,    17 },
	[usb_ulpi_data4]		 = { true,	0x01,	0x33,	18,	0x12,	12,	0x51,    18 },
	[usb_ulpi_data5]		 = { true,	0x01,	0x33,	24,	0x12,	16,	0x51,    19 },
	[usb_ulpi_data6]		 = { true,	0x01,	0x34,	0,	0x12,	20,	0x51,    20 },
	[usb_ulpi_data7]		 = { true,	0x01,	0x34,	6,	0x12,	24,	0x51,    21 },
	[usb_ulpi_dir]			 = { true,	0x01,	0x34,	12,	0x12,	28,	0x51,    22 },
	[usb_ulpi_nxt]			 = { true,	0x01,	0x34,	18,	0x13,	0,	0x51,    23 },
	[usb_ulpi_refclk]		 = { true,	0x01,	0x34,	24,	0x13,	4,	0x51,    24 },
	[usb_ulpi_stp]			 = { true,	0x01,	0x35,	0,	0x13,	8,	0x51,    25 },
	[ulpi1lpc_gpe_b]		 = { true,	0x02,	0x30,	0,	0x10,	0,	0x51,    0 },
	[ulpi1lpc_lpc_ad0]		 = { true,	0x02,	0x30,	6,	0x10,	4,	0x51,    1 },
	[ulpi1lpc_lpc_ad1]		 = { true,	0x02,	0x30,	12,	0x10,	8,	0x51,    2 },
	[ulpi1lpc_lpc_ad2]		 = { true,	0x02,	0x30,	18,	0x10,	12,	0x51,    3 },
	[ulpi1lpc_lpc_ad3]		 = { true,	0x02,	0x30,	24,	0x10,	16,	0x51,    4 },
	[ulpi1lpc_lpc_clkout]		 = { true,	0x02,	0x31,	0,	0x10,	20,	0x51,    5 },
	[ulpi1lpc_lpc_clkrun]		 = { true,	0x02,	0x31,	6,	0x10,	24,	0x51,    6 },
	[ulpi1lpc_lpc_frame_b]		 = { true,	0x02,	0x31,	12,	0x10,	28,	0x51,    7 },
	[ulpi1lpc_lpc_reset_b]		 = { true,	0x02,	0x31,	18,	0x11,	0,	0x51,    8 },
	[ulpi1lpc_lpc_serirq]		 = { true,	0x02,	0x31,	24,	0x11,	4,	0x51,    9 },
	[ulpi1lpc_lpc_smi_b]		 = { true,	0x02,	0x32,	0,	0x11,	8,	0x51,    10 },
	[ulpi1lpc_usb_ulpi_1_clk]	 = { true,	0x02,	0x32,	6,	0x11,	12,	0x51,    11 },
	[ulpi1lpc_usb_ulpi_1_data0]	 = { true,	0x02,	0x32,	12,	0x11,	16,	0x51,    12 },
	[ulpi1lpc_usb_ulpi_1_data1]	 = { true,	0x02,	0x32,	18,	0x11,	20,	0x51,    13 },
	[ulpi1lpc_usb_ulpi_1_data2]	 = { true,	0x02,	0x32,	24,	0x11,	24,	0x51,    14 },
	[ulpi1lpc_usb_ulpi_1_data3]	 = { true,	0x02,	0x33,	0,	0x11,	28,	0x51,    15 },
	[ulpi1lpc_usb_ulpi_1_data4]	 = { true,	0x02,	0x33,	6,	0x12,	0,	0x51,    16 },
	[ulpi1lpc_usb_ulpi_1_data5]	 = { true,	0x02,	0x33,	12,	0x12,	4,	0x51,    17 },
	[ulpi1lpc_usb_ulpi_1_data6]	 = { true,	0x02,	0x33,	18,	0x12,	8,	0x51,    18 },
	[ulpi1lpc_usb_ulpi_1_data7]	 = { true,	0x02,	0x33,	24,	0x12,	12,	0x51,    19 },
	[ulpi1lpc_usb_ulpi_1_dir]	 = { true,	0x02,	0x34,	0,	0x12,	16,	0x51,    20 },
	[ulpi1lpc_usb_ulpi_1_nxt]	 = { true,	0x02,	0x34,	6,	0x12,	20,	0x51,    21 },
	[ulpi1lpc_usb_ulpi_1_refclk]	 = { true,	0x02,	0x34,	12,	0x12,	24,	0x51,    22 },
	[ulpi1lpc_usb_ulpi_1_stp]	 = { true,	0x02,	0x34,	18,	0x12,	28,	0x51,    23 },
	[kbd_dkin0]			 = { true,	0x04,	0x30,	0,	0x10,	0,	0x51,    0 },
	[kbd_dkin1]			 = { true,	0x04,	0x30,	6,	0x10,	4,	0x51,    1 },
	[kbd_dkin2]			 = { true,	0x04,	0x30,	12,	0x10,	8,	0x51,    2 },
	[kbd_dkin3]			 = { true,	0x04,	0x30,	18,	0x10,	12,	0x51,    3 },
	[kbd_mkin0]			 = { true,	0x04,	0x30,	24,	0x10,	16,	0x51,    4 },
	[kbd_mkin1]			 = { true,	0x04,	0x31,	0,	0x10,	20,	0x51,    5 },
	[kbd_mkin2]			 = { true,	0x04,	0x31,	6,	0x10,	24,	0x51,    6 },
	[kbd_mkin3]			 = { true,	0x04,	0x31,	12,	0x10,	28,	0x51,    7 },
	[kbd_mkin4]			 = { true,	0x04,	0x31,	18,	0x11,	0,	0x51,    8 },
	[kbd_mkin5]			 = { true,	0x04,	0x31,	24,	0x11,	4,	0x51,    9 },
	[kbd_mkin6]			 = { true,	0x04,	0x32,	0,	0x11,	8,	0x51,    10 },
	[kbd_mkin7]			 = { true,	0x04,	0x32,	6,	0x11,	12,	0x51,    11 },
	[kbd_mkout0]			 = { true,	0x04,	0x32,	12,	0x11,	16,	0x51,    12 },
	[kbd_mkout1]			 = { true,	0x04,	0x32,	18,	0x11,	20,	0x51,    13 },
	[kbd_mkout2]			 = { true,	0x04,	0x32,	24,	0x11,	24,	0x51,    14 },
	[kbd_mkout3]			 = { true,	0x04,	0x33,	0,	0x11,	28,	0x51,    15 },
	[kbd_mkout4]			 = { true,	0x04,	0x33,	6,	0x12,	0,	0x51,    16 },
	[kbd_mkout5]			 = { true,	0x04,	0x33,	12,	0x12,	4,	0x51,    17 },
	[kbd_mkout6]			 = { true,	0x04,	0x33,	18,	0x12,	8,	0x51,    18 },
	[kbd_mkout7]			 = { true,	0x04,	0x33,	24,	0x12,	12,	0x51,    19 },
	[camerasb10]			 = { true,	0x05,	0x30,	0,	0x10,	0,	0x51,    0 },
	[camerasb4]			 = { true,	0x05,	0x30,	6,	0x10,	4,	0x51,    1 },
	[camerasb5]			 = { true,	0x05,	0x30,	12,	0x10,	8,	0x51,    2 },
	[camerasb6]			 = { true,	0x05,	0x30,	18,	0x10,	12,	0x51,    3 },
	[camerasb7]			 = { true,	0x05,	0x30,	24,	0x10,	16,	0x51,    4 },
	[camerasb8]			 = { true,	0x05,	0x31,	0,	0x10,	20,	0x51,    5 },
	[camerasb9]			 = { true,	0x05,	0x31,	6,	0x10,	24,	0x51,    6 },
	[i2c_4_scl]			 = { true,	0x05,	0x31,	12,	0x11,	0,	0x51,    7 },
	[i2c_4_sda]			 = { true,	0x05,	0x31,	18,	0x11,	4,	0x51,    8 },
	[i2c_5_scl]			 = { true,	0x05,	0x31,	24,	0x11,	8,	0x51,    9 },
	[i2c_5_sda]			 = { true,	0x05,	0x32,	0,	0x11,	12,	0x51,    10 },
	[intd_dsi_te1]			 = { true,	0x05,	0x32,	6,	0x11,	16,	0x51,    11 },
	[intd_dsi_te2]			 = { true,	0x05,	0x32,	12,	0x11,	20,	0x51,    12 },
	[stio_0_cd_b]			 = { true,	0x08,	0x30,	0,	0x10,	0,	0x51,    0 },
	[stio_0_clk]			 = { true,	0x08,	0x30,	6,	0x10,	4,	0xFF,    0xFF },
	[stio_0_cmd]			 = { true,	0x08,	0x30,	12,	0x10,	8,	0xFF,    0xFF },
	[stio_0_dat0]			 = { true,	0x08,	0x30,	18,	0x10,	12,	0xFF,    0xFF },
	[stio_0_dat1]			 = { true,	0x08,	0x30,	24,	0x10,	16,	0xFF,    0xFF },
	[stio_0_dat2]			 = { true,	0x08,	0x31,	0,	0x10,	20,	0xFF,    0xFF },
	[stio_0_dat3]			 = { true,	0x08,	0x31,	6,	0x10,	24,	0xFF,    0xFF },
	[stio_0_dat4]			 = { true,	0x08,	0x31,	12,	0x10,	28,	0xFF,    0xFF },
	[stio_0_dat5]			 = { true,	0x08,	0x31,	18,	0x11,	0,	0xFF,    0xFF },
	[stio_0_dat6]			 = { true,	0x08,	0x31,	24,	0x11,	4,	0xFF,    0xFF },
	[stio_0_dat7]			 = { true,	0x08,	0x32,	0,	0x11,	8,	0xFF,    0xFF },
	[stio_0_wp_b]			 = { true,	0x08,	0x32,	6,	0x11,	12,	0xFF,    0xFF },
	[camerasb0]			 = { true,	0x09,	0x30,	0,	0x10,	0,	0x52,    0 },
	[camerasb1]			 = { true,	0x09,	0x30,	6,	0x10,	4,	0x52,    1 },
	[camerasb2]			 = { true,	0x09,	0x30,	12,	0x10,	8,	0x52,    2 },
	[camerasb3]			 = { true,	0x09,	0x30,	18,	0x10,	12,	0x52,    3 },
	[ded_gpio10]			 = { true,	0x09,	0x30,	24,	0x10,	16,	0x52,    4 },
	[ded_gpio11]			 = { true,	0x09,	0x31,	0,	0x10,	20,	0x52,    5 },
	[ded_gpio12]			 = { true,	0x09,	0x31,	6,	0x10,	24,	0x52,    6 },
	[ded_gpio13]			 = { true,	0x09,	0x31,	12,	0x10,	28,	0x52,    7 },
	[ded_gpio14]			 = { true,	0x09,	0x31,	18,	0x11,	0,	0x52,    8 },
	[ded_gpio15]			 = { true,	0x09,	0x31,	24,	0x11,	4,	0x52,    9 },
	[ded_gpio16]			 = { true,	0x09,	0x32,	0,	0x11,	8,	0x52,    10 },
	[ded_gpio17]			 = { true,	0x09,	0x32,	6,	0x11,	12,	0x52,    11 },
	[ded_gpio18]			 = { true,	0x09,	0x32,	12,	0x11,	16,	0x52,    12 },
	[ded_gpio19]			 = { true,	0x09,	0x32,	18,	0x11,	20,	0x52,    13 },
	[ded_gpio20]			 = { true,	0x09,	0x32,	24,	0x11,	24,	0x52,    14 },
	[ded_gpio21]			 = { true,	0x09,	0x33,	0,	0x11,	28,	0x52,    15 },
	[ded_gpio22]			 = { true,	0x09,	0x33,	6,	0x12,	0,	0x52,    16 },
	[ded_gpio23]			 = { true,	0x09,	0x33,	12,	0x12,	4,	0x52,    17 },
	[ded_gpio24]			 = { true,	0x09,	0x33,	18,	0x12,	8,	0x52,    18 },
	[ded_gpio25]			 = { true,	0x09,	0x33,	24,	0x12,	12,	0x52,    19 },
	[ded_gpio26]			 = { true,	0x09,	0x34,	0,	0x12,	16,	0x52,    20 },
	[ded_gpio27]			 = { true,	0x09,	0x34,	6,	0x12,	20,	0x52,    21 },
	[ded_gpio28]			 = { true,	0x09,	0x34,	12,	0x12,	24,	0x52,    22 },
	[ded_gpio29]			 = { true,	0x09,	0x34,	18,	0x12,	28,	0x52,    23 },
	[ded_gpio30]			 = { true,	0x09,	0x34,	24,	0x13,	0,	0x52,    24 },
	[ded_gpio8]			 = { true,	0x09,	0x35,	0,	0x13,	4,	0x52,    25 },
	[ded_gpio9]			 = { true,	0x09,	0x35,	6,	0x13,	8,	0x52,    26 },
	[mpti_nidnt_clk]		 = { true,	0x09,	0x35,	12,	0x13,	12,	0x52,    27 },
	[mpti_nidnt_data0]		 = { true,	0x09,	0x35,	18,	0x13,	16,	0x52,    28 },
	[mpti_nidnt_data1]		 = { true,	0x09,	0x35,	24,	0x13,	20,	0x52,    29 },
	[mpti_nidnt_data2]		 = { true,	0x09,	0x36,	0,	0x13,	24,	0x52,    30 },
	[mpti_nidnt_data3]		 = { true,	0x09,	0x36,	6,	0x13,	28,	0x52,    31 },
	[stio_1_clk]			 = { true,	0x09,	0x36,	12,	0x14,	0,	0x53,    0 },
	[stio_1_cmd]			 = { true,	0x09,	0x36,	18,	0x14,	4,	0x53,    1 },
	[stio_1_dat0]			 = { true,	0x09,	0x36,	24,	0x14,	8,	0x53,    2 },
	[stio_1_dat1]			 = { true,	0x09,	0x37,	0,	0x14,	12,	0x53,    3 },
	[stio_1_dat2]			 = { true,	0x09,	0x37,	6,	0x14,	16,	0x53,    4 },
	[stio_1_dat3]			 = { true,	0x09,	0x37,	12,	0x14,	20,	0x53,    5 },
	[stio_2_clk]			 = { true,	0x09,	0x37,	18,	0x14,	24,	0x53,    6 },
	[stio_2_cmd]			 = { true,	0x09,	0x37,	24,	0x14,	28,	0x53,    7 },
	[stio_2_dat0]			 = { true,	0x09,	0x38,	0,	0x15,	0,	0x53,    8 },
	[stio_2_dat1]			 = { true,	0x09,	0x38,	6,	0x15,	4,	0x53,    9 },
	[stio_2_dat2]			 = { true,	0x09,	0x38,	12,	0x15,	8,	0x53,    10 },
	[stio_2_dat3]			 = { true,	0x09,	0x38,	18,	0x15,	12,	0x53,    11 },
	[coms_int0]			 = { true,	0x0B,	0x30,	0,	0x10,	0,	0x53,    0 },
	[coms_int1]			 = { true,	0x0B,	0x30,	6,	0x10,	4,	0x53,    1 },
	[coms_int2]			 = { true,	0x0B,	0x30,	12,	0x10,	8,	0x53,    2 },
	[coms_int3]			 = { true,	0x0B,	0x30,	18,	0x10,	12,	0x53,    3 },
	[ded_gpio4]			 = { true,	0x0B,	0x30,	24,	0x10,	16,	0x53,    4 },
	[ded_gpio5]			 = { true,	0x0B,	0x31,	0,	0x10,	20,	0x53,    5 },
	[ded_gpio6]			 = { true,	0x0B,	0x31,	6,	0x10,	24,	0x53,    6 },
	[ded_gpio7]			 = { true,	0x0B,	0x31,	12,	0x10,	28,	0x53,    7 },
	[i2s_0_clk]			 = { true,	0x0B,	0x31,	18,	0x11,	0,	0x53,    8 },
	[i2s_0_fs]			 = { true,	0x0B,	0x31,	24,	0x11,	4,	0x53,    9 },
	[i2s_0_rxd]			 = { true,	0x0B,	0x32,	0,	0x11,	8,	0x53,    10 },
	[i2s_0_txd]			 = { true,	0x0B,	0x32,	6,	0x11,	12,	0x53,    11 },
	[i2s_1_clk]			 = { true,	0x0B,	0x32,	12,	0x11,	16,	0x53,    12 },
	[i2s_1_fs]			 = { true,	0x0B,	0x32,	18,	0x11,	20,	0x53,    13 },
	[i2s_1_rxd]			 = { true,	0x0B,	0x32,	24,	0x11,	24,	0x53,    14 },
	[i2s_1_txd]			 = { true,	0x0B,	0x33,	0,	0x11,	28,	0x53,    15 },
	[mslim_1_bclk]			 = { true,	0x0B,	0x33,	6,	0x12,	0,	0x53,    16 },
	[mslim_1_bdat]			 = { true,	0x0B,	0x33,	12,	0x12,	4,	0x53,    17 },
	[resetout_b]			 = { true,	0x0B,	0x33,	18,	0x12,	8,	0x53,    18 },
	[spi_2_clk]			 = { true,	0x0B,	0x33,	24,	0x12,	12,	0x53,    19 },
	[spi_2_sdi]			 = { true,	0x0B,	0x34,	0,	0x12,	16,	0x53,    20 },
	[spi_2_sdo]			 = { true,	0x0B,	0x34,	6,	0x12,	20,	0x53,    21 },
	[spi_2_ss0]			 = { true,	0x0B,	0x34,	12,	0x12,	24,	0x53,    22 },
	[spi_2_ss1]			 = { true,	0x0B,	0x34,	18,	0x12,	28,	0x53,    23 },
	[spi_3_clk]			 = { true,	0x0B,	0x34,	24,	0x13,	0,	0x53,    24 },
	[spi_3_sdi]			 = { true,	0x0B,	0x35,	0,	0x13,	4,	0x53,    25 },
	[spi_3_sdo]			 = { true,	0x0B,	0x35,	6,	0x13,	8,	0x53,    26 },
	[spi_3_ss0]			 = { true,	0x0B,	0x35,	12,	0x13,	12,	0x53,    27 },
	[spi_3_ss1]			 = { true,	0x0B,	0x35,	18,	0x13,	16,	0x53,    28 },
	[uart_0_cts]			 = { true,	0x0B,	0x35,	24,	0x13,	20,	0x53,    29 },
	[uart_0_rts]			 = { true,	0x0B,	0x36,	0,	0x13,	24,	0x53,    30 },
	[uart_0_rx]			 = { true,	0x0B,	0x36,	6,	0x13,	28,	0x53,    31 },
	[uart_0_tx]			 = { true,	0x0B,	0x36,	12,	0x14,	0,	0x54,    0 },
	[uart_1_rx]			 = { true,	0x0B,	0x36,	18,	0x14,	4,	0x54,    1 },
	[uart_1_sd]			 = { true,	0x0B,	0x36,	24,	0x14,	8,	0x54,    2 },
	[uart_1_tx]			 = { true,	0x0B,	0x37,	0,	0x14,	12,	0x54,    3 },
	[uart_2_rx]			 = { true,	0x0B,	0x37,	6,	0x14,	16,	0x54,    4 },
	[uart_2_tx]			 = { true,	0x0B,	0x37,	12,	0x14,	20,	0x54,    5 },
	[aclkph]			 = { true,	0x10,	0x30,	0,	0x10,	0,	0x51,    0 },
	[dclkph]			 = { true,	0x10,	0x30,	6,	0x10,	4,	0x51,    1 },
	[dsiclkph]			 = { true,	0x10,	0x30,	12,	0x10,	8,	0x51,    2 },
	[ierr]				 = { true,	0x10,	0x30,	18,	0x10,	12,	0x51,    3 },
	[jtag_tckc]			 = { true,	0x10,	0x30,	24,	0x10,	16,	0x51,    4 },
	[jtag_tdic]			 = { true,	0x10,	0x31,	0,	0x10,	20,	0x51,    5 },
	[jtag_tdoc]			 = { true,	0x10,	0x31,	6,	0x10,	24,	0x51,    6 },
	[jtag_tmsc]			 = { true,	0x10,	0x31,	12,	0x10,	26,	0x51,    7 },
	[jtag_trst_b]			 = { true,	0x10,	0x31,	18,	0x11,	0,	0x51,    8 },
	[lclkph]			 = { true,	0x10,	0x31,	24,	0x11,	4,	0x51,    9 },
	[lfhclkph]			 = { true,	0x10,	0x32,	0,	0x11,	8,	0x51,    10 },
	[osc_clk_ctrl0]			 = { true,	0x10,	0x32,	6,	0x11,	12,	0x51,    11 },
	[osc_clk_ctrl1]			 = { true,	0x10,	0x32,	12,	0x11,	16,	0x51,    12 },
	[osc_clk_out0]			 = { true,	0x10,	0x32,	18,	0x11,	20,	0x51,    13 },
	[osc_clk_out1]			 = { true,	0x10,	0x32,	24,	0x11,	24,	0x51,    14 },
	[osc_clk_out2]			 = { true,	0x10,	0x33,	0,	0x11,	28,	0x51,    15 },
	[osc_clk_out3]			 = { true,	0x10,	0x33,	6,	0x12,	0,	0x51,    16 },
	[prochot_b]			 = { true,	0x10,	0x33,	12,	0x12,	4,	0x51,    17 },
	[thermtrip_b]			 = { true,	0x10,	0x33,	18,	0x12,	8,	0x51,    18 },
	[uclkph]			 = { true,	0x10,	0x33,	24,	0x12,	12,	0x51,    19 },
	[ded_gpio31]			 = { true,	0x12,	0x30,	0,	0x10,	0,	0x51,    0 },
	[ded_gpio32]			 = { true,	0x12,	0x30,	6,	0x10,	4,	0x51,    1 },
	[ded_gpio33]			 = { true,	0x12,	0x30,	12,	0x10,	8,	0x51,    2 },
	[hdmi_cec]			 = { true,	0x12,	0x30,	18,	0x10,	12,	0x51,    3 },
	[i2c_3_scl_hdmi_ddc]		 = { true,	0x12,	0x30,	24,	0x10,	16,	0x51,    4 },
	[i2c_3_sda_hdmi_ddc]		 = { true,	0x12,	0x31,	0,	0x10,	20,	0x51,    5 },
	[i2c_0_scl]			 = { true,	0x15,	0x30,	0,	0x10,	0,	0x51,    0 },
	[i2c_0_sda]			 = { true,	0x15,	0x30,	6,	0x10,	4,	0x51,    1 },
	[i2c_1_scl]			 = { true,	0x15,	0x30,	12,	0x10,	8,	0x51,    2 },
	[i2c_1_sda]			 = { true,	0x15,	0x30,	18,	0x10,	12,	0x51,    3 },
	[i2c_2_scl]			 = { true,	0x15,	0x30,	24,	0x10,	16,	0x51,    4 },
	[i2c_2_sda]			 = { true,	0x15,	0x31,	0,	0x10,	20,	0x51,    5 },
	[spi_1_clk]			 = { true,	0x15,	0x31,	6,	0x10,	24,	0x51,    6 },
	[spi_1_sdi]			 = { true,	0x15,	0x31,	12,	0x10,	28,	0x51,    7 },
	[spi_1_sdo]			 = { true,	0x15,	0x31,	18,	0x11,	0,	0x51,    8 },
	[spi_1_ss0]			 = { true,	0x15,	0x31,	24,	0x11,	4,	0x51,    9 },
	[spi_1_ss1]			 = { true,	0x15,	0x32,	0,	0x11,	8,	0x51,    10 },
	[spi_1_ss2]			 = { true,	0x15,	0x32,	6,	0x11,	12,	0x51,    11 },
	[spi_1_ss3]			 = { true,	0x15,	0x32,	12,	0x11,	16,	0x51,    12 },
	[spi_1_ss4]			 = { true,	0x15,	0x32,	18,	0x11,	20,	0x51,    13 }
};

static struct pin_mmio_flis_t tng_pin_mmio_flis_table[TNG_PIN_NUM] = {
	[tng_usb_ulpi_0_clk] = { writable, 0x0500 },
	[tng_usb_ulpi_0_data_0] = { writable, 0x0504 },
	[tng_usb_ulpi_0_data_1] = { writable, 0x0508 },
	[tng_usb_ulpi_0_data_2] = { writable, 0x050C },
	[tng_usb_ulpi_0_data_3] = { writable, 0x0510 },
	[tng_usb_ulpi_0_data_4] = { writable, 0x0514 },
	[tng_usb_ulpi_0_data_5] = { writable, 0x0518 },
	[tng_usb_ulpi_0_data_6] = { writable, 0x051C },
	[tng_usb_ulpi_0_data_7] = { writable, 0x0520 },
	[tng_usb_ulpi_0_dir] = { writable, 0x0524 },
	[tng_usb_ulpi_0_nxt] = { writable, 0x0528 },
	[tng_usb_ulpi_0_refclk] = { writable, 0x052C },
	[tng_usb_ulpi_0_stp] = { writable, 0x0530 },
	[tng_emmc_0_clk] = { writable, 0x0900 },
	[tng_emmc_0_cmd] = { writable, 0x0904 },
	[tng_emmc_0_d_0] = { writable, 0x0908 },
	[tng_emmc_0_d_1] = { writable, 0x090C },
	[tng_emmc_0_d_2] = { writable, 0x0910 },
	[tng_emmc_0_d_3] = { writable, 0x0914 },
	[tng_emmc_0_d_4] = { writable, 0x0918 },
	[tng_emmc_0_d_5] = { writable, 0x091C },
	[tng_emmc_0_d_6] = { writable, 0x0920 },
	[tng_emmc_0_d_7] = { writable, 0x0924 },
	[tng_emmc_0_rst_b] = { writable, 0x0928 },
	[tng_gp_emmc_1_clk] = { writable, 0x092C },
	[tng_gp_emmc_1_cmd] = { writable, 0x0930 },
	[tng_gp_emmc_1_d_0] = { writable, 0x0934 },
	[tng_gp_emmc_1_d_1] = { writable, 0x0938 },
	[tng_gp_emmc_1_d_2] = { writable, 0x093C },
	[tng_gp_emmc_1_d_3] = { writable, 0x0940 },
	[tng_gp_emmc_1_d_4] = { writable, 0x0944 },
	[tng_gp_emmc_1_d_5] = { writable, 0x0948 },
	[tng_gp_emmc_1_d_6] = { writable, 0x094C },
	[tng_gp_emmc_1_d_7] = { writable, 0x0950 },
	[tng_gp_emmc_1_rst_b] = { writable, 0x0954 },
	[tng_gp_28] = { writable, 0x0958 },
	[tng_gp_29] = { writable, 0x095C },
	[tng_gp_sdio_0_cd_b] = { writable, 0x0D00 },
	[tng_gp_sdio_0_clk] = { writable, 0x0D04 },
	[tng_gp_sdio_0_cmd] = { writable, 0x0D08 },
	[tng_gp_sdio_0_dat_0] = { writable, 0x0D0C },
	[tng_gp_sdio_0_dat_1] = { writable, 0x0D10 },
	[tng_gp_sdio_0_dat_2] = { writable, 0x0D14 },
	[tng_gp_sdio_0_dat_3] = { writable, 0x0D18 },
	[tng_gp_sdio_0_lvl_clk_fb] = { writable, 0x0D1C },
	[tng_gp_sdio_0_lvl_cmd_dir] = { writable, 0x0D20 },
	[tng_gp_sdio_0_lvl_dat_dir] = { writable, 0x0D24 },
	[tng_gp_sdio_0_lvl_sel] = { writable, 0x0D28 },
	[tng_gp_sdio_0_powerdown_b] = { writable, 0x0D2C },
	[tng_gp_sdio_0_wp] = { writable, 0x0D30 },
	[tng_gp_sdio_1_clk] = { writable, 0x0D34 },
	[tng_gp_sdio_1_cmd] = { writable, 0x0D38 },
	[tng_gp_sdio_1_dat_0] = { writable, 0x0D3C },
	[tng_gp_sdio_1_dat_1] = { writable, 0x0D40 },
	[tng_gp_sdio_1_dat_2] = { writable, 0x0D44 },
	[tng_gp_sdio_1_dat_3] = { writable, 0x0D48 },
	[tng_gp_sdio_1_powerdown_b] = { writable, 0x0D4C },
	[tng_mhsi_acdata] = { writable, 0x1100 },
	[tng_mhsi_acflag] = { writable, 0x1104 },
	[tng_mhsi_acready] = { writable, 0x1108 },
	[tng_mhsi_acwake] = { writable, 0x110C },
	[tng_mhsi_cadata] = { writable, 0x1110 },
	[tng_mhsi_caflag] = { writable, 0x1114 },
	[tng_mhsi_caready] = { writable, 0x1118 },
	[tng_mhsi_cawake] = { writable, 0x111C },
	[tng_gp_mslim_0_bclk] = { writable, 0x1500 },
	[tng_gp_mslim_0_bdat] = { writable, 0x1504 },
	[tng_gp_ssp_0_clk] = { writable, 0x1508 },
	[tng_gp_ssp_0_fs] = { writable, 0x150C },
	[tng_gp_ssp_0_rxd] = { writable, 0x1510 },
	[tng_gp_ssp_0_txd] = { writable, 0x1514 },
	[tng_gp_ssp_1_clk] = { writable, 0x1518 },
	[tng_gp_ssp_1_fs] = { writable, 0x151C },
	[tng_gp_ssp_1_rxd] = { writable, 0x1520 },
	[tng_gp_ssp_1_txd] = { writable, 0x1524 },
	[tng_gp_ssp_2_clk] = { writable, 0x1528 },
	[tng_gp_ssp_2_fs] = { writable, 0x152C },
	[tng_gp_ssp_2_rxd] = { writable, 0x1530 },
	[tng_gp_ssp_2_txd] = { writable, 0x1534 },
	[tng_gp_ssp_3_clk] = { writable, 0x1900 },
	[tng_gp_ssp_3_fs] = { writable, 0x1904 },
	[tng_gp_ssp_3_rxd] = { writable, 0x1908 },
	[tng_gp_ssp_3_txd] = { writable, 0x190C },
	[tng_gp_ssp_4_clk] = { writable, 0x1910 },
	[tng_gp_ssp_4_fs_0] = { writable, 0x1914 },
	[tng_gp_ssp_4_fs_1] = { writable, 0x1918 },
	[tng_gp_ssp_4_fs_2] = { writable, 0x191C },
	[tng_gp_ssp_4_fs_3] = { writable, 0x1920 },
	[tng_gp_ssp_4_rxd] = { writable, 0x1924 },
	[tng_gp_ssp_4_txd] = { writable, 0x1928 },
	[tng_gp_ssp_5_clk] = { writable, 0x192C },
	[tng_gp_ssp_5_fs_0] = { writable, 0x1930 },
	[tng_gp_ssp_5_fs_1] = { writable, 0x1934 },
	[tng_gp_ssp_5_fs_2] = { writable, 0x1938 },
	[tng_gp_ssp_5_fs_3] = { writable, 0x193C },
	[tng_gp_ssp_5_rxd] = { writable, 0x1940 },
	[tng_gp_ssp_5_txd] = { writable, 0x1944 },
	[tng_gp_ssp_6_clk] = { writable, 0x1948 },
	[tng_gp_ssp_6_fs] = { writable, 0x194C },
	[tng_gp_ssp_6_rxd] = { writable, 0x1950 },
	[tng_gp_ssp_6_txd] = { writable, 0x1954 },
	[tng_gp_i2c_1_scl] = { writable, 0x1D00 },
	[tng_gp_i2c_1_sda] = { writable, 0x1D04 },
	[tng_gp_i2c_2_scl] = { writable, 0x1D08 },
	[tng_gp_i2c_2_sda] = { writable, 0x1D0C },
	[tng_gp_i2c_3_scl] = { writable, 0x1D10 },
	[tng_gp_i2c_3_sda] = { writable, 0x1D14 },
	[tng_gp_i2c_4_scl] = { writable, 0x1D18 },
	[tng_gp_i2c_4_sda] = { writable, 0x1D1C },
	[tng_gp_i2c_5_scl] = { writable, 0x1D20 },
	[tng_gp_i2c_5_sda] = { writable, 0x1D24 },
	[tng_gp_i2c_6_scl] = { writable, 0x1D28 },
	[tng_gp_i2c_6_sda] = { writable, 0x1D2C },
	[tng_gp_i2c_7_scl] = { writable, 0x1D30 },
	[tng_gp_i2c_7_sda] = { writable, 0x1D34 },
	[tng_gp_uart_0_cts] = { writable, 0x2100 },
	[tng_gp_uart_0_rts] = { writable, 0x2104 },
	[tng_gp_uart_0_rx] = { writable, 0x2108 },
	[tng_gp_uart_0_tx] = { writable, 0x210C },
	[tng_gp_uart_1_cts] = { writable, 0x2110 },
	[tng_gp_uart_1_rts] = { writable, 0x2114 },
	[tng_gp_uart_1_rx] = { writable, 0x2118 },
	[tng_gp_uart_1_tx] = { writable, 0x211C },
	[tng_gp_uart_2_cts] = { writable, 0x2120 },
	[tng_gp_uart_2_rts] = { writable, 0x2124 },
	[tng_gp_uart_2_rx] = { writable, 0x2128 },
	[tng_gp_uart_2_tx] = { writable, 0x212C },
	[tng_gp_13] = { writable, 0x2500 },
	[tng_gp_14] = { writable, 0x2504 },
	[tng_gp_15] = { writable, 0x2508 },
	[tng_gp_16] = { writable, 0x250C },
	[tng_gp_17] = { writable, 0x2510 },
	[tng_gp_18] = { writable, 0x2514 },
	[tng_gp_19] = { writable, 0x2518 },
	[tng_gp_20] = { writable, 0x251C },
	[tng_gp_21] = { writable, 0x2520 },
	[tng_gp_22] = { writable, 0x2524 },
	[tng_gp_23] = { writable, 0x2528 },
	[tng_gp_24] = { writable, 0x252C },
	[tng_gp_25] = { writable, 0x2530 },
	[tng_gp_fast_int_0] = { writable, 0x2534 },
	[tng_gp_fast_int_1] = { writable, 0x2538 },
	[tng_gp_fast_int_2] = { writable, 0x253C },
	[tng_gp_fast_int_3] = { writable, 0x2540 },
	[tng_gp_pwm_0] = { writable, 0x2544 },
	[tng_gp_pwm_1] = { writable, 0x2548 },
	[tng_gp_camerasb_0] = { writable, 0x2900 },
	[tng_gp_camerasb_1] = { writable, 0x2904 },
	[tng_gp_camerasb_2] = { writable, 0x2908 },
	[tng_gp_camerasb_3] = { writable, 0x290C },
	[tng_gp_camerasb_4] = { writable, 0x2910 },
	[tng_gp_camerasb_5] = { writable, 0x2914 },
	[tng_gp_camerasb_6] = { writable, 0x2918 },
	[tng_gp_camerasb_7] = { writable, 0x291C },
	[tng_gp_camerasb_8] = { writable, 0x2920 },
	[tng_gp_camerasb_9] = { writable, 0x2924 },
	[tng_gp_camerasb_10] = { writable, 0x2928 },
	[tng_gp_camerasb_11] = { writable, 0x292C },
	[tng_gp_clkph_0] = { writable, 0x2D00 },
	[tng_gp_clkph_1] = { writable, 0x2D04 },
	[tng_gp_clkph_2] = { writable, 0x2D08 },
	[tng_gp_clkph_3] = { writable, 0x2D0C },
	[tng_gp_clkph_4] = { writable, 0x2D10 },
	[tng_gp_clkph_5] = { writable, 0x2D14 },
	[tng_gp_hdmi_hpd] = { writable, 0x2D18 },
	[tng_gp_intd_dsi_te1] = { writable, 0x2D1C },
	[tng_gp_intd_dsi_te2] = { writable, 0x2D20 },
	[tng_osc_clk_ctrl_0] = { writable, 0x2D24 },
	[tng_osc_clk_ctrl_1] = { writable, 0x2D28 },
	[tng_osc_clk_out_0] = { writable, 0x2D2C },
	[tng_osc_clk_out_1] = { writable, 0x2D30 },
	[tng_osc_clk_out_2] = { writable, 0x2D34 },
	[tng_osc_clk_out_3] = { writable, 0x2D38 },
	[tng_osc_clk_out_4] = { writable, 0x2D3C },
	[tng_resetout_b] = { writable, 0x2D40 },
	[tng_xxpmode] = { writable, 0x2D44 },
	[tng_xxprdy] = { writable, 0x2D48 },
	[tng_xxpreq_b] = { writable, 0x2D4C },
	[tng_gp_26] = { writable, 0x2D50 },
	[tng_gp_27] = { writable, 0x2D54 },
	[tng_i2c_0_scl] = { writable, 0x3100 },
	[tng_i2c_0_sda] = { writable, 0x3104 },
	[tng_ierr_b] = { writable, 0x3108 },
	[tng_jtag_tckc] = { writable, 0x310C },
	[tng_jtag_tdic] = { writable, 0x3110 },
	[tng_jtag_tdoc] = { writable, 0x3114 },
	[tng_jtag_tmsc] = { writable, 0x3118 },
	[tng_jtag_trst_b] = { writable, 0x311C },
	[tng_prochot_b] = { writable, 0x3120 },
	[tng_rtc_clk] = { writable, 0x3124 },
	[tng_svid_vclk] = { writable, 0x3128 },
	[tng_svid_vdio] = { writable, 0x3130 },
	[tng_thermtrip_b] = { writable, 0x3134 },
	[tng_standby] = { writable, 0x3138 },
	[tng_gp_kbd_dkin_0] = { writable, 0x3500 },
	[tng_gp_kbd_dkin_1] = { writable, 0x3504 },
	[tng_gp_kbd_dkin_2] = { writable, 0x3508 },
	[tng_gp_kbd_dkin_3] = { writable, 0x350C },
	[tng_gp_kbd_mkin_0] = { writable, 0x3510 },
	[tng_gp_kbd_mkin_1] = { writable, 0x3514 },
	[tng_gp_kbd_mkin_2] = { writable, 0x3518 },
	[tng_gp_kbd_mkin_3] = { writable, 0x351C },
	[tng_gp_kbd_mkin_4] = { writable, 0x3520 },
	[tng_gp_kbd_mkin_5] = { writable, 0x3524 },
	[tng_gp_kbd_mkin_6] = { writable, 0x3528 },
	[tng_gp_kbd_mkin_7] = { writable, 0x352C },
	[tng_gp_kbd_mkout_0] = { writable, 0x3530 },
	[tng_gp_kbd_mkout_1] = { writable, 0x3534 },
	[tng_gp_kbd_mkout_2] = { writable, 0x3538 },
	[tng_gp_kbd_mkout_3] = { writable, 0x353C },
	[tng_gp_kbd_mkout_4] = { writable, 0x3540 },
	[tng_gp_kbd_mkout_5] = { writable, 0x3544 },
	[tng_gp_kbd_mkout_6] = { writable, 0x3548 },
	[tng_gp_kbd_mkout_7] = { writable, 0x354C },
	[tng_gp_0] = { writable, 0x3900 },
	[tng_gp_1] = { writable, 0x3904 },
	[tng_gp_2] = { writable, 0x3908 },
	[tng_gp_3] = { writable, 0x390C },
	[tng_gp_4] = { writable, 0x3910 },
	[tng_gp_5] = { writable, 0x3914 },
	[tng_gp_6] = { writable, 0x3918 },
	[tng_gp_7] = { writable, 0x391C },
	[tng_gp_8] = { writable, 0x3920 },
	[tng_gp_9] = { writable, 0x3924 },
	[tng_gp_10] = { writable, 0x3928 },
	[tng_gp_11] = { writable, 0x392C },
	[tng_gp_12] = { writable, 0x3930 },
	[tng_gp_mpti_clk] = { writable, 0x3D00 },
	[tng_gp_mpti_data_0] = { writable, 0x3D04 },
	[tng_gp_mpti_data_1] = { writable, 0x3D08 },
	[tng_gp_mpti_data_2] = { writable, 0x3D0C },
	[tng_gp_mpti_data_3] = { writable, 0x3D10 },
};

static struct pin_mmio_flis_t ann_pin_mmio_flis_table[ANN_PIN_TABLE_SIZE] = {
	/* gpioclk */
	[ann_gp_clkph_0] = { writable, 0x2D00 },
	[ann_gp_clkph_1] = { writable, 0x2D04 },
	[ann_gp_clkph_2] = { writable, 0x2D08 },
	[ann_gp_clkph_3] = { writable, 0x2D0C },
	[ann_gp_clkph_4] = { writable, 0x2D10 },
	[ann_gp_clkph_5] = { writable, 0x2D14 },
	[ann_gp_clkph_6] = { writable, 0x2D18 },
	[ann_osc_clk_ctrl_0] = { writable, 0x2D1C },
	[ann_osc_clk_ctrl_1] = { writable, 0x2D20 },
	[ann_osc_clk_out_0] = { writable, 0x2D24 },
	[ann_osc_clk_out_1] = { writable, 0x2D28 },
	[ann_osc_clk_out_2] = { writable, 0x2D2C },
	[ann_osc_clk_out_3] = { writable, 0x2D30 },
	[ann_osc_clk_out_4] = { writable, 0x2D34 },

	/* gpiocsb */
	[ann_gp_camerasb_0] = { writable, 0x2900 },
	[ann_gp_camerasb_1] = { writable, 0x2904 },
	[ann_gp_camerasb_2] = { writable, 0x2908 },
	[ann_gp_camerasb_3] = { writable, 0x290C },
	[ann_gp_camerasb_4] = { writable, 0x2910 },
	[ann_gp_camerasb_5] = { writable, 0x2914 },
	[ann_gp_camerasb_6] = { writable, 0x2918 },
	[ann_gp_camerasb_7] = { writable, 0x291C },
	[ann_gp_camerasb_8] = { writable, 0x2920 },
	[ann_gp_camerasb_9] = { writable, 0x2924 },
	[ann_gp_camerasb_10] = { writable, 0x2928 },
	[ann_gp_camerasb_11] = { writable, 0x292C },
	[ann_gp_hdmi_hpd] = { writable, 0x2930 },
	[ann_gp_intd_dsi_te1] = { writable, 0x2934 },
	[ann_gp_intd_dsi_te2] = { writable, 0x2938 },

	/* gpioemmc */
	[ann_emmc_0_clk] = { writable, 0x900 },
	[ann_emmc_0_cmd] = { writable, 0x904 },
	[ann_emmc_0_d_0] = { writable, 0x908 },
	[ann_emmc_0_d_1] = { writable, 0x90C },
	[ann_emmc_0_d_2] = { writable, 0x910 },
	[ann_emmc_0_d_3] = { writable, 0x914 },
	[ann_emmc_0_d_4] = { writable, 0x918 },
	[ann_emmc_0_d_5] = { writable, 0x91C },
	[ann_emmc_0_d_6] = { writable, 0x920 },
	[ann_emmc_0_d_7] = { writable, 0x924 },
	[ann_emmc_0_rst_b] = { writable, 0x928 },
	[ann_emmc_0_rclk] = { writable, 0x92C },

	/* gpiogpio */
	[ann_gp_12] = { writable, 0x2500 },
	[ann_gp_13] = { writable, 0x2504 },
	[ann_gp_14] = { writable, 0x2508 },
	[ann_gp_15] = { writable, 0x250C },
	[ann_gp_16] = { writable, 0x2510 },
	[ann_gp_17] = { writable, 0x2514 },
	[ann_gp_18] = { writable, 0x2518 },
	[ann_gp_19] = { writable, 0x251C },
	[ann_gp_20] = { writable, 0x2520 },
	[ann_gp_21] = { writable, 0x2524 },
	[ann_gp_22] = { writable, 0x2528 },
	[ann_gp_23] = { writable, 0x252C },
	[ann_gp_24] = { writable, 0x2530 },
	[ann_gp_25] = { writable, 0x2534 },
	[ann_gp_26] = { writable, 0x2538 },
	[ann_gp_27] = { writable, 0x253C },
	[ann_gp_28] = { writable, 0x2540 },
	[ann_gp_29] = { writable, 0x2544 },
	[ann_gp_30] = { writable, 0x2548 },
	[ann_gp_31] = { writable, 0x254C },

	/* gpiohsi */
	[ann_mhsi_acdata] = { writable, 0x1100 },
	[ann_mhsi_acflag] = { writable, 0x1104 },
	[ann_mhsi_acready] = { writable, 0x1108 },
	[ann_mhsi_acwake] = { writable, 0x110C },
	[ann_mhsi_cadata] = { writable, 0x1110 },
	[ann_mhsi_caflag] = { writable, 0x1114 },
	[ann_mhsi_caready] = { writable, 0x1118 },
	[ann_mhsi_cawake] = { writable, 0x111C },

	/* gpioi2c */
	[ann_i2c_0_scl] = { writable, 0x1D00 },
	[ann_i2c_0_sda] = { writable, 0x1D04 },
	[ann_gp_i2c_1_scl] = { writable, 0x1D08 },
	[ann_gp_i2c_1_sda] = { writable, 0x1D0C },
	[ann_gp_i2c_2_scl] = { writable, 0x1D10 },
	[ann_gp_i2c_2_sda] = { writable, 0x1D14 },
	[ann_gp_i2c_3_scl] = { writable, 0x1D18 },
	[ann_gp_i2c_3_sda] = { writable, 0x1D1C },
	[ann_gp_i2c_4_scl] = { writable, 0x1D20 },
	[ann_gp_i2c_4_sda] = { writable, 0x1D24 },
	[ann_gp_i2c_5_scl] = { writable, 0x1D28 },
	[ann_gp_i2c_5_sda] = { writable, 0x1D2C },
	[ann_gp_i2c_6_scl] = { writable, 0x1D30 },
	[ann_gp_i2c_6_sda] = { writable, 0x1D34 },
	[ann_gp_i2c_7_scl] = { writable, 0x1D38 },
	[ann_gp_i2c_7_sda] = { writable, 0x1D3C },
	[ann_i2c_8_scl] = { writable, 0x1D40 },
	[ann_i2c_8_sda] = { writable, 0x1D44 },
	[ann_i2c_9_scl] = { writable, 0x1D48 },
	[ann_i2c_9_sda] = { writable, 0x1D4C },

	/* gpiokbd */
	[ann_gp_kbd_dkin_0] = { writable, 0x3500 },
	[ann_gp_kbd_dkin_1] = { writable, 0x3504 },
	[ann_gp_kbd_dkin_2] = { writable, 0x3508 },
	[ann_gp_kbd_dkin_3] = { writable, 0x350C },
	[ann_gp_kbd_mkin_0] = { writable, 0x3510 },
	[ann_gp_kbd_mkin_1] = { writable, 0x3514 },
	[ann_gp_kbd_mkin_2] = { writable, 0x3518 },
	[ann_gp_kbd_mkin_3] = { writable, 0x351C },
	[ann_gp_kbd_mkin_4] = { writable, 0x3520 },
	[ann_gp_kbd_mkin_5] = { writable, 0x3524 },
	[ann_gp_kbd_mkin_6] = { writable, 0x3528 },
	[ann_gp_kbd_mkin_7] = { writable, 0x352C },
	[ann_gp_kbd_mkout_0] = { writable, 0x3530 },
	[ann_gp_kbd_mkout_1] = { writable, 0x3534 },
	[ann_gp_kbd_mkout_2] = { writable, 0x3538 },
	[ann_gp_kbd_mkout_3] = { writable, 0x353C },
	[ann_gp_kbd_mkout_4] = { writable, 0x3540 },
	[ann_gp_kbd_mkout_5] = { writable, 0x3544 },
	[ann_gp_kbd_mkout_6] = { writable, 0x3548 },
	[ann_gp_kbd_mkout_7] = { writable, 0x354C },

	/* gpiopmic */
	[ann_prochot_b] = { writable, 0x3100 },
	[ann_resetout_b] = { writable, 0x3104 },
	[ann_rtc_clk] = { writable, 0x3108 },
	[ann_standby] = { writable, 0x310C },
	[ann_svid_alert_b] = { writable, 0x3110 },
	[ann_svid_vclk] = { writable, 0x3114 },
	[ann_svid_vdio] = { writable, 0x3118 },
	[ann_thermtrip_b] = { writable, 0x311C },
	[ann_xxpmode] = { writable, 0x3120 },
	[ann_xxprdy] = { writable, 0x3124 },
	[ann_xxpreq_b] = { writable, 0x3128 },
	[ann_gp_fast_int_0] = { writable, 0x312C },
	[ann_gp_fast_int_1] = { writable, 0x3130 },
	[ann_gp_fast_int_2] = { writable, 0x3134 },
	[ann_gp_fast_int_3] = { writable, 0x3138 },

	/* gpiopti */
	[ann_gp_mpti_clk] = { writable, 0x3D00 },
	[ann_gp_mpti_data_0] = { writable, 0x3D04 },
	[ann_gp_mpti_data_1] = { writable, 0x3D08 },
	[ann_gp_mpti_data_2] = { writable, 0x3D0C },
	[ann_gp_mpti_data_3] = { writable, 0x3D10 },
	[ann_gp_0] = { writable, 0x3D14 },
	[ann_gp_1] = { writable, 0x3D18 },
	[ann_gp_2] = { writable, 0x3D1C },
	[ann_gp_3] = { writable, 0x3D20 },
	[ann_gp_4] = { writable, 0x3D24 },
	[ann_gp_5] = { writable, 0x3D28 },
	[ann_gp_6] = { writable, 0x3D2C },
	[ann_gp_7] = { writable, 0x3D30 },
	[ann_gp_8] = { writable, 0x3D34 },
	[ann_gp_9] = { writable, 0x3D38 },
	[ann_gp_10] = { writable, 0x3D3C },
	[ann_gp_11] = { writable, 0x3D40 },
	[ann_jtag_tckc] = { writable, 0x3D44 },
	[ann_jtag_tdic] = { writable, 0x3D48 },
	[ann_jtag_tdoc] = { writable, 0x3D4C },
	[ann_jtag_tmsc] = { writable, 0x3D50 },
	[ann_jtag_trst_b] = { writable, 0x3D54 },

	/* gpiosdio */
	[ann_gp_sdio_0_cd_b] = { writable, 0xD00 },
	[ann_gp_sdio_0_clk] = { writable, 0xD04 },
	[ann_gp_sdio_0_cmd] = { writable, 0xD08 },
	[ann_gp_sdio_0_dat_0] = { writable, 0xD0C },
	[ann_gp_sdio_0_dat_1] = { writable, 0xD10 },
	[ann_gp_sdio_0_dat_2] = { writable, 0xD14 },
	[ann_gp_sdio_0_dat_3] = { writable, 0xD18 },
	[ann_gp_sdio_0_lvl_clk_fb] = { writable, 0xD1C },
	[ann_gp_sdio_0_lvl_cmd_dir] = { writable, 0xD20 },
	[ann_gp_sdio_0_lvl_dat_dir] = { writable, 0xD24 },
	[ann_gp_sdio_0_lvl_sel] = { writable, 0xD28 },
	[ann_gp_sdio_0_powerdown_b] = { writable, 0xD2C },
	[ann_gp_sdio_0_wp] = { writable, 0xD30 },
	[ann_gp_sdio_1_clk] = { writable, 0xD34 },
	[ann_gp_sdio_1_cmd] = { writable, 0xD38 },
	[ann_gp_sdio_1_dat_0] = { writable, 0xD3C },
	[ann_gp_sdio_1_dat_1] = { writable, 0xD40 },
	[ann_gp_sdio_1_dat_2] = { writable, 0xD44 },
	[ann_gp_sdio_1_dat_3] = { writable, 0xD48 },
	[ann_gp_sdio_1_powerdown_b] = { writable, 0xD4C },

	/* gpiossp */
	[ann_gp_ssp_3_clk] = { writable, 0x1900 },
	[ann_gp_ssp_3_fs] = { writable, 0x1904 },
	[ann_gp_ssp_3_rxd] = { writable, 0x1908 },
	[ann_gp_ssp_3_txd] = { writable, 0x190C },
	[ann_gp_ssp_4_clk] = { writable, 0x1910 },
	[ann_gp_ssp_4_fs_0] = { writable, 0x1914 },
	[ann_gp_ssp_4_fs_1] = { writable, 0x1918 },
	[ann_gp_ssp_4_fs_2] = { writable, 0x191C },
	[ann_gp_ssp_4_fs_3] = { writable, 0x1920 },
	[ann_gp_ssp_4_rxd] = { writable, 0x1924 },
	[ann_gp_ssp_4_txd] = { writable, 0x1928 },
	[ann_gp_ssp_5_clk] = { writable, 0x192C },
	[ann_gp_ssp_5_fs_0] = { writable, 0x1930 },
	[ann_gp_ssp_5_fs_1] = { writable, 0x1934 },
	[ann_gp_ssp_5_fs_2] = { writable, 0x1938 },
	[ann_gp_ssp_5_fs_3] = { writable, 0x193C },
	[ann_gp_ssp_5_rxd] = { writable, 0x1940 },
	[ann_gp_ssp_5_txd] = { writable, 0x1944 },
	[ann_gp_ssp_6_clk] = { writable, 0x1948 },
	[ann_gp_ssp_6_fs] = { writable, 0x194C },
	[ann_gp_ssp_6_rxd] = { writable, 0x1950 },
	[ann_gp_ssp_6_txd] = { writable, 0x1954 },

	/* gpiosspa */
	[ann_gp_mslim_0_bclk] = { writable, 0x1500 },
	[ann_gp_mslim_0_bdat] = { writable, 0x1504 },
	[ann_gp_ssp_0_clk] = { writable, 0x1508 },
	[ann_gp_ssp_0_fs] = { writable, 0x150C },
	[ann_gp_ssp_0_rxd] = { writable, 0x1510 },
	[ann_gp_ssp_0_txd] = { writable, 0x1514 },
	[ann_gp_ssp_1_clk] = { writable, 0x1518 },
	[ann_gp_ssp_1_fs] = { writable, 0x151C },
	[ann_gp_ssp_1_rxd] = { writable, 0x1520 },
	[ann_gp_ssp_1_txd] = { writable, 0x1524 },
	[ann_gp_ssp_2_clk] = { writable, 0x1528 },
	[ann_gp_ssp_2_fs] = { writable, 0x152C },
	[ann_gp_ssp_2_rxd] = { writable, 0x1530 },
	[ann_gp_ssp_2_txd] = { writable, 0x1534 },

	/* gpiouart */
	[ann_gp_uart_0_cts] = { writable, 0x2100 },
	[ann_gp_uart_0_rts] = { writable, 0x2104 },
	[ann_gp_uart_0_rx] = { writable, 0x2108 },
	[ann_gp_uart_0_tx] = { writable, 0x210C },
	[ann_gp_uart_1_cts] = { writable, 0x2110 },
	[ann_gp_uart_1_rts] = { writable, 0x2114 },
	[ann_gp_uart_1_rx] = { writable, 0x2118 },
	[ann_gp_uart_1_tx] = { writable, 0x211C },
	[ann_gp_uart_2_cts] = { writable, 0x2120 },
	[ann_gp_uart_2_rts] = { writable, 0x2124 },
	[ann_gp_uart_2_rx] = { writable, 0x2128 },
	[ann_gp_uart_2_tx] = { writable, 0x212C },
	[ann_gp_32] = { writable, 0x2130 },
	[ann_gp_33] = { writable, 0x2134 },
	[ann_gp_34] = { writable, 0x2138 },
	[ann_gp_35] = { writable, 0x213C },
	[ann_gp_36] = { writable, 0x2140 },
	[ann_gp_37] = { writable, 0x2144 },
	[ann_gp_38] = { writable, 0x2148 },
	[ann_gp_39] = { writable, 0x214C },
	[ann_gp_40] = { writable, 0x2150 },
	[ann_gp_pwm_0] = { writable, 0x2154 },
	[ann_gp_pwm_1] = { writable, 0x2158 },

	/* gpioulpi */
	[ann_gp_ulpi_0_clk] = { writable, 0x500 },
	[ann_gp_ulpi_0_data_0] = { writable, 0x504 },
	[ann_gp_ulpi_0_data_1] = { writable, 0x508 },
	[ann_gp_ulpi_0_data_2] = { writable, 0x50C },
	[ann_gp_ulpi_0_data_3] = { writable, 0x510 },
	[ann_gp_ulpi_0_data_4] = { writable, 0x514 },
	[ann_gp_ulpi_0_data_5] = { writable, 0x518 },
	[ann_gp_ulpi_0_data_6] = { writable, 0x51C },
	[ann_gp_ulpi_0_data_7] = { writable, 0x520 },
	[ann_gp_ulpi_0_dir] = { writable, 0x524 },
	[ann_gp_ulpi_0_nxt] = { writable, 0x528 },
	[ann_gp_ulpi_0_refclk] = { writable, 0x52C },
	[ann_gp_ulpi_0_stp] = { writable, 0x530 },
};

static int __init intel_scu_flis_init(void)
{
	int ret;
	struct platform_device *pdev = NULL;
	static struct intel_scu_flis_platform_data flis_pdata;

	if (INTEL_MID_BOARD(1, PHONE, CLVTP) ||
		INTEL_MID_BOARD(1, TABLET, CLVT)) {
		flis_pdata.pin_t = ctp_pin_table;
		flis_pdata.pin_num = CTP_PIN_NUM;
		flis_pdata.mmio_flis_t = NULL;
		flis_pdata.shim_access = true;
	} else if (INTEL_MID_BOARD(1, PHONE, MRFL)) {
		flis_pdata.pin_t = NULL;
		flis_pdata.pin_num = TNG_PIN_NUM;
		flis_pdata.flis_base = 0xFF0C0000;
		flis_pdata.flis_len = 0x8000;
		flis_pdata.mmio_flis_t = tng_pin_mmio_flis_table;
	} else if (INTEL_MID_BOARD(1, PHONE, MOFD) ||
		INTEL_MID_BOARD(1, TABLET, MOFD)) {
		flis_pdata.pin_t = NULL;
		flis_pdata.pin_num = ANN_PIN_TABLE_SIZE;
		flis_pdata.flis_base = 0xFF0C0000;
		flis_pdata.flis_len = 0x8000;
		flis_pdata.mmio_flis_t = ann_pin_mmio_flis_table;
	} else {
		/* Runtime flis config is supported on CLV & TNG only */
		return -EINVAL;
	}

	pdev = platform_device_alloc(FLIS_DEVICE_NAME, -1);
	if (!pdev) {
		pr_err("out of memory for platform dev %s\n", FLIS_DEVICE_NAME);
		ret = -EINVAL;
		goto out;
	}

	pdev->dev.platform_data = &flis_pdata;

	ret = platform_device_add(pdev);
	if (ret) {
		pr_err("failed to add flis platform device\n");
		platform_device_put(pdev);
		goto out;
	}

	pr_info("intel_scu_flis platform device created\n");
out:
	return ret;
}
fs_initcall(intel_scu_flis_init);

