/*
 * sct.c
 *
 *  Created on: Oct 9, 2024
 *      Author: 217255
 *
 *      This is a source file of my SCT library
 *
 */

#include "sct.h"

 static const uint32_t reg_values[3][10] = {
        // Tabulka segmentů pro číslice 0–9
        {
            0b0111000000000111 << 16,  // 0
            0b0100000000000001 << 16,  // 1
            0b0011000000001011 << 16,  // 2
            0b0110000000001011 << 16,  // 3
            0b0100000000001101 << 16,  // 4
            0b0110000000001110 << 16,  // 5
            0b0111000000001110 << 16,  // 6
            0b0100000000000011 << 16,  // 7
            0b0111000000001111 << 16,  // 8
            0b0110000000001111 << 16   // 9
        },
        {
            0b0000011101110000 << 0,  // 0
            0b0000010000010000 << 0,  // 1
            0b0000001110110000 << 0,  // 2
            0b0000011010110000 << 0,  // 3
            0b0000010011010000 << 0,  // 4
            0b0000011011100000 << 0,  // 5
            0b0000011111100000 << 0,  // 6
            0b0000010000110000 << 0,  // 7
            0b0000011111110000 << 0,  // 8
            0b0000011011110000 << 0   // 9
        },
        {
            0b0111000000000111 << 0,  // 0
            0b0100000000000001 << 0,  // 1
            0b0011000000001011 << 0,  // 2
            0b0110000000001011 << 0,  // 3
            0b0100000000001101 << 0,  // 4
            0b0110000000001110 << 0,  // 5
            0b0111000000001110 << 0,  // 6
            0b0100000000000011 << 0,  // 7
            0b0111000000001111 << 0,  // 8
            0b0110000000001111 << 0   // 9
        }
    };


void sct_init() {
    sct_led(0);
}

void sct_led(uint32_t value) {
    for (uint8_t i = 0; i < 32; i++) {
        HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, (value & 1));

        HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 1);
        HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 0);

        value >>= 1;
    }

    HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 1);
    HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 0);
}


void sct_value(uint16_t value) {

    uint32_t reg = 0;

    reg |= reg_values[0][value / 100 % 10];

    reg |= reg_values[1][value / 10 % 10];

    reg |= reg_values[2][value % 10];

    sct_led(reg);
}


