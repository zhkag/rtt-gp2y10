/*
 * Copyright (c) 2020, RudyLo <luhuadong@163.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-01-21     luhuadong    the first version
 */

#ifndef __GP2Y10_H__
#define __GP2Y10_H__

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"

#define GP2Y10LIB_VERSION   "0.0.1"

#define ADC_DEV_NAME        "adc1"      /* ADC device name */
#define ADC_DEV_CHANNEL     4           /* ADC channel */
#define CONVERT_BITS        (1 << 12)   /* 转换位数为12位 */


/* 
 * PKG_USING_GP2Y10_VOLTAGE_RATIO  11
 * PKG_USING_GP2Y10_SOFT_FILTER
 */


struct gp2y10_device
{
	rt_adc_device_t adc_dev;
	rt_base_t  iled_pin;
	rt_base_t  aout_pin;
	rt_mutex_t lock;
};
typedef struct gp2y10_device *gp2y10_device_t;

gp2y10_device_t gp2y10_init(gp2y10_device_t dev, rt_base_t iled_pin, rt_base_t aout_pin);
void gp2y10_deinit(gp2y10_device_t dev);

rt_uint32_t gp2y10_get_adc_value(gp2y10_device_t dev);
float gp2y10_get_voltage(gp2y10_device_t dev);
float gp2y10_get_dust_density(gp2y10_device_t dev);

#endif /* __GP2Y10_H__ */