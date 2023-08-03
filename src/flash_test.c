#include "flash_test.h"
#include "hmt_simple_timer.h"

#define FIRST_DATA	0xAABBCCDD
#define SECOND_DATA	0xCDCDCDCD
#define THIRD_DATA	0xDDCCBBAA

static void WriteFlash();
static void ReadFlash();
static bool MemoryClear();

static simple_timer_t FlashTestTimer;
static bool WriteOne = false;
static uint32_t DataToWrite [3] = {FIRST_DATA, SECOND_DATA, THIRD_DATA}, DataReaded[3] = {0};

void FlashTestInit()
{
	hmt_Flash_Init();
	ReadFlash();
	if(MemoryClear()){
		WriteOne = true;
	}
	hmt_SimpleTimerStart(&FlashTestTimer, 2000);
}


void FlashTestRun()
{
	if(hmt_SimpleTimerElapsed(&FlashTestTimer, true, 0))
	{
		if(WriteOne){
			WriteFlash();
			WriteOne = false;
		}
		ReadFlash();
	}
}

static void WriteFlash()
{
	hmt_Flash_WriteData(0, &DataToWrite[0], 1, sizeof(uint32_t));
	hmt_Flash_WriteData(hmt_Flash_GetMaxAddr() / 2, &DataToWrite[1], 1, sizeof(uint32_t));
	hmt_Flash_WriteData(hmt_Flash_GetMaxAddr(), &DataToWrite[2], 1, sizeof(uint32_t));
}

static void ReadFlash()
{
	hmt_Flash_ReadData(0, &DataReaded[0], 1, sizeof(uint32_t));
	hmt_Flash_ReadData(hmt_Flash_GetMaxAddr() / 2, &DataReaded[1], 1, sizeof(uint32_t));
	hmt_Flash_ReadData(hmt_Flash_GetMaxAddr(), &DataReaded[2], 1, sizeof(uint32_t));
}

static bool MemoryClear()
{
	for(int i = 0; i < 3; i++){
		if(DataReaded[i] != DataToWrite[i]){
			return true;
		}
	}
	return false;
}