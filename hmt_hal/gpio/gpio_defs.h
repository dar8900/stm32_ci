#ifndef GPIO_DEFS_H
#define GPIO_DEFS_H

#include "hmt_common.h"

#define N_PORT           8 /* A B C D E F G H */
#define N_PIN_X_PORT    16
#define MAX_GPIO        (N_PORT * N_PIN_X_PORT)

#define ADD_GPIO_TO_TAB(port, pin)      {GPIO##port, P##port##_##pin##_PIN, \
                                        P##port##_##pin##_MODE, P##port##_##pin##_SPEED,\
                                        P##port##_##pin##_OUTPUT, P##port##_##pin##_PULL_TYPE, 0, \
                                        HIGH, LOW, LOW}

/* PORT A */

#define PA_0_PIN    IO_PIN_0

#ifndef PA_0_MODE
#define    PA_0_MODE    NOT_USED
#endif

#ifndef PA_0_SPEED
#define    PA_0_SPEED    SPEED_HIGH
#endif

#ifndef PA_0_OUTPUT
#define    PA_0_OUTPUT    PUSH_PULL
#endif

#ifndef PA_0_PULL_TYPE
#define    PA_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PA_1_MODE
#define    PA_1_MODE    NOT_USED
#endif

#ifndef PA_1_SPEED
#define    PA_1_SPEED    SPEED_HIGH
#endif

#ifndef PA_1_OUTPUT
#define    PA_1_OUTPUT    PUSH_PULL
#endif

#ifndef PA_1_PULL_TYPE
#define    PA_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PA_2_MODE
#define    PA_2_MODE    NOT_USED
#endif

#ifndef PA_2_SPEED
#define    PA_2_SPEED    SPEED_HIGH
#endif

#ifndef PA_2_OUTPUT
#define    PA_2_OUTPUT    PUSH_PULL
#endif

#ifndef PA_2_PULL_TYPE
#define    PA_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PA_3_MODE
#define    PA_3_MODE    NOT_USED
#endif

#ifndef PA_3_SPEED
#define    PA_3_SPEED    SPEED_HIGH
#endif

#ifndef PA_3_OUTPUT
#define    PA_3_OUTPUT    PUSH_PULL
#endif

#ifndef PA_3_PULL_TYPE
#define    PA_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PA_4_MODE
#define    PA_4_MODE    NOT_USED
#endif

#ifndef PA_4_SPEED
#define    PA_4_SPEED    SPEED_HIGH
#endif

#ifndef PA_4_OUTPUT
#define    PA_4_OUTPUT    PUSH_PULL
#endif

#ifndef PA_4_PULL_TYPE
#define    PA_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PA_5_MODE
#define    PA_5_MODE    NOT_USED
#endif

#ifndef PA_5_SPEED
#define    PA_5_SPEED    SPEED_HIGH
#endif

#ifndef PA_5_OUTPUT
#define    PA_5_OUTPUT    PUSH_PULL
#endif

#ifndef PA_5_PULL_TYPE
#define    PA_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PA_6_MODE
#define    PA_6_MODE    NOT_USED
#endif

#ifndef PA_6_SPEED
#define    PA_6_SPEED    SPEED_HIGH
#endif

#ifndef PA_6_OUTPUT
#define    PA_6_OUTPUT    PUSH_PULL
#endif

#ifndef PA_6_PULL_TYPE
#define    PA_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PA_7_MODE
#define    PA_7_MODE    NOT_USED
#endif

#ifndef PA_7_SPEED
#define    PA_7_SPEED    SPEED_HIGH
#endif

#ifndef PA_7_OUTPUT
#define    PA_7_OUTPUT    PUSH_PULL
#endif

#ifndef PA_7_PULL_TYPE
#define    PA_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PA_8_MODE
#define    PA_8_MODE    NOT_USED
#endif

#ifndef PA_8_SPEED
#define    PA_8_SPEED    SPEED_HIGH
#endif

#ifndef PA_8_OUTPUT
#define    PA_8_OUTPUT    PUSH_PULL
#endif

#ifndef PA_8_PULL_TYPE
#define    PA_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PA_9_MODE
#define    PA_9_MODE    NOT_USED
#endif

#ifndef PA_9_SPEED
#define    PA_9_SPEED    SPEED_HIGH
#endif

#ifndef PA_9_OUTPUT
#define    PA_9_OUTPUT    PUSH_PULL
#endif

#ifndef PA_9_PULL_TYPE
#define    PA_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PA_10_MODE
#define    PA_10_MODE    NOT_USED
#endif

#ifndef PA_10_SPEED
#define    PA_10_SPEED    SPEED_HIGH
#endif

#ifndef PA_10_OUTPUT
#define    PA_10_OUTPUT    PUSH_PULL
#endif

#ifndef PA_10_PULL_TYPE
#define    PA_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PA_11_MODE
#define    PA_11_MODE    NOT_USED
#endif

#ifndef PA_11_SPEED
#define    PA_11_SPEED    SPEED_HIGH
#endif

#ifndef PA_11_OUTPUT
#define    PA_11_OUTPUT    PUSH_PULL
#endif

#ifndef PA_11_PULL_TYPE
#define    PA_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PA_12_MODE
#define    PA_12_MODE    NOT_USED
#endif

#ifndef PA_12_SPEED
#define    PA_12_SPEED    SPEED_HIGH
#endif

#ifndef PA_12_OUTPUT
#define    PA_12_OUTPUT    PUSH_PULL
#endif

#ifndef PA_12_PULL_TYPE
#define    PA_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PA_13_MODE
#define    PA_13_MODE    NOT_USED
#endif

#ifndef PA_13_SPEED
#define    PA_13_SPEED    SPEED_HIGH
#endif

#ifndef PA_13_OUTPUT
#define    PA_13_OUTPUT    PUSH_PULL
#endif

#ifndef PA_13_PULL_TYPE
#define    PA_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PA_14_MODE
#define    PA_14_MODE    NOT_USED
#endif

#ifndef PA_14_SPEED
#define    PA_14_SPEED    SPEED_HIGH
#endif

#ifndef PA_14_OUTPUT
#define    PA_14_OUTPUT    PUSH_PULL
#endif

#ifndef PA_14_PULL_TYPE
#define    PA_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PA_15_MODE
#define    PA_15_MODE    NOT_USED
#endif

#ifndef PA_15_SPEED
#define    PA_15_SPEED    SPEED_HIGH
#endif

#ifndef PA_15_OUTPUT
#define    PA_15_OUTPUT    PUSH_PULL
#endif

#ifndef PA_15_PULL_TYPE
#define    PA_15_PULL_TYPE    NO_PULL
#endif

/* PORT B */

#define PA_0_PIN    IO_PIN_0

#ifndef PB_0_MODE
#define    PB_0_MODE    NOT_USED
#endif

#ifndef PB_0_SPEED
#define    PB_0_SPEED    SPEED_HIGH
#endif

#ifndef PB_0_OUTPUT
#define    PB_0_OUTPUT    PUSH_PULL
#endif

#ifndef PB_0_PULL_TYPE
#define    PB_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PB_1_MODE
#define    PB_1_MODE    NOT_USED
#endif

#ifndef PB_1_SPEED
#define    PB_1_SPEED    SPEED_HIGH
#endif

#ifndef PB_1_OUTPUT
#define    PB_1_OUTPUT    PUSH_PULL
#endif

#ifndef PB_1_PULL_TYPE
#define    PB_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PB_2_MODE
#define    PB_2_MODE    NOT_USED
#endif

#ifndef PB_2_SPEED
#define    PB_2_SPEED    SPEED_HIGH
#endif

#ifndef PB_2_OUTPUT
#define    PB_2_OUTPUT    PUSH_PULL
#endif

#ifndef PB_2_PULL_TYPE
#define    PB_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PB_3_MODE
#define    PB_3_MODE    NOT_USED
#endif

#ifndef PB_3_SPEED
#define    PB_3_SPEED    SPEED_HIGH
#endif

#ifndef PB_3_OUTPUT
#define    PB_3_OUTPUT    PUSH_PULL
#endif

#ifndef PB_3_PULL_TYPE
#define    PB_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PB_4_MODE
#define    PB_4_MODE    NOT_USED
#endif

#ifndef PB_4_SPEED
#define    PB_4_SPEED    SPEED_HIGH
#endif

#ifndef PB_4_OUTPUT
#define    PB_4_OUTPUT    PUSH_PULL
#endif

#ifndef PB_4_PULL_TYPE
#define    PB_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PB_5_MODE
#define    PB_5_MODE    NOT_USED
#endif

#ifndef PB_5_SPEED
#define    PB_5_SPEED    SPEED_HIGH
#endif

#ifndef PB_5_OUTPUT
#define    PB_5_OUTPUT    PUSH_PULL
#endif

#ifndef PB_5_PULL_TYPE
#define    PB_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PB_6_MODE
#define    PB_6_MODE    NOT_USED
#endif

#ifndef PB_6_SPEED
#define    PB_6_SPEED    SPEED_HIGH
#endif

#ifndef PB_6_OUTPUT
#define    PB_6_OUTPUT    PUSH_PULL
#endif

#ifndef PB_6_PULL_TYPE
#define    PB_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PB_7_MODE
#define    PB_7_MODE    NOT_USED
#endif

#ifndef PB_7_SPEED
#define    PB_7_SPEED    SPEED_HIGH
#endif

#ifndef PB_7_OUTPUT
#define    PB_7_OUTPUT    PUSH_PULL
#endif

#ifndef PB_7_PULL_TYPE
#define    PB_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PB_8_MODE
#define    PB_8_MODE    NOT_USED
#endif

#ifndef PB_8_SPEED
#define    PB_8_SPEED    SPEED_HIGH
#endif

#ifndef PB_8_OUTPUT
#define    PB_8_OUTPUT    PUSH_PULL
#endif

#ifndef PB_8_PULL_TYPE
#define    PB_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PB_9_MODE
#define    PB_9_MODE    NOT_USED
#endif

#ifndef PB_9_SPEED
#define    PB_9_SPEED    SPEED_HIGH
#endif

#ifndef PB_9_OUTPUT
#define    PB_9_OUTPUT    PUSH_PULL
#endif

#ifndef PB_9_PULL_TYPE
#define    PB_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PB_10_MODE
#define    PB_10_MODE    NOT_USED
#endif

#ifndef PB_10_SPEED
#define    PB_10_SPEED    SPEED_HIGH
#endif

#ifndef PB_10_OUTPUT
#define    PB_10_OUTPUT    PUSH_PULL
#endif

#ifndef PB_10_PULL_TYPE
#define    PB_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PB_11_MODE
#define    PB_11_MODE    NOT_USED
#endif

#ifndef PB_11_SPEED
#define    PB_11_SPEED    SPEED_HIGH
#endif

#ifndef PB_11_OUTPUT
#define    PB_11_OUTPUT    PUSH_PULL
#endif

#ifndef PB_11_PULL_TYPE
#define    PB_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PB_12_MODE
#define    PB_12_MODE    NOT_USED
#endif

#ifndef PB_12_SPEED
#define    PB_12_SPEED    SPEED_HIGH
#endif

#ifndef PB_12_OUTPUT
#define    PB_12_OUTPUT    PUSH_PULL
#endif

#ifndef PB_12_PULL_TYPE
#define    PB_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PB_13_MODE
#define    PB_13_MODE    NOT_USED
#endif

#ifndef PB_13_SPEED
#define    PB_13_SPEED    SPEED_HIGH
#endif

#ifndef PB_13_OUTPUT
#define    PB_13_OUTPUT    PUSH_PULL
#endif

#ifndef PB_13_PULL_TYPE
#define    PB_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PB_14_MODE
#define    PB_14_MODE    NOT_USED
#endif

#ifndef PB_14_SPEED
#define    PB_14_SPEED    SPEED_HIGH
#endif

#ifndef PB_14_OUTPUT
#define    PB_14_OUTPUT    PUSH_PULL
#endif

#ifndef PB_14_PULL_TYPE
#define    PB_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PB_15_MODE
#define    PB_15_MODE    NOT_USED
#endif

#ifndef PB_15_SPEED
#define    PB_15_SPEED    SPEED_HIGH
#endif

#ifndef PB_15_OUTPUT
#define    PB_15_OUTPUT    PUSH_PULL
#endif

#ifndef PB_15_PULL_TYPE
#define    PB_15_PULL_TYPE    NO_PULL
#endif

/* PORT C */

#define PA_0_PIN    IO_PIN_0

#ifndef PC_0_MODE
#define    PC_0_MODE    NOT_USED
#endif

#ifndef PC_0_SPEED
#define    PC_0_SPEED    SPEED_HIGH
#endif

#ifndef PC_0_OUTPUT
#define    PC_0_OUTPUT    PUSH_PULL
#endif

#ifndef PC_0_PULL_TYPE
#define    PC_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PC_1_MODE
#define    PC_1_MODE    NOT_USED
#endif

#ifndef PC_1_SPEED
#define    PC_1_SPEED    SPEED_HIGH
#endif

#ifndef PC_1_OUTPUT
#define    PC_1_OUTPUT    PUSH_PULL
#endif

#ifndef PC_1_PULL_TYPE
#define    PC_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PC_2_MODE
#define    PC_2_MODE    NOT_USED
#endif

#ifndef PC_2_SPEED
#define    PC_2_SPEED    SPEED_HIGH
#endif

#ifndef PC_2_OUTPUT
#define    PC_2_OUTPUT    PUSH_PULL
#endif

#ifndef PC_2_PULL_TYPE
#define    PC_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PC_3_MODE
#define    PC_3_MODE    NOT_USED
#endif

#ifndef PC_3_SPEED
#define    PC_3_SPEED    SPEED_HIGH
#endif

#ifndef PC_3_OUTPUT
#define    PC_3_OUTPUT    PUSH_PULL
#endif

#ifndef PC_3_PULL_TYPE
#define    PC_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PC_4_MODE
#define    PC_4_MODE    NOT_USED
#endif

#ifndef PC_4_SPEED
#define    PC_4_SPEED    SPEED_HIGH
#endif

#ifndef PC_4_OUTPUT
#define    PC_4_OUTPUT    PUSH_PULL
#endif

#ifndef PC_4_PULL_TYPE
#define    PC_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PC_5_MODE
#define    PC_5_MODE    NOT_USED
#endif

#ifndef PC_5_SPEED
#define    PC_5_SPEED    SPEED_HIGH
#endif

#ifndef PC_5_OUTPUT
#define    PC_5_OUTPUT    PUSH_PULL
#endif

#ifndef PC_5_PULL_TYPE
#define    PC_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PC_6_MODE
#define    PC_6_MODE    NOT_USED
#endif

#ifndef PC_6_SPEED
#define    PC_6_SPEED    SPEED_HIGH
#endif

#ifndef PC_6_OUTPUT
#define    PC_6_OUTPUT    PUSH_PULL
#endif

#ifndef PC_6_PULL_TYPE
#define    PC_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PC_7_MODE
#define    PC_7_MODE    NOT_USED
#endif

#ifndef PC_7_SPEED
#define    PC_7_SPEED    SPEED_HIGH
#endif

#ifndef PC_7_OUTPUT
#define    PC_7_OUTPUT    PUSH_PULL
#endif

#ifndef PC_7_PULL_TYPE
#define    PC_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PC_8_MODE
#define    PC_8_MODE    NOT_USED
#endif

#ifndef PC_8_SPEED
#define    PC_8_SPEED    SPEED_HIGH
#endif

#ifndef PC_8_OUTPUT
#define    PC_8_OUTPUT    PUSH_PULL
#endif

#ifndef PC_8_PULL_TYPE
#define    PC_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PC_9_MODE
#define    PC_9_MODE    NOT_USED
#endif

#ifndef PC_9_SPEED
#define    PC_9_SPEED    SPEED_HIGH
#endif

#ifndef PC_9_OUTPUT
#define    PC_9_OUTPUT    PUSH_PULL
#endif

#ifndef PC_9_PULL_TYPE
#define    PC_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PC_10_MODE
#define    PC_10_MODE    NOT_USED
#endif

#ifndef PC_10_SPEED
#define    PC_10_SPEED    SPEED_HIGH
#endif

#ifndef PC_10_OUTPUT
#define    PC_10_OUTPUT    PUSH_PULL
#endif

#ifndef PC_10_PULL_TYPE
#define    PC_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PC_11_MODE
#define    PC_11_MODE    NOT_USED
#endif

#ifndef PC_11_SPEED
#define    PC_11_SPEED    SPEED_HIGH
#endif

#ifndef PC_11_OUTPUT
#define    PC_11_OUTPUT    PUSH_PULL
#endif

#ifndef PC_11_PULL_TYPE
#define    PC_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PC_12_MODE
#define    PC_12_MODE    NOT_USED
#endif

#ifndef PC_12_SPEED
#define    PC_12_SPEED    SPEED_HIGH
#endif

#ifndef PC_12_OUTPUT
#define    PC_12_OUTPUT    PUSH_PULL
#endif

#ifndef PC_12_PULL_TYPE
#define    PC_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PC_13_MODE
#define    PC_13_MODE    NOT_USED
#endif

#ifndef PC_13_SPEED
#define    PC_13_SPEED    SPEED_HIGH
#endif

#ifndef PC_13_OUTPUT
#define    PC_13_OUTPUT    PUSH_PULL
#endif

#ifndef PC_13_PULL_TYPE
#define    PC_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PC_14_MODE
#define    PC_14_MODE    NOT_USED
#endif

#ifndef PC_14_SPEED
#define    PC_14_SPEED    SPEED_HIGH
#endif

#ifndef PC_14_OUTPUT
#define    PC_14_OUTPUT    PUSH_PULL
#endif

#ifndef PC_14_PULL_TYPE
#define    PC_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PC_15_MODE
#define    PC_15_MODE    NOT_USED
#endif

#ifndef PC_15_SPEED
#define    PC_15_SPEED    SPEED_HIGH
#endif

#ifndef PC_15_OUTPUT
#define    PC_15_OUTPUT    PUSH_PULL
#endif

#ifndef PC_15_PULL_TYPE
#define    PC_15_PULL_TYPE    NO_PULL
#endif

/* PORT D */

#define PA_0_PIN    IO_PIN_0

#ifndef PD_0_MODE
#define    PD_0_MODE    NOT_USED
#endif

#ifndef PD_0_SPEED
#define    PD_0_SPEED    SPEED_HIGH
#endif

#ifndef PD_0_OUTPUT
#define    PD_0_OUTPUT    PUSH_PULL
#endif

#ifndef PD_0_PULL_TYPE
#define    PD_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PD_1_MODE
#define    PD_1_MODE    NOT_USED
#endif

#ifndef PD_1_SPEED
#define    PD_1_SPEED    SPEED_HIGH
#endif

#ifndef PD_1_OUTPUT
#define    PD_1_OUTPUT    PUSH_PULL
#endif

#ifndef PD_1_PULL_TYPE
#define    PD_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PD_2_MODE
#define    PD_2_MODE    NOT_USED
#endif

#ifndef PD_2_SPEED
#define    PD_2_SPEED    SPEED_HIGH
#endif

#ifndef PD_2_OUTPUT
#define    PD_2_OUTPUT    PUSH_PULL
#endif

#ifndef PD_2_PULL_TYPE
#define    PD_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PD_3_MODE
#define    PD_3_MODE    NOT_USED
#endif

#ifndef PD_3_SPEED
#define    PD_3_SPEED    SPEED_HIGH
#endif

#ifndef PD_3_OUTPUT
#define    PD_3_OUTPUT    PUSH_PULL
#endif

#ifndef PD_3_PULL_TYPE
#define    PD_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PD_4_MODE
#define    PD_4_MODE    NOT_USED
#endif

#ifndef PD_4_SPEED
#define    PD_4_SPEED    SPEED_HIGH
#endif

#ifndef PD_4_OUTPUT
#define    PD_4_OUTPUT    PUSH_PULL
#endif

#ifndef PD_4_PULL_TYPE
#define    PD_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PD_5_MODE
#define    PD_5_MODE    NOT_USED
#endif

#ifndef PD_5_SPEED
#define    PD_5_SPEED    SPEED_HIGH
#endif

#ifndef PD_5_OUTPUT
#define    PD_5_OUTPUT    PUSH_PULL
#endif

#ifndef PD_5_PULL_TYPE
#define    PD_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PD_6_MODE
#define    PD_6_MODE    NOT_USED
#endif

#ifndef PD_6_SPEED
#define    PD_6_SPEED    SPEED_HIGH
#endif

#ifndef PD_6_OUTPUT
#define    PD_6_OUTPUT    PUSH_PULL
#endif

#ifndef PD_6_PULL_TYPE
#define    PD_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PD_7_MODE
#define    PD_7_MODE    NOT_USED
#endif

#ifndef PD_7_SPEED
#define    PD_7_SPEED    SPEED_HIGH
#endif

#ifndef PD_7_OUTPUT
#define    PD_7_OUTPUT    PUSH_PULL
#endif

#ifndef PD_7_PULL_TYPE
#define    PD_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PD_8_MODE
#define    PD_8_MODE    NOT_USED
#endif

#ifndef PD_8_SPEED
#define    PD_8_SPEED    SPEED_HIGH
#endif

#ifndef PD_8_OUTPUT
#define    PD_8_OUTPUT    PUSH_PULL
#endif

#ifndef PD_8_PULL_TYPE
#define    PD_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PD_9_MODE
#define    PD_9_MODE    NOT_USED
#endif

#ifndef PD_9_SPEED
#define    PD_9_SPEED    SPEED_HIGH
#endif

#ifndef PD_9_OUTPUT
#define    PD_9_OUTPUT    PUSH_PULL
#endif

#ifndef PD_9_PULL_TYPE
#define    PD_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PD_10_MODE
#define    PD_10_MODE    NOT_USED
#endif

#ifndef PD_10_SPEED
#define    PD_10_SPEED    SPEED_HIGH
#endif

#ifndef PD_10_OUTPUT
#define    PD_10_OUTPUT    PUSH_PULL
#endif

#ifndef PD_10_PULL_TYPE
#define    PD_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PD_11_MODE
#define    PD_11_MODE    NOT_USED
#endif

#ifndef PD_11_SPEED
#define    PD_11_SPEED    SPEED_HIGH
#endif

#ifndef PD_11_OUTPUT
#define    PD_11_OUTPUT    PUSH_PULL
#endif

#ifndef PD_11_PULL_TYPE
#define    PD_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PD_12_MODE
#define    PD_12_MODE    NOT_USED
#endif

#ifndef PD_12_SPEED
#define    PD_12_SPEED    SPEED_HIGH
#endif

#ifndef PD_12_OUTPUT
#define    PD_12_OUTPUT    PUSH_PULL
#endif

#ifndef PD_12_PULL_TYPE
#define    PD_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PD_13_MODE
#define    PD_13_MODE    NOT_USED
#endif

#ifndef PD_13_SPEED
#define    PD_13_SPEED    SPEED_HIGH
#endif

#ifndef PD_13_OUTPUT
#define    PD_13_OUTPUT    PUSH_PULL
#endif

#ifndef PD_13_PULL_TYPE
#define    PD_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PD_14_MODE
#define    PD_14_MODE    NOT_USED
#endif

#ifndef PD_14_SPEED
#define    PD_14_SPEED    SPEED_HIGH
#endif

#ifndef PD_14_OUTPUT
#define    PD_14_OUTPUT    PUSH_PULL
#endif

#ifndef PD_14_PULL_TYPE
#define    PD_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PD_15_MODE
#define    PD_15_MODE    NOT_USED
#endif

#ifndef PD_15_SPEED
#define    PD_15_SPEED    SPEED_HIGH
#endif

#ifndef PD_15_OUTPUT
#define    PD_15_OUTPUT    PUSH_PULL
#endif

#ifndef PD_15_PULL_TYPE
#define    PD_15_PULL_TYPE    NO_PULL
#endif

/* PORT E */

#define PA_0_PIN    IO_PIN_0

#ifndef PE_0_MODE
#define    PE_0_MODE    NOT_USED
#endif

#ifndef PE_0_SPEED
#define    PE_0_SPEED    SPEED_HIGH
#endif

#ifndef PE_0_OUTPUT
#define    PE_0_OUTPUT    PUSH_PULL
#endif

#ifndef PE_0_PULL_TYPE
#define    PE_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PE_1_MODE
#define    PE_1_MODE    NOT_USED
#endif

#ifndef PE_1_SPEED
#define    PE_1_SPEED    SPEED_HIGH
#endif

#ifndef PE_1_OUTPUT
#define    PE_1_OUTPUT    PUSH_PULL
#endif

#ifndef PE_1_PULL_TYPE
#define    PE_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PE_2_MODE
#define    PE_2_MODE    NOT_USED
#endif

#ifndef PE_2_SPEED
#define    PE_2_SPEED    SPEED_HIGH
#endif

#ifndef PE_2_OUTPUT
#define    PE_2_OUTPUT    PUSH_PULL
#endif

#ifndef PE_2_PULL_TYPE
#define    PE_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PE_3_MODE
#define    PE_3_MODE    NOT_USED
#endif

#ifndef PE_3_SPEED
#define    PE_3_SPEED    SPEED_HIGH
#endif

#ifndef PE_3_OUTPUT
#define    PE_3_OUTPUT    PUSH_PULL
#endif

#ifndef PE_3_PULL_TYPE
#define    PE_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PE_4_MODE
#define    PE_4_MODE    NOT_USED
#endif

#ifndef PE_4_SPEED
#define    PE_4_SPEED    SPEED_HIGH
#endif

#ifndef PE_4_OUTPUT
#define    PE_4_OUTPUT    PUSH_PULL
#endif

#ifndef PE_4_PULL_TYPE
#define    PE_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PE_5_MODE
#define    PE_5_MODE    NOT_USED
#endif

#ifndef PE_5_SPEED
#define    PE_5_SPEED    SPEED_HIGH
#endif

#ifndef PE_5_OUTPUT
#define    PE_5_OUTPUT    PUSH_PULL
#endif

#ifndef PE_5_PULL_TYPE
#define    PE_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PE_6_MODE
#define    PE_6_MODE    NOT_USED
#endif

#ifndef PE_6_SPEED
#define    PE_6_SPEED    SPEED_HIGH
#endif

#ifndef PE_6_OUTPUT
#define    PE_6_OUTPUT    PUSH_PULL
#endif

#ifndef PE_6_PULL_TYPE
#define    PE_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PE_7_MODE
#define    PE_7_MODE    NOT_USED
#endif

#ifndef PE_7_SPEED
#define    PE_7_SPEED    SPEED_HIGH
#endif

#ifndef PE_7_OUTPUT
#define    PE_7_OUTPUT    PUSH_PULL
#endif

#ifndef PE_7_PULL_TYPE
#define    PE_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PE_8_MODE
#define    PE_8_MODE    NOT_USED
#endif

#ifndef PE_8_SPEED
#define    PE_8_SPEED    SPEED_HIGH
#endif

#ifndef PE_8_OUTPUT
#define    PE_8_OUTPUT    PUSH_PULL
#endif

#ifndef PE_8_PULL_TYPE
#define    PE_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PE_9_MODE
#define    PE_9_MODE    NOT_USED
#endif

#ifndef PE_9_SPEED
#define    PE_9_SPEED    SPEED_HIGH
#endif

#ifndef PE_9_OUTPUT
#define    PE_9_OUTPUT    PUSH_PULL
#endif

#ifndef PE_9_PULL_TYPE
#define    PE_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PE_10_MODE
#define    PE_10_MODE    NOT_USED
#endif

#ifndef PE_10_SPEED
#define    PE_10_SPEED    SPEED_HIGH
#endif

#ifndef PE_10_OUTPUT
#define    PE_10_OUTPUT    PUSH_PULL
#endif

#ifndef PE_10_PULL_TYPE
#define    PE_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PE_11_MODE
#define    PE_11_MODE    NOT_USED
#endif

#ifndef PE_11_SPEED
#define    PE_11_SPEED    SPEED_HIGH
#endif

#ifndef PE_11_OUTPUT
#define    PE_11_OUTPUT    PUSH_PULL
#endif

#ifndef PE_11_PULL_TYPE
#define    PE_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PE_12_MODE
#define    PE_12_MODE    NOT_USED
#endif

#ifndef PE_12_SPEED
#define    PE_12_SPEED    SPEED_HIGH
#endif

#ifndef PE_12_OUTPUT
#define    PE_12_OUTPUT    PUSH_PULL
#endif

#ifndef PE_12_PULL_TYPE
#define    PE_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PE_13_MODE
#define    PE_13_MODE    NOT_USED
#endif

#ifndef PE_13_SPEED
#define    PE_13_SPEED    SPEED_HIGH
#endif

#ifndef PE_13_OUTPUT
#define    PE_13_OUTPUT    PUSH_PULL
#endif

#ifndef PE_13_PULL_TYPE
#define    PE_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PE_14_MODE
#define    PE_14_MODE    NOT_USED
#endif

#ifndef PE_14_SPEED
#define    PE_14_SPEED    SPEED_HIGH
#endif

#ifndef PE_14_OUTPUT
#define    PE_14_OUTPUT    PUSH_PULL
#endif

#ifndef PE_14_PULL_TYPE
#define    PE_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PE_15_MODE
#define    PE_15_MODE    NOT_USED
#endif

#ifndef PE_15_SPEED
#define    PE_15_SPEED    SPEED_HIGH
#endif

#ifndef PE_15_OUTPUT
#define    PE_15_OUTPUT    PUSH_PULL
#endif

#ifndef PE_15_PULL_TYPE
#define    PE_15_PULL_TYPE    NO_PULL
#endif


/* PORT F */

#define PA_0_PIN    IO_PIN_0

#ifndef PF_0_MODE
#define    PF_0_MODE    NOT_USED
#endif

#ifndef PF_0_SPEED
#define    PF_0_SPEED    SPEED_HIGH
#endif

#ifndef PF_0_OUTPUT
#define    PF_0_OUTPUT    PUSH_PULL
#endif

#ifndef PF_0_PULL_TYPE
#define    PF_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PF_1_MODE
#define    PF_1_MODE    NOT_USED
#endif

#ifndef PF_1_SPEED
#define    PF_1_SPEED    SPEED_HIGH
#endif

#ifndef PF_1_OUTPUT
#define    PF_1_OUTPUT    PUSH_PULL
#endif

#ifndef PF_1_PULL_TYPE
#define    PF_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PF_2_MODE
#define    PF_2_MODE    NOT_USED
#endif

#ifndef PF_2_SPEED
#define    PF_2_SPEED    SPEED_HIGH
#endif

#ifndef PF_2_OUTPUT
#define    PF_2_OUTPUT    PUSH_PULL
#endif

#ifndef PF_2_PULL_TYPE
#define    PF_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PF_3_MODE
#define    PF_3_MODE    NOT_USED
#endif

#ifndef PF_3_SPEED
#define    PF_3_SPEED    SPEED_HIGH
#endif

#ifndef PF_3_OUTPUT
#define    PF_3_OUTPUT    PUSH_PULL
#endif

#ifndef PF_3_PULL_TYPE
#define    PF_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PF_4_MODE
#define    PF_4_MODE    NOT_USED
#endif

#ifndef PF_4_SPEED
#define    PF_4_SPEED    SPEED_HIGH
#endif

#ifndef PF_4_OUTPUT
#define    PF_4_OUTPUT    PUSH_PULL
#endif

#ifndef PF_4_PULL_TYPE
#define    PF_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PF_5_MODE
#define    PF_5_MODE    NOT_USED
#endif

#ifndef PF_5_SPEED
#define    PF_5_SPEED    SPEED_HIGH
#endif

#ifndef PF_5_OUTPUT
#define    PF_5_OUTPUT    PUSH_PULL
#endif

#ifndef PF_5_PULL_TYPE
#define    PF_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PF_6_MODE
#define    PF_6_MODE    NOT_USED
#endif

#ifndef PF_6_SPEED
#define    PF_6_SPEED    SPEED_HIGH
#endif

#ifndef PF_6_OUTPUT
#define    PF_6_OUTPUT    PUSH_PULL
#endif

#ifndef PF_6_PULL_TYPE
#define    PF_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PF_7_MODE
#define    PF_7_MODE    NOT_USED
#endif

#ifndef PF_7_SPEED
#define    PF_7_SPEED    SPEED_HIGH
#endif

#ifndef PF_7_OUTPUT
#define    PF_7_OUTPUT    PUSH_PULL
#endif

#ifndef PF_7_PULL_TYPE
#define    PF_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PF_8_MODE
#define    PF_8_MODE    NOT_USED
#endif

#ifndef PF_8_SPEED
#define    PF_8_SPEED    SPEED_HIGH
#endif

#ifndef PF_8_OUTPUT
#define    PF_8_OUTPUT    PUSH_PULL
#endif

#ifndef PF_8_PULL_TYPE
#define    PF_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PF_9_MODE
#define    PF_9_MODE    NOT_USED
#endif

#ifndef PF_9_SPEED
#define    PF_9_SPEED    SPEED_HIGH
#endif

#ifndef PF_9_OUTPUT
#define    PF_9_OUTPUT    PUSH_PULL
#endif

#ifndef PF_9_PULL_TYPE
#define    PF_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PF_10_MODE
#define    PF_10_MODE    NOT_USED
#endif

#ifndef PF_10_SPEED
#define    PF_10_SPEED    SPEED_HIGH
#endif

#ifndef PF_10_OUTPUT
#define    PF_10_OUTPUT    PUSH_PULL
#endif

#ifndef PF_10_PULL_TYPE
#define    PF_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PF_11_MODE
#define    PF_11_MODE    NOT_USED
#endif

#ifndef PF_11_SPEED
#define    PF_11_SPEED    SPEED_HIGH
#endif

#ifndef PF_11_OUTPUT
#define    PF_11_OUTPUT    PUSH_PULL
#endif

#ifndef PF_11_PULL_TYPE
#define    PF_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PF_12_MODE
#define    PF_12_MODE    NOT_USED
#endif

#ifndef PF_12_SPEED
#define    PF_12_SPEED    SPEED_HIGH
#endif

#ifndef PF_12_OUTPUT
#define    PF_12_OUTPUT    PUSH_PULL
#endif

#ifndef PF_12_PULL_TYPE
#define    PF_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PF_13_MODE
#define    PF_13_MODE    NOT_USED
#endif

#ifndef PF_13_SPEED
#define    PF_13_SPEED    SPEED_HIGH
#endif

#ifndef PF_13_OUTPUT
#define    PF_13_OUTPUT    PUSH_PULL
#endif

#ifndef PF_13_PULL_TYPE
#define    PF_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PF_14_MODE
#define    PF_14_MODE    NOT_USED
#endif

#ifndef PF_14_SPEED
#define    PF_14_SPEED    SPEED_HIGH
#endif

#ifndef PF_14_OUTPUT
#define    PF_14_OUTPUT    PUSH_PULL
#endif

#ifndef PF_14_PULL_TYPE
#define    PF_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PF_15_MODE
#define    PF_15_MODE    NOT_USED
#endif

#ifndef PF_15_SPEED
#define    PF_15_SPEED    SPEED_HIGH
#endif

#ifndef PF_15_OUTPUT
#define    PF_15_OUTPUT    PUSH_PULL
#endif

#ifndef PF_15_PULL_TYPE
#define    PF_15_PULL_TYPE    NO_PULL
#endif


/* PORT G */

#define PA_0_PIN    IO_PIN_0

#ifndef PG_0_MODE
#define    PG_0_MODE    NOT_USED
#endif

#ifndef PG_0_SPEED
#define    PG_0_SPEED    SPEED_HIGH
#endif

#ifndef PG_0_OUTPUT
#define    PG_0_OUTPUT    PUSH_PULL
#endif

#ifndef PG_0_PULL_TYPE
#define    PG_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PG_1_MODE
#define    PG_1_MODE    NOT_USED
#endif

#ifndef PG_1_SPEED
#define    PG_1_SPEED    SPEED_HIGH
#endif

#ifndef PG_1_OUTPUT
#define    PG_1_OUTPUT    PUSH_PULL
#endif

#ifndef PG_1_PULL_TYPE
#define    PG_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PG_2_MODE
#define    PG_2_MODE    NOT_USED
#endif

#ifndef PG_2_SPEED
#define    PG_2_SPEED    SPEED_HIGH
#endif

#ifndef PG_2_OUTPUT
#define    PG_2_OUTPUT    PUSH_PULL
#endif

#ifndef PG_2_PULL_TYPE
#define    PG_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PG_3_MODE
#define    PG_3_MODE    NOT_USED
#endif

#ifndef PG_3_SPEED
#define    PG_3_SPEED    SPEED_HIGH
#endif

#ifndef PG_3_OUTPUT
#define    PG_3_OUTPUT    PUSH_PULL
#endif

#ifndef PG_3_PULL_TYPE
#define    PG_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PG_4_MODE
#define    PG_4_MODE    NOT_USED
#endif

#ifndef PG_4_SPEED
#define    PG_4_SPEED    SPEED_HIGH
#endif

#ifndef PG_4_OUTPUT
#define    PG_4_OUTPUT    PUSH_PULL
#endif

#ifndef PG_4_PULL_TYPE
#define    PG_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PG_5_MODE
#define    PG_5_MODE    NOT_USED
#endif

#ifndef PG_5_SPEED
#define    PG_5_SPEED    SPEED_HIGH
#endif

#ifndef PG_5_OUTPUT
#define    PG_5_OUTPUT    PUSH_PULL
#endif

#ifndef PG_5_PULL_TYPE
#define    PG_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PG_6_MODE
#define    PG_6_MODE    NOT_USED
#endif

#ifndef PG_6_SPEED
#define    PG_6_SPEED    SPEED_HIGH
#endif

#ifndef PG_6_OUTPUT
#define    PG_6_OUTPUT    PUSH_PULL
#endif

#ifndef PG_6_PULL_TYPE
#define    PG_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PG_7_MODE
#define    PG_7_MODE    NOT_USED
#endif

#ifndef PG_7_SPEED
#define    PG_7_SPEED    SPEED_HIGH
#endif

#ifndef PG_7_OUTPUT
#define    PG_7_OUTPUT    PUSH_PULL
#endif

#ifndef PG_7_PULL_TYPE
#define    PG_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PG_8_MODE
#define    PG_8_MODE    NOT_USED
#endif

#ifndef PG_8_SPEED
#define    PG_8_SPEED    SPEED_HIGH
#endif

#ifndef PG_8_OUTPUT
#define    PG_8_OUTPUT    PUSH_PULL
#endif

#ifndef PG_8_PULL_TYPE
#define    PG_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PG_9_MODE
#define    PG_9_MODE    NOT_USED
#endif

#ifndef PG_9_SPEED
#define    PG_9_SPEED    SPEED_HIGH
#endif

#ifndef PG_9_OUTPUT
#define    PG_9_OUTPUT    PUSH_PULL
#endif

#ifndef PG_9_PULL_TYPE
#define    PG_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PG_10_MODE
#define    PG_10_MODE    NOT_USED
#endif

#ifndef PG_10_SPEED
#define    PG_10_SPEED    SPEED_HIGH
#endif

#ifndef PG_10_OUTPUT
#define    PG_10_OUTPUT    PUSH_PULL
#endif

#ifndef PG_10_PULL_TYPE
#define    PG_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PG_11_MODE
#define    PG_11_MODE    NOT_USED
#endif

#ifndef PG_11_SPEED
#define    PG_11_SPEED    SPEED_HIGH
#endif

#ifndef PG_11_OUTPUT
#define    PG_11_OUTPUT    PUSH_PULL
#endif

#ifndef PG_11_PULL_TYPE
#define    PG_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PG_12_MODE
#define    PG_12_MODE    NOT_USED
#endif

#ifndef PG_12_SPEED
#define    PG_12_SPEED    SPEED_HIGH
#endif

#ifndef PG_12_OUTPUT
#define    PG_12_OUTPUT    PUSH_PULL
#endif

#ifndef PG_12_PULL_TYPE
#define    PG_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PG_13_MODE
#define    PG_13_MODE    NOT_USED
#endif

#ifndef PG_13_SPEED
#define    PG_13_SPEED    SPEED_HIGH
#endif

#ifndef PG_13_OUTPUT
#define    PG_13_OUTPUT    PUSH_PULL
#endif

#ifndef PG_13_PULL_TYPE
#define    PG_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PG_14_MODE
#define    PG_14_MODE    NOT_USED
#endif

#ifndef PG_14_SPEED
#define    PG_14_SPEED    SPEED_HIGH
#endif

#ifndef PG_14_OUTPUT
#define    PG_14_OUTPUT    PUSH_PULL
#endif

#ifndef PG_14_PULL_TYPE
#define    PG_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PG_15_MODE
#define    PG_15_MODE    NOT_USED
#endif

#ifndef PG_15_SPEED
#define    PG_15_SPEED    SPEED_HIGH
#endif

#ifndef PG_15_OUTPUT
#define    PG_15_OUTPUT    PUSH_PULL
#endif

#ifndef PG_15_PULL_TYPE
#define    PG_15_PULL_TYPE    NO_PULL
#endif


/* PORT H */

#define PA_0_PIN    IO_PIN_0

#ifndef PH_0_MODE
#define    PH_0_MODE    NOT_USED
#endif

#ifndef PH_0_SPEED
#define    PH_0_SPEED    SPEED_HIGH
#endif

#ifndef PH_0_OUTPUT
#define    PH_0_OUTPUT    PUSH_PULL
#endif

#ifndef PH_0_PULL_TYPE
#define    PH_0_PULL_TYPE    NO_PULL
#endif

#define PA_1_PIN    IO_PIN_1

#ifndef PH_1_MODE
#define    PH_1_MODE    NOT_USED
#endif

#ifndef PH_1_SPEED
#define    PH_1_SPEED    SPEED_HIGH
#endif

#ifndef PH_1_OUTPUT
#define    PH_1_OUTPUT    PUSH_PULL
#endif

#ifndef PH_1_PULL_TYPE
#define    PH_1_PULL_TYPE    NO_PULL
#endif

#define PA_2_PIN    IO_PIN_2

#ifndef PH_2_MODE
#define    PH_2_MODE    NOT_USED
#endif

#ifndef PH_2_SPEED
#define    PH_2_SPEED    SPEED_HIGH
#endif

#ifndef PH_2_OUTPUT
#define    PH_2_OUTPUT    PUSH_PULL
#endif

#ifndef PH_2_PULL_TYPE
#define    PH_2_PULL_TYPE    NO_PULL
#endif

#define PA_3_PIN    IO_PIN_3

#ifndef PH_3_MODE
#define    PH_3_MODE    NOT_USED
#endif

#ifndef PH_3_SPEED
#define    PH_3_SPEED    SPEED_HIGH
#endif

#ifndef PH_3_OUTPUT
#define    PH_3_OUTPUT    PUSH_PULL
#endif

#ifndef PH_3_PULL_TYPE
#define    PH_3_PULL_TYPE    NO_PULL
#endif

#define PA_4_PIN    IO_PIN_4

#ifndef PH_4_MODE
#define    PH_4_MODE    NOT_USED
#endif

#ifndef PH_4_SPEED
#define    PH_4_SPEED    SPEED_HIGH
#endif

#ifndef PH_4_OUTPUT
#define    PH_4_OUTPUT    PUSH_PULL
#endif

#ifndef PH_4_PULL_TYPE
#define    PH_4_PULL_TYPE    NO_PULL
#endif

#define PA_5_PIN    IO_PIN_5

#ifndef PH_5_MODE
#define    PH_5_MODE    NOT_USED
#endif

#ifndef PH_5_SPEED
#define    PH_5_SPEED    SPEED_HIGH
#endif

#ifndef PH_5_OUTPUT
#define    PH_5_OUTPUT    PUSH_PULL
#endif

#ifndef PH_5_PULL_TYPE
#define    PH_5_PULL_TYPE    NO_PULL
#endif

#define PA_6_PIN    IO_PIN_6

#ifndef PH_6_MODE
#define    PH_6_MODE    NOT_USED
#endif

#ifndef PH_6_SPEED
#define    PH_6_SPEED    SPEED_HIGH
#endif

#ifndef PH_6_OUTPUT
#define    PH_6_OUTPUT    PUSH_PULL
#endif

#ifndef PH_6_PULL_TYPE
#define    PH_6_PULL_TYPE    NO_PULL
#endif

#define PA_7_PIN    IO_PIN_7

#ifndef PH_7_MODE
#define    PH_7_MODE    NOT_USED
#endif

#ifndef PH_7_SPEED
#define    PH_7_SPEED    SPEED_HIGH
#endif

#ifndef PH_7_OUTPUT
#define    PH_7_OUTPUT    PUSH_PULL
#endif

#ifndef PH_7_PULL_TYPE
#define    PH_7_PULL_TYPE    NO_PULL
#endif

#define PA_8_PIN    IO_PIN_8

#ifndef PH_8_MODE
#define    PH_8_MODE    NOT_USED
#endif

#ifndef PH_8_SPEED
#define    PH_8_SPEED    SPEED_HIGH
#endif

#ifndef PH_8_OUTPUT
#define    PH_8_OUTPUT    PUSH_PULL
#endif

#ifndef PH_8_PULL_TYPE
#define    PH_8_PULL_TYPE    NO_PULL
#endif

#define PA_9_PIN    IO_PIN_9

#ifndef PH_9_MODE
#define    PH_9_MODE    NOT_USED
#endif

#ifndef PH_9_SPEED
#define    PH_9_SPEED    SPEED_HIGH
#endif

#ifndef PH_9_OUTPUT
#define    PH_9_OUTPUT    PUSH_PULL
#endif

#ifndef PH_9_PULL_TYPE
#define    PH_9_PULL_TYPE    NO_PULL
#endif

#define PA_10_PIN    IO_PIN_10

#ifndef PH_10_MODE
#define    PH_10_MODE    NOT_USED
#endif

#ifndef PH_10_SPEED
#define    PH_10_SPEED    SPEED_HIGH
#endif

#ifndef PH_10_OUTPUT
#define    PH_10_OUTPUT    PUSH_PULL
#endif

#ifndef PH_10_PULL_TYPE
#define    PH_10_PULL_TYPE    NO_PULL
#endif

#define PA_11_PIN    IO_PIN_11

#ifndef PH_11_MODE
#define    PH_11_MODE    NOT_USED
#endif

#ifndef PH_11_SPEED
#define    PH_11_SPEED    SPEED_HIGH
#endif

#ifndef PH_11_OUTPUT
#define    PH_11_OUTPUT    PUSH_PULL
#endif

#ifndef PH_11_PULL_TYPE
#define    PH_11_PULL_TYPE    NO_PULL
#endif

#define PA_12_PIN    IO_PIN_12

#ifndef PH_12_MODE
#define    PH_12_MODE    NOT_USED
#endif

#ifndef PH_12_SPEED
#define    PH_12_SPEED    SPEED_HIGH
#endif

#ifndef PH_12_OUTPUT
#define    PH_12_OUTPUT    PUSH_PULL
#endif

#ifndef PH_12_PULL_TYPE
#define    PH_12_PULL_TYPE    NO_PULL
#endif

#define PA_13_PIN    IO_PIN_13

#ifndef PH_13_MODE
#define    PH_13_MODE    NOT_USED
#endif

#ifndef PH_13_SPEED
#define    PH_13_SPEED    SPEED_HIGH
#endif

#ifndef PH_13_OUTPUT
#define    PH_13_OUTPUT    PUSH_PULL
#endif

#ifndef PH_13_PULL_TYPE
#define    PH_13_PULL_TYPE    NO_PULL
#endif

#define PA_14_PIN    IO_PIN_14

#ifndef PH_14_MODE
#define    PH_14_MODE    NOT_USED
#endif

#ifndef PH_14_SPEED
#define    PH_14_SPEED    SPEED_HIGH
#endif

#ifndef PH_14_OUTPUT
#define    PH_14_OUTPUT    PUSH_PULL
#endif

#ifndef PH_14_PULL_TYPE
#define    PH_14_PULL_TYPE    NO_PULL
#endif

#define PA_15_PIN    IO_PIN_15

#ifndef PH_15_MODE
#define    PH_15_MODE    NOT_USED
#endif

#ifndef PH_15_SPEED
#define    PH_15_SPEED    SPEED_HIGH
#endif

#ifndef PH_15_OUTPUT
#define    PH_15_OUTPUT    PUSH_PULL
#endif

#ifndef PH_15_PULL_TYPE
#define    PH_15_PULL_TYPE    NO_PULL
#endif


#endif