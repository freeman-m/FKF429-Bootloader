# FK429 FOTA Bootloader

**FK-F429开发板硬件**
- MCU：STM32F429BIT6，主频 180MHz，2048KB FLASH ，256KB RAM (SRAM1:64K SRAM2:16K SRAM3:64K CCMRAM:64K)
- 外部 RAM：W9812G2（SDRAM，16MB，32bit）(bootloader未使用)
- 外部 FLASH：W25Q64(BVSSIG)（SPI，8MB）
- 常用外设
  - LED：PD12
  - 按键：PI8
- 常用接口：UART(PA9 PA10)
- 调试接口：SWD

**FOTA Bootloader实现功能**
- 基于RT-Thread-v4.0.2移植
- spi flash存在df_area和fm_area两个分区
- 支持通过ymodem传送数据到spi flash
- 支持RTT官方的RBL打包软件，使用方式也一致。目前支持包括CRC32、AES256、quicklz和fastlz功能
- 支持命令行模式（FINSH组件）和出厂固件恢复
- 支持FLASH分区（FAL组件）

**感谢RTT论坛的Spunky大神**
- 此版本是基于原作者源码移植到FK-F429开发板上
- 具体使用方式可参考[原贴地址](https://www.rt-thread.org/qa/thread-422812-1-1.html)

-  [GitHub](https://github.com/freeman-m/FKF429-Bootloader), 邮箱：<136287213@qq.com>