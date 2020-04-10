/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-05     zylx         The first version for STM32F4xx
 */

#ifndef __SDRAM_PORT_H__
#define __SDRAM_PORT_H__


//user add
#define	EXT_SDRAM_ADDR	0XD0000018
/* LCD 显存, 图层 1, 分配 4M 字节 */
#define SDRAM_LCD_BUF1 EXT_SDRAM_ADDR
/* LCD 显存, 图层 2, 分配 4M 字节 */
#define SDRAM_LCD_BUF2 (EXT_SDRAM_ADDR + 4 * 1024 * 1024)
/* 仅 SDRAM 驱动里面的测试代码调用了 */
#define SDRAM_APP_SIZE ( 8 * 1024 * 1024)

/*emwin动态内存使用,除了显存使用的8MB,后面8MB留给系统动态内存使用*/
#define SDRAM_APP_BUF (EXT_SDRAM_ADDR + 8 * 1024 * 1024)


/* parameters for sdram peripheral */
/* Bank1 or Bank2 */
#define SDRAM_TARGET_BANK               2//1
/* stm32f4 Bank1:0XC0000000  Bank2:0XD0000000 */
#define SDRAM_BANK_ADDR                 ((uint32_t)0XD0000000)//((uint32_t)0XC0000000)
/* data width: 8, 16, 32 */
#define SDRAM_DATA_WIDTH                32
/* column bit numbers: 8, 9, 10, 11 */
#define SDRAM_COLUMN_BITS               8
/* row bit numbers: 11, 12, 13 */
#define SDRAM_ROW_BITS                  12
/* cas latency clock number: 1, 2, 3 */
#define SDRAM_CAS_LATENCY               3
/* read pipe delay: 0, 1, 2 */
#define SDRAM_RPIPE_DELAY               1
/* clock divid: 2, 3 */
#define SDCLOCK_PERIOD                  2
/* refresh rate counter */
#define SDRAM_REFRESH_COUNT             ((uint32_t)0x0569)
#define SDRAM_SIZE                      ((uint32_t)0x1000000)

/* Timing configuration for W9825G6KH-6 */
/* 90 MHz of SD clock frequency (180MHz/2) */
/* TMRD: 2 Clock cycles */
#define LOADTOACTIVEDELAY               2
/* TXSR: 7x11.90ns */
#define EXITSELFREFRESHDELAY            7
/* TRAS: 4x11.90ns */
#define SELFREFRESHTIME                 4
/* TRC:  7x11.90ns */
#define ROWCYCLEDELAY                   7
/* TWR:  2 Clock cycles */
#define WRITERECOVERYTIME               2
/* TRP:  2x11.90ns */
#define RPDELAY                         2
/* TRCD: 2x11.90ns */
#define RCDDELAY                        2

/* memory mode register */
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)

#endif
