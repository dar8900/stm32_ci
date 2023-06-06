#ifndef HMT_SIMPLE_TIMER_H
#define HMT_SIMPLE_TIMER_H

#include "hmt_common.h"

/**
 * @brief Start the timer with a timeout
 * 
 * @param simple_timer* Timer 
 * @param uint32_t Timeout 
 */
void hmt_SimpleTimerStart(simple_timer *Timer, uint32_t Timeout);

/**
 * @brief Stop the timer
 * 
 * @param simple_timer* Timer 
 */
void hmt_SimpleTimerStop(simple_timer *Timer);

/**
 * @brief Restart the timer with optionally a new timeout if != 0 
 * 			or != from the old one
 * 
 * @param simple_timer* Timer
 * @param uint32_t Timeout 
 */
void hmt_SimpleTimerRestart(simple_timer *Timer, uint32_t Timeout);

/**
 * @brief Check if the timer is elapsed, if Restart = true, the timer restarting 
 * 			with optionally a new timeout if != 0 or != from the old one
 * 
 * @param simple_timer* Timer
 * @param bool Restart 
 * @param uint32_t Timeout 
 * @return [bool] Elsapsed 
 */
bool hmt_SimpleTimerElapsed(simple_timer *Timer, bool Restart, uint32_t Timeout);

/**
 * @brief Return the state of the timer
 * 
 * @param simple_timer* Timer 
 * @return [bool] Ongoing 
 */
bool hmt_SimpleTimerOngoing(simple_timer *Timer);

#endif