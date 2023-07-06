#ifndef TIMER_TEST_H
#define TIMER_TEST_H

#include "hmt_common.h"
#include "pwm_common.h"
#include "pwm_manager.h"
#include "ic_common.h"
#include "ic_manager.h"

#ifdef USE_PWM

void PwmTestInit();
void PwmTestRun();

#endif /* USE_PWM */

#ifdef USE_INPUT_CAPTURE

void IcTestInit();
void IcTestRun();

#endif /* USE_INPUT_CAPTURE */
#endif