#include "eeprom.h"


void write_to_eeprom(float *tab){
	static uint16_t mem_address = 0;
	uint8_t data_to_write_0[4];
	uint8_t data_to_write_1[4];
	uint8_t data_to_write_2[4];
	memcpy(data_to_write_0,&tab[0],sizeof(float));
	memcpy(data_to_write_1,&tab[1],sizeof(float));
	memcpy(data_to_write_2,&tab[2],sizeof(float));
	if(HAL_I2C_Mem_Write(&hi2c1, EEPROM_ADDRESS, mem_address, I2C_MEMADD_SIZE_8BIT, data_to_write_0, sizeof(data_to_write_0), HAL_MAX_DELAY) != HAL_OK){
		printf("blad zapis 0\n");
	}
	HAL_Delay(TIME);
	mem_address += 4;
	HAL_I2C_Mem_Write(&hi2c1, EEPROM_ADDRESS, mem_address, I2C_MEMADD_SIZE_8BIT, data_to_write_1, sizeof(data_to_write_1), HAL_MAX_DELAY);
	HAL_Delay(TIME);
	mem_address += 4;
	HAL_I2C_Mem_Write(&hi2c1, EEPROM_ADDRESS, mem_address, I2C_MEMADD_SIZE_8BIT, data_to_write_2, sizeof(data_to_write_2), HAL_MAX_DELAY);
	HAL_Delay(TIME);
	mem_address += 4;
	if(mem_address == MAX_ADDRESS){
		mem_address = 0;
	}

}



void read_from_eeprom(){
	static uint16_t mem_address = 0;
		uint8_t data_to_read_0[4];
		uint8_t data_to_read_1[4];
		uint8_t data_to_read_2[4];
		float distance[3];

		if(HAL_I2C_Mem_Read(&hi2c1, EEPROM_ADDRESS, mem_address, I2C_MEMADD_SIZE_8BIT, data_to_read_0, sizeof(data_to_read_0),  HAL_MAX_DELAY) != HAL_OK){
			//printf("blad odczytu 0\n");
		}
		HAL_Delay(TIME);
		mem_address += 4;
		HAL_I2C_Mem_Read(&hi2c1, EEPROM_ADDRESS, mem_address, I2C_MEMADD_SIZE_8BIT, data_to_read_1, sizeof(data_to_read_1),  HAL_MAX_DELAY);
		HAL_Delay(TIME);
		mem_address += 4;
		HAL_I2C_Mem_Read(&hi2c1, EEPROM_ADDRESS, mem_address, I2C_MEMADD_SIZE_8BIT, data_to_read_2, sizeof(data_to_read_2),  HAL_MAX_DELAY);
		HAL_Delay(TIME);
		mem_address += 4;
		if(mem_address == MAX_ADDRESS){
			mem_address = 0;
		}
		memcpy(&distance[0],data_to_read_0,sizeof(data_to_read_0));
		memcpy(&distance[1],data_to_read_1,sizeof(data_to_read_1));
		memcpy(&distance[2],data_to_read_2,sizeof(data_to_read_2));
		for(uint8_t i = 0; i < 3; ++i){
			printf("ultradzwiek %d: %.1f cm\n", i, distance[i]);
		}


}
