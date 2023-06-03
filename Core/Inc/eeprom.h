/*
 * eeprom.h
 *
 *  Created on: 3 cze 2023
 *      Author: kubus
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "i2c.h"
#include <string.h>
#include <stdio.h>

#define EEPROM_ADDRESS 0xA0 // eeprom address
#define MAX_ADDRESS 120 // max adress that can be used for 12B block of data
#define TIME 5 // time needed for proper i2c processing

/**
 * wites 12B blocks of data to eeprom
 */
void write_to_eeprom(float *tab);

/**
 * send to uart each 12B block of data
 */
void read_from_eeprom();


#endif /* INC_EEPROM_H_ */
