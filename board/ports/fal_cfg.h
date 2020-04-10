/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-5      SummerGift   first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtthread.h>
#include <board.h>

#if 1
#define NOR_FLASH_SPI_DEV_NAME             	"W25Q64"

#define STM32_FLASH_START_ADRESS_16K		((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
#define FLASH_SIZE_GRANULARITY_16K			(4 * 16 * 1024)

#define STM32_FLASH_START_ADRESS_64K		((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
#define FLASH_SIZE_GRANULARITY_64K			(1 * 64 * 1024)

#define STM32_FLASH_START_ADRESS_128K		((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
#define FLASH_SIZE_GRANULARITY_128K			(7 * 128 * 1024)

/* ===================== Flash device Configuration ========================= */
extern const struct fal_flash_dev stm32f4_onchip_flash;
extern struct fal_flash_dev nor_flash0;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &stm32f4_onchip_flash,                                           \
    &nor_flash0,                                                     \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG
/* partition table */
#define FAL_PART_TABLE                                                               \
{                                                                                    \
    {FAL_PART_MAGIC_WROD,        "app",    "onchip_flash",                           	  128 * 1024,       896 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD,    "fm_area",    FAL_USING_NOR_FLASH_DEV_NAME,                           0,      1024 * 1024, 0}, \
    {FAL_PART_MAGIC_WROD,    "df_area",    FAL_USING_NOR_FLASH_DEV_NAME,                 1024 * 1024,      1024 * 1024, 0}, \
}
#endif

#else

#define FLASH_SIZE_GRANULARITY_16K   (4 * 16 * 1024)
#define FLASH_SIZE_GRANULARITY_64K   (64 * 1024)
#define FLASH_SIZE_GRANULARITY_128K  (7 * 128 * 1024)

#define STM32_FLASH_START_ADRESS_16K  STM32_FLASH_START_ADRESS
#define STM32_FLASH_START_ADRESS_64K  (STM32_FLASH_START_ADRESS_16K + FLASH_SIZE_GRANULARITY_16K)
#define STM32_FLASH_START_ADRESS_128K (STM32_FLASH_START_ADRESS_64K + FLASH_SIZE_GRANULARITY_64K)

extern const struct fal_flash_dev stm32_onchip_flash_16k;
extern const struct fal_flash_dev stm32_onchip_flash_64k;
extern const struct fal_flash_dev stm32_onchip_flash_128k;

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &stm32_onchip_flash_16k,                                         \
    &stm32_onchip_flash_64k,                                         \
    &stm32_onchip_flash_128k,                                        \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG

/* partition table */
#define FAL_PART_TABLE                                                                                                     \
{                                                                                                                          \
    {FAL_PART_MAGIC_WROD, "bootloader", "onchip_flash_16k",  0 , FLASH_SIZE_GRANULARITY_16K , 0}, \
    {FAL_PART_MAGIC_WROD, "param",      "onchip_flash_64k",  0 , FLASH_SIZE_GRANULARITY_64K , 0}, \
    {FAL_PART_MAGIC_WROD, "app",        "onchip_flash_128k", 0 , FLASH_SIZE_GRANULARITY_128K, 0}, \
}

#endif /* FAL_PART_HAS_TABLE_CFG */
#endif /* _FAL_CFG_H_ */
#endif
