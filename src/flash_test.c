#include "flash_test.h"

#define FIRST_DATA	0xAABBCCDD
#define SECOND_DATA	0xCDCDCDCD
#define THIRD_DATA	0xDDCCBBAA

static void WriteFlash();
static void ReadFlash();
static bool MemoryClear();

static bool WriteOne = false;
static uint32_t DataToWrite [3] = {FIRST_DATA, SECOND_DATA, THIRD_DATA}, DataReaded[3] = {0};

void FlashTestInit()
{
	hmt_Flash_Init();
	ReadFlash();
	if(MemoryClear()){
		WriteOne = true;
	}
}


void FlashTestRun()
{
	if(WriteOne){
		WriteFlash();
	}
	ReadFlash();
}

static void WriteFlash()
{
	hmt_Flash_WriteData(0, FIRST_DATA);
	hmt_Flash_WriteData(hmt_Flash_GetMaxAddr() / 2, SECOND_DATA);
	hmt_Flash_WriteData(hmt_Flash_GetMaxAddr(), THIRD_DATA);
}

static void ReadFlash()
{
	hmt_Flash_ReadData(0, &DataReaded[0]);
	hmt_Flash_ReadData(hmt_Flash_GetMaxAddr() / 2, &DataReaded[1]);
	hmt_Flash_ReadData(hmt_Flash_GetMaxAddr(), &DataReaded[2]);
}

static bool MemoryClear()
{
	for(int i = 0; i < 3; i++){
		if(DataReaded[i] != DataToWrite[i]){
			return false;
		}
	}
	return true;
}