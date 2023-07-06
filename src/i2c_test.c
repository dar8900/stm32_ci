#include "i2c_test.h"
#include "hmt_simple_timer.h"

#ifdef USE_I2C

static simple_timer_t I2cTestTimer;

void I2cTestInit()
{
	hmt_I2C_Init(I2C_USED);
}

void I2cTestRun()
{
	const char *Msg = "Hi from stm32f013 with i2c test\r\n";
	hmt_SimpleTimerStart(&I2cTestTimer, 500);
	while(1)
	{
		if(hmt_SimpleTimerElapsed(&I2cTestTimer, true, 0)){
			hmt_I2C_MasterTransmitter(I2C_USED, I2C_SLAVE_ADDR, Msg, strlen(Msg), 0);
		}
	}
}

#endif /* USE_I2C */