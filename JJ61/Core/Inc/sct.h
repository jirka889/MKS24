/*
 * sct.h
 *
 *  Created on: Oct 9, 2024
 *      Author: 217255
 *      This is header of mz SCT library
 */

#ifndef SRC_SCT_H_
#define SRC_SCT_H_
#include "main.h"

void sct_init();
void sct_led(uint32_t value);
void sct_value(uint16_t value,uint16_t LED);

#endif /* SRC_SCT_H_ */
