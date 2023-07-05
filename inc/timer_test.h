#ifndef TIMER_TEST_H
#define TIMER_TEST_H

#ifdef USE_PWM

void PwmTestInit();
void PwmTestRun();

#endif /* USE_PWM */

#ifdef USE_INPUT_CAPTURE

void IcTestInit();
void IcTestRun();

#endif /* USE_INPUT_CAPTURE */
#endif