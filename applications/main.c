/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-18     zylx         first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define	LED0_PIN_NUM	GET_PIN(G, 7)

int main(void)
{
	rt_pin_mode(LED0_PIN_NUM, PIN_MODE_OUTPUT);

	extern int finsh_set_prompt(const char * prompt);

	#if defined(RT_USING_FINSH) && defined(FINSH_USING_MSH)
	finsh_set_prompt("rt-fota />");
	#endif

	extern void rt_fota_init(void);
	rt_fota_init();
    
    return RT_EOK;
}

