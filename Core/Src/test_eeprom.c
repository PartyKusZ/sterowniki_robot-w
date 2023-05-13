/*
 * test_eeprom.c
 *
 *  Created on: May 13, 2023
 *      Author: kubus
 */

/*void test_eeprom(){
	uint8_t test = 0x5A;
	  uint8_t result = 0x00;

	 if(HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0x10, 1, &test, sizeof(test), 100) != HAL_OK){
			printf("Blad zapisu\n\r");
		  }
		   HAL_Delay(100);
		  if (HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0x10, 1, &result, sizeof(result), 100) != HAL_OK){
			  printf("Blad odczytu\n\r");
		  }

		  printf("%d\n\r", result);

		  if(HAL_I2C_Mem_Write(&hi2c1, 0xA0, 0x10, 1, &test, sizeof(test), 100) == HAL_ERROR){
		  		printf("hal busy\n\r");
		  	  }

		  HAL_Delay(1000);
}*/



