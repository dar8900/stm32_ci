#include "hmt_simple_timer.h"

void hmt_SimpleTimerStart(simple_timer_t *Timer, uint32_t Timeout)
{
	if(!Timer){
		return;
	}
	if(Timeout != 0 && Timeout != Timer->timeout){
		Timer->timeout = Timeout;
	}
	Timer->start = true;
	Timer->stop = false;
	Timer->counter = hmt_GetMsTick();
}

void hmt_SimpleTimerStop(simple_timer_t *Timer)
{
	if(!Timer){
		return;
	}
	Timer->start = false;
	Timer->stop = true;	
}

void hmt_SimpleTimerRestart(simple_timer_t *Timer, uint32_t Timeout)
{
	hmt_SimpleTimerStop(Timer);
	hmt_SimpleTimerStart(Timer, Timeout);
}


bool hmt_SimpleTimerElapsed(simple_timer_t *Timer, bool Restart, uint32_t Timeout)
{
	bool Elapsed = false;
	if(!Timer){
		return false;
	}
	if(!Timer->start){
		return false;
	}
	if(hmt_GetMsTick() - Timer->counter >= Timer->timeout)
	{
		hmt_SimpleTimerStop(Timer);
		if(Restart){
			hmt_SimpleTimerRestart(Timer, Timeout);
		}
		Elapsed = true;
	}
	return Elapsed;
}

bool hmt_SimpleTimerOngoing(simple_timer_t *Timer)
{
	return Timer->start;
}