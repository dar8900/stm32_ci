#ifndef GPIO_DEFS_H
#define GPIO_DEFS_H

#include "hmt_common.h"

#define N_PORT           8 /* A B C D E F G H */
#define N_PIN_X_PORT    16
#define MAX_GPIO        (N_PORT * N_PIN_X_PORT)

#define ADD_GPIO_TO_TAB(port, pin)      {GPIO##port, P##port##_##pin##_PIN, \
                                        P##port##_##pin##_MODE, P##port##_##pin##_SPEED,\
                                        P##port##_##pin##_OUTPUT, P##port##_##pin##_PULL_TYPE, P##port##_##pin##_AF_TYPE, \
                                        P##port##_##pin##_ACTIVE_LEVEL, P##port##_##pin##_START_LEVEL}

#define P(port)      GPIO##port


typedef enum gpio_mode
{
    NOT_USED = 0,
    FLOATING = LL_GPIO_MODE_FLOATING,
    INPUT = LL_GPIO_MODE_INPUT,
    OUTPUT = LL_GPIO_MODE_OUTPUT,
    ANALOG = LL_GPIO_MODE_ANALOG,
    ALTERNATE = LL_GPIO_MODE_ALTERNATE
}gpio_mode;

typedef enum gpio_output
{
    PUSH_PULL = LL_GPIO_OUTPUT_PUSHPULL,
    OPEN_DRAIN = LL_GPIO_OUTPUT_OPENDRAIN
}gpio_output;

typedef enum gpio_input
{
    NO_PULL = LL_GPIO_PULL_NO,
    PULL_UP = LL_GPIO_PULL_UP,
    PULL_DOWN = LL_GPIO_PULL_DOWN
}gpio_input;

typedef enum gpio_speed
{
    SPEED_LOW = LL_GPIO_SPEED_FREQ_LOW,       
    SPEED_MED = LL_GPIO_SPEED_FREQ_MEDIUM,    
    SPEED_HIGH = LL_GPIO_SPEED_FREQ_HIGH,      
    SPEED_V_HIGH = LL_GPIO_SPEED_FREQ_VERY_HIGH 
}gpio_speed;

typedef enum gpio_value
{
    LOW = GPIO_PIN_RESET,
    HIGH = GPIO_PIN_SET
}gpio_value;


typedef enum gpio_af
{
    AF_NOT_USED = 0,
    AF_0,
    AF_1,
    AF_2,
    AF_3,
    AF_4,
    AF_5,
    AF_6,
    AF_7,
    AF_8,
    AF_9,
    AF_10,
    AF_11,
    AF_12,
    AF_13,
    AF_14,
    AF_15
}gpio_af;

typedef enum gpio_pin
{
    IO_PIN_0   =  LL_GPIO_PIN_0,
    IO_PIN_1   =  LL_GPIO_PIN_1,
    IO_PIN_2   =  LL_GPIO_PIN_2,
    IO_PIN_3   =  LL_GPIO_PIN_3,
    IO_PIN_4   =  LL_GPIO_PIN_4,
    IO_PIN_5   =  LL_GPIO_PIN_5,
    IO_PIN_6   =  LL_GPIO_PIN_6,
    IO_PIN_7   =  LL_GPIO_PIN_7,
    IO_PIN_8   =  LL_GPIO_PIN_8,
    IO_PIN_9   =  LL_GPIO_PIN_9,
    IO_PIN_10  =  LL_GPIO_PIN_10,
    IO_PIN_11  =  LL_GPIO_PIN_11,
    IO_PIN_12  =  LL_GPIO_PIN_12,
    IO_PIN_13  =  LL_GPIO_PIN_13,
    IO_PIN_14  =  LL_GPIO_PIN_14,
    IO_PIN_15  =  LL_GPIO_PIN_15,
    IO_MAX_PIN = 17
}gpio_pin;

typedef struct 
{
    GPIO_TypeDef            *port;
    uint32_t                pin;         
    uint32_t                mode;        
    uint32_t                speed;       
    uint32_t                outputType;  
    uint32_t                pull;
    gpio_af                 alternate;
    gpio_value              activeLevel;
    gpio_value              startVal;
}gpio_def;

typedef struct 
{
    gpio_value              activeLevel;                 
    gpio_value              actualVal;
    gpio_value              oldVal;
}gpio_val_s;

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

#define PB_0_PIN    IO_PIN_0

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

#define PB_1_PIN    IO_PIN_1

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

#define PB_2_PIN    IO_PIN_2

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

#define PB_3_PIN    IO_PIN_3

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

#define PB_4_PIN    IO_PIN_4

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

#define PB_5_PIN    IO_PIN_5

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

#define PB_6_PIN    IO_PIN_6

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

#define PB_7_PIN    IO_PIN_7

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

#define PB_8_PIN    IO_PIN_8

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

#define PB_9_PIN    IO_PIN_9

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

#define PB_10_PIN    IO_PIN_10

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

#define PB_11_PIN    IO_PIN_11

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

#define PB_12_PIN    IO_PIN_12

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

#define PB_13_PIN    IO_PIN_13

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

#define PB_14_PIN    IO_PIN_14

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

#define PB_15_PIN    IO_PIN_15

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

#define PC_0_PIN    IO_PIN_0

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

#define PC_1_PIN    IO_PIN_1

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

#define PC_2_PIN    IO_PIN_2

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

#define PC_3_PIN    IO_PIN_3

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

#define PC_4_PIN    IO_PIN_4

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

#define PC_5_PIN    IO_PIN_5

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

#define PC_6_PIN    IO_PIN_6

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

#define PC_7_PIN    IO_PIN_7

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

#define PC_8_PIN    IO_PIN_8

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

#define PC_9_PIN    IO_PIN_9

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

#define PC_10_PIN    IO_PIN_10

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

#define PC_11_PIN    IO_PIN_11

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

#define PC_12_PIN    IO_PIN_12

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

#define PC_13_PIN    IO_PIN_13

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

#define PC_14_PIN    IO_PIN_14

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

#define PC_15_PIN    IO_PIN_15

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

#define PD_0_PIN    IO_PIN_0

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

#define PD_1_PIN    IO_PIN_1

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

#define PD_2_PIN    IO_PIN_2

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

#define PD_3_PIN    IO_PIN_3

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

#define PD_4_PIN    IO_PIN_4

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

#define PD_5_PIN    IO_PIN_5

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

#define PD_6_PIN    IO_PIN_6

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

#define PD_7_PIN    IO_PIN_7

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

#define PD_8_PIN    IO_PIN_8

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

#define PD_9_PIN    IO_PIN_9

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

#define PD_10_PIN    IO_PIN_10

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

#define PD_11_PIN    IO_PIN_11

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

#define PD_12_PIN    IO_PIN_12

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

#define PD_13_PIN    IO_PIN_13

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

#define PD_14_PIN    IO_PIN_14

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

#define PD_15_PIN    IO_PIN_15

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

#define PE_0_PIN    IO_PIN_0

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

#define PE_1_PIN    IO_PIN_1

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

#define PE_2_PIN    IO_PIN_2

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

#define PE_3_PIN    IO_PIN_3

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

#define PE_4_PIN    IO_PIN_4

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

#define PE_5_PIN    IO_PIN_5

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

#define PE_6_PIN    IO_PIN_6

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

#define PE_7_PIN    IO_PIN_7

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

#define PE_8_PIN    IO_PIN_8

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

#define PE_9_PIN    IO_PIN_9

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

#define PE_10_PIN    IO_PIN_10

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

#define PE_11_PIN    IO_PIN_11

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

#define PE_12_PIN    IO_PIN_12

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

#define PE_13_PIN    IO_PIN_13

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

#define PE_14_PIN    IO_PIN_14

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

#define PE_15_PIN    IO_PIN_15

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

#define PF_0_PIN    IO_PIN_0

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

#define PF_1_PIN    IO_PIN_1

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

#define PF_2_PIN    IO_PIN_2

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

#define PF_3_PIN    IO_PIN_3

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

#define PF_4_PIN    IO_PIN_4

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

#define PF_5_PIN    IO_PIN_5

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

#define PF_6_PIN    IO_PIN_6

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

#define PF_7_PIN    IO_PIN_7

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

#define PF_8_PIN    IO_PIN_8

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

#define PF_9_PIN    IO_PIN_9

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

#define PF_10_PIN    IO_PIN_10

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

#define PF_11_PIN    IO_PIN_11

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

#define PF_12_PIN    IO_PIN_12

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

#define PF_13_PIN    IO_PIN_13

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

#define PF_14_PIN    IO_PIN_14

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

#define PF_15_PIN    IO_PIN_15

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

#define PG_0_PIN    IO_PIN_0

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

#define PG_1_PIN    IO_PIN_1

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

#define PG_2_PIN    IO_PIN_2

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

#define PG_3_PIN    IO_PIN_3

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

#define PG_4_PIN    IO_PIN_4

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

#define PG_5_PIN    IO_PIN_5

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

#define PG_6_PIN    IO_PIN_6

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

#define PG_7_PIN    IO_PIN_7

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

#define PG_8_PIN    IO_PIN_8

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

#define PG_9_PIN    IO_PIN_9

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

#define PG_10_PIN    IO_PIN_10

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

#define PG_11_PIN    IO_PIN_11

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

#define PG_12_PIN    IO_PIN_12

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

#define PG_13_PIN    IO_PIN_13

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

#define PG_14_PIN    IO_PIN_14

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

#define PG_15_PIN    IO_PIN_15

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

#define PH_0_PIN    IO_PIN_0

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

#define PH_1_PIN    IO_PIN_1

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

#define PH_2_PIN    IO_PIN_2

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

#define PH_3_PIN    IO_PIN_3

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

#define PH_4_PIN    IO_PIN_4

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

#define PH_5_PIN    IO_PIN_5

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

#define PH_6_PIN    IO_PIN_6

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

#define PH_7_PIN    IO_PIN_7

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

#define PH_8_PIN    IO_PIN_8

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

#define PH_9_PIN    IO_PIN_9

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

#define PH_10_PIN    IO_PIN_10

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

#define PH_11_PIN    IO_PIN_11

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

#define PH_12_PIN    IO_PIN_12

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

#define PH_13_PIN    IO_PIN_13

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

#define PH_14_PIN    IO_PIN_14

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

#define PH_15_PIN    IO_PIN_15

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

/* ALTERNATE DEFINITIONS */

/* PORT A */
#ifndef PA_0_AF_TYPE
#define    PA_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_1_AF_TYPE
#define    PA_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_2_AF_TYPE
#define    PA_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_3_AF_TYPE
#define    PA_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_4_AF_TYPE
#define    PA_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_5_AF_TYPE
#define    PA_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_6_AF_TYPE
#define    PA_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_7_AF_TYPE
#define    PA_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_8_AF_TYPE
#define    PA_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_9_AF_TYPE
#define    PA_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_10_AF_TYPE
#define    PA_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_11_AF_TYPE
#define    PA_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_12_AF_TYPE
#define    PA_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_13_AF_TYPE
#define    PA_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_14_AF_TYPE
#define    PA_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PA_15_AF_TYPE
#define    PA_15_AF_TYPE    AF_NOT_USED
#endif

/* PORT B */
#ifndef PB_0_AF_TYPE
#define    PB_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_1_AF_TYPE
#define    PB_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_2_AF_TYPE
#define    PB_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_3_AF_TYPE
#define    PB_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_4_AF_TYPE
#define    PB_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_5_AF_TYPE
#define    PB_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_6_AF_TYPE
#define    PB_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_7_AF_TYPE
#define    PB_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_8_AF_TYPE
#define    PB_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_9_AF_TYPE
#define    PB_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_10_AF_TYPE
#define    PB_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_11_AF_TYPE
#define    PB_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_12_AF_TYPE
#define    PB_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_13_AF_TYPE
#define    PB_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_14_AF_TYPE
#define    PB_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PB_15_AF_TYPE
#define    PB_15_AF_TYPE    AF_NOT_USED
#endif

/* PORT C */
#ifndef PC_0_AF_TYPE
#define    PC_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_1_AF_TYPE
#define    PC_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_2_AF_TYPE
#define    PC_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_3_AF_TYPE
#define    PC_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_4_AF_TYPE
#define    PC_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_5_AF_TYPE
#define    PC_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_6_AF_TYPE
#define    PC_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_7_AF_TYPE
#define    PC_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_8_AF_TYPE
#define    PC_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_9_AF_TYPE
#define    PC_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_10_AF_TYPE
#define    PC_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_11_AF_TYPE
#define    PC_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_12_AF_TYPE
#define    PC_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_13_AF_TYPE
#define    PC_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_14_AF_TYPE
#define    PC_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PC_15_AF_TYPE
#define    PC_15_AF_TYPE    AF_NOT_USED
#endif

/* PORT D */
#ifndef PD_0_AF_TYPE
#define    PD_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_1_AF_TYPE
#define    PD_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_2_AF_TYPE
#define    PD_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_3_AF_TYPE
#define    PD_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_4_AF_TYPE
#define    PD_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_5_AF_TYPE
#define    PD_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_6_AF_TYPE
#define    PD_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_7_AF_TYPE
#define    PD_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_8_AF_TYPE
#define    PD_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_9_AF_TYPE
#define    PD_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_10_AF_TYPE
#define    PD_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_11_AF_TYPE
#define    PD_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_12_AF_TYPE
#define    PD_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_13_AF_TYPE
#define    PD_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_14_AF_TYPE
#define    PD_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PD_15_AF_TYPE
#define    PD_15_AF_TYPE    AF_NOT_USED
#endif


/* PORT E */
#ifndef PE_0_AF_TYPE
#define    PE_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_1_AF_TYPE
#define    PE_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_2_AF_TYPE
#define    PE_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_3_AF_TYPE
#define    PE_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_4_AF_TYPE
#define    PE_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_5_AF_TYPE
#define    PE_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_6_AF_TYPE
#define    PE_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_7_AF_TYPE
#define    PE_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_8_AF_TYPE
#define    PE_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_9_AF_TYPE
#define    PE_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_10_AF_TYPE
#define    PE_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_11_AF_TYPE
#define    PE_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_12_AF_TYPE
#define    PE_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_13_AF_TYPE
#define    PE_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_14_AF_TYPE
#define    PE_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PE_15_AF_TYPE
#define    PE_15_AF_TYPE    AF_NOT_USED
#endif


/* PORT F */
#ifndef PF_0_AF_TYPE
#define    PF_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_1_AF_TYPE
#define    PF_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_2_AF_TYPE
#define    PF_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_3_AF_TYPE
#define    PF_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_4_AF_TYPE
#define    PF_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_5_AF_TYPE
#define    PF_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_6_AF_TYPE
#define    PF_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_7_AF_TYPE
#define    PF_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_8_AF_TYPE
#define    PF_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_9_AF_TYPE
#define    PF_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_10_AF_TYPE
#define    PF_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_11_AF_TYPE
#define    PF_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_12_AF_TYPE
#define    PF_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_13_AF_TYPE
#define    PF_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_14_AF_TYPE
#define    PF_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PF_15_AF_TYPE
#define    PF_15_AF_TYPE    AF_NOT_USED
#endif


/* PORT G */
#ifndef PG_0_AF_TYPE
#define    PG_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_1_AF_TYPE
#define    PG_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_2_AF_TYPE
#define    PG_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_3_AF_TYPE
#define    PG_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_4_AF_TYPE
#define    PG_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_5_AF_TYPE
#define    PG_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_6_AF_TYPE
#define    PG_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_7_AF_TYPE
#define    PG_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_8_AF_TYPE
#define    PG_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_9_AF_TYPE
#define    PG_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_10_AF_TYPE
#define    PG_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_11_AF_TYPE
#define    PG_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_12_AF_TYPE
#define    PG_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_13_AF_TYPE
#define    PG_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_14_AF_TYPE
#define    PG_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PG_15_AF_TYPE
#define    PG_15_AF_TYPE    AF_NOT_USED
#endif


/* PORT H */
#ifndef PH_0_AF_TYPE
#define    PH_0_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_1_AF_TYPE
#define    PH_1_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_2_AF_TYPE
#define    PH_2_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_3_AF_TYPE
#define    PH_3_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_4_AF_TYPE
#define    PH_4_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_5_AF_TYPE
#define    PH_5_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_6_AF_TYPE
#define    PH_6_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_7_AF_TYPE
#define    PH_7_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_8_AF_TYPE
#define    PH_8_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_9_AF_TYPE
#define    PH_9_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_10_AF_TYPE
#define    PH_10_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_11_AF_TYPE
#define    PH_11_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_12_AF_TYPE
#define    PH_12_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_13_AF_TYPE
#define    PH_13_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_14_AF_TYPE
#define    PH_14_AF_TYPE    AF_NOT_USED
#endif

#ifndef PH_15_AF_TYPE
#define    PH_15_AF_TYPE    AF_NOT_USED
#endif

/* ACTIVE LEVEL */

/* PORT A */
#ifndef PA_0_ACTIVE_LEVEL
#define PA_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_1_ACTIVE_LEVEL
#define PA_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_2_ACTIVE_LEVEL
#define PA_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_3_ACTIVE_LEVEL
#define PA_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_4_ACTIVE_LEVEL
#define PA_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_5_ACTIVE_LEVEL
#define PA_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_6_ACTIVE_LEVEL
#define PA_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_7_ACTIVE_LEVEL
#define PA_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_8_ACTIVE_LEVEL
#define PA_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_9_ACTIVE_LEVEL
#define PA_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_10_ACTIVE_LEVEL
#define PA_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_11_ACTIVE_LEVEL
#define PA_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_12_ACTIVE_LEVEL
#define PA_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_13_ACTIVE_LEVEL
#define PA_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_14_ACTIVE_LEVEL
#define PA_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PA_15_ACTIVE_LEVEL
#define PA_15_ACTIVE_LEVEL HIGH
#endif

/* PORT B */

#ifndef PB_0_ACTIVE_LEVEL
#define PB_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_1_ACTIVE_LEVEL
#define PB_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_2_ACTIVE_LEVEL
#define PB_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_3_ACTIVE_LEVEL
#define PB_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_4_ACTIVE_LEVEL
#define PB_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_5_ACTIVE_LEVEL
#define PB_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_6_ACTIVE_LEVEL
#define PB_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_7_ACTIVE_LEVEL
#define PB_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_8_ACTIVE_LEVEL
#define PB_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_9_ACTIVE_LEVEL
#define PB_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_10_ACTIVE_LEVEL
#define PB_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_11_ACTIVE_LEVEL
#define PB_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_12_ACTIVE_LEVEL
#define PB_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_13_ACTIVE_LEVEL
#define PB_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_14_ACTIVE_LEVEL
#define PB_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PB_15_ACTIVE_LEVEL
#define PB_15_ACTIVE_LEVEL HIGH
#endif

/* PORT C */

#ifndef PC_0_ACTIVE_LEVEL
#define PC_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_1_ACTIVE_LEVEL
#define PC_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_2_ACTIVE_LEVEL
#define PC_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_3_ACTIVE_LEVEL
#define PC_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_4_ACTIVE_LEVEL
#define PC_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_5_ACTIVE_LEVEL
#define PC_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_6_ACTIVE_LEVEL
#define PC_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_7_ACTIVE_LEVEL
#define PC_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_8_ACTIVE_LEVEL
#define PC_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_9_ACTIVE_LEVEL
#define PC_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_10_ACTIVE_LEVEL
#define PC_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_11_ACTIVE_LEVEL
#define PC_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_12_ACTIVE_LEVEL
#define PC_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_13_ACTIVE_LEVEL
#define PC_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_14_ACTIVE_LEVEL
#define PC_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PC_15_ACTIVE_LEVEL
#define PC_15_ACTIVE_LEVEL HIGH
#endif

/* PORT D */

#ifndef PD_0_ACTIVE_LEVEL
#define PD_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_1_ACTIVE_LEVEL
#define PD_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_2_ACTIVE_LEVEL
#define PD_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_3_ACTIVE_LEVEL
#define PD_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_4_ACTIVE_LEVEL
#define PD_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_5_ACTIVE_LEVEL
#define PD_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_6_ACTIVE_LEVEL
#define PD_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_7_ACTIVE_LEVEL
#define PD_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_8_ACTIVE_LEVEL
#define PD_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_9_ACTIVE_LEVEL
#define PD_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_10_ACTIVE_LEVEL
#define PD_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_11_ACTIVE_LEVEL
#define PD_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_12_ACTIVE_LEVEL
#define PD_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_13_ACTIVE_LEVEL
#define PD_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_14_ACTIVE_LEVEL
#define PD_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PD_15_ACTIVE_LEVEL
#define PD_15_ACTIVE_LEVEL HIGH
#endif

/* PORT E */

#ifndef PE_0_ACTIVE_LEVEL
#define PE_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_1_ACTIVE_LEVEL
#define PE_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_2_ACTIVE_LEVEL
#define PE_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_3_ACTIVE_LEVEL
#define PE_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_4_ACTIVE_LEVEL
#define PE_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_5_ACTIVE_LEVEL
#define PE_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_6_ACTIVE_LEVEL
#define PE_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_7_ACTIVE_LEVEL
#define PE_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_8_ACTIVE_LEVEL
#define PE_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_9_ACTIVE_LEVEL
#define PE_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_10_ACTIVE_LEVEL
#define PE_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_11_ACTIVE_LEVEL
#define PE_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_12_ACTIVE_LEVEL
#define PE_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_13_ACTIVE_LEVEL
#define PE_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_14_ACTIVE_LEVEL
#define PE_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PE_15_ACTIVE_LEVEL
#define PE_15_ACTIVE_LEVEL HIGH
#endif

/* PORT F */

#ifndef PF_0_ACTIVE_LEVEL
#define PF_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_1_ACTIVE_LEVEL
#define PF_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_2_ACTIVE_LEVEL
#define PF_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_3_ACTIVE_LEVEL
#define PF_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_4_ACTIVE_LEVEL
#define PF_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_5_ACTIVE_LEVEL
#define PF_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_6_ACTIVE_LEVEL
#define PF_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_7_ACTIVE_LEVEL
#define PF_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_8_ACTIVE_LEVEL
#define PF_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_9_ACTIVE_LEVEL
#define PF_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_10_ACTIVE_LEVEL
#define PF_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_11_ACTIVE_LEVEL
#define PF_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_12_ACTIVE_LEVEL
#define PF_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_13_ACTIVE_LEVEL
#define PF_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_14_ACTIVE_LEVEL
#define PF_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PF_15_ACTIVE_LEVEL
#define PF_15_ACTIVE_LEVEL HIGH
#endif


/* PORT G */

#ifndef PG_0_ACTIVE_LEVEL
#define PG_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_1_ACTIVE_LEVEL
#define PG_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_2_ACTIVE_LEVEL
#define PG_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_3_ACTIVE_LEVEL
#define PG_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_4_ACTIVE_LEVEL
#define PG_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_5_ACTIVE_LEVEL
#define PG_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_6_ACTIVE_LEVEL
#define PG_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_7_ACTIVE_LEVEL
#define PG_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_8_ACTIVE_LEVEL
#define PG_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_9_ACTIVE_LEVEL
#define PG_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_10_ACTIVE_LEVEL
#define PG_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_11_ACTIVE_LEVEL
#define PG_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_12_ACTIVE_LEVEL
#define PG_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_13_ACTIVE_LEVEL
#define PG_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_14_ACTIVE_LEVEL
#define PG_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PG_15_ACTIVE_LEVEL
#define PG_15_ACTIVE_LEVEL HIGH
#endif

/* PORT H */

#ifndef PH_0_ACTIVE_LEVEL
#define PH_0_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_1_ACTIVE_LEVEL
#define PH_1_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_2_ACTIVE_LEVEL
#define PH_2_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_3_ACTIVE_LEVEL
#define PH_3_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_4_ACTIVE_LEVEL
#define PH_4_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_5_ACTIVE_LEVEL
#define PH_5_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_6_ACTIVE_LEVEL
#define PH_6_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_7_ACTIVE_LEVEL
#define PH_7_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_8_ACTIVE_LEVEL
#define PH_8_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_9_ACTIVE_LEVEL
#define PH_9_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_10_ACTIVE_LEVEL
#define PH_10_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_11_ACTIVE_LEVEL
#define PH_11_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_12_ACTIVE_LEVEL
#define PH_12_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_13_ACTIVE_LEVEL
#define PH_13_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_14_ACTIVE_LEVEL
#define PH_14_ACTIVE_LEVEL HIGH
#endif

#ifndef PH_15_ACTIVE_LEVEL
#define PH_15_ACTIVE_LEVEL HIGH
#endif

/* START LEVEL */

/* PORT A */
#ifndef PA_0_START_LEVEL
#define PA_0_START_LEVEL LOW
#endif

#ifndef PA_1_START_LEVEL
#define PA_1_START_LEVEL LOW
#endif

#ifndef PA_2_START_LEVEL
#define PA_2_START_LEVEL LOW
#endif

#ifndef PA_3_START_LEVEL
#define PA_3_START_LEVEL LOW
#endif

#ifndef PA_4_START_LEVEL
#define PA_4_START_LEVEL LOW
#endif

#ifndef PA_5_START_LEVEL
#define PA_5_START_LEVEL LOW
#endif

#ifndef PA_6_START_LEVEL
#define PA_6_START_LEVEL LOW
#endif

#ifndef PA_7_START_LEVEL
#define PA_7_START_LEVEL LOW
#endif

#ifndef PA_8_START_LEVEL
#define PA_8_START_LEVEL LOW
#endif

#ifndef PA_9_START_LEVEL
#define PA_9_START_LEVEL LOW
#endif

#ifndef PA_10_START_LEVEL
#define PA_10_START_LEVEL LOW
#endif

#ifndef PA_11_START_LEVEL
#define PA_11_START_LEVEL LOW
#endif

#ifndef PA_12_START_LEVEL
#define PA_12_START_LEVEL LOW
#endif

#ifndef PA_13_START_LEVEL
#define PA_13_START_LEVEL LOW
#endif

#ifndef PA_14_START_LEVEL
#define PA_14_START_LEVEL LOW
#endif

#ifndef PA_15_START_LEVEL
#define PA_15_START_LEVEL LOW
#endif

/* PORT B */

#ifndef PB_0_START_LEVEL
#define PB_0_START_LEVEL LOW
#endif

#ifndef PB_1_START_LEVEL
#define PB_1_START_LEVEL LOW
#endif

#ifndef PB_2_START_LEVEL
#define PB_2_START_LEVEL LOW
#endif

#ifndef PB_3_START_LEVEL
#define PB_3_START_LEVEL LOW
#endif

#ifndef PB_4_START_LEVEL
#define PB_4_START_LEVEL LOW
#endif

#ifndef PB_5_START_LEVEL
#define PB_5_START_LEVEL LOW
#endif

#ifndef PB_6_START_LEVEL
#define PB_6_START_LEVEL LOW
#endif

#ifndef PB_7_START_LEVEL
#define PB_7_START_LEVEL LOW
#endif

#ifndef PB_8_START_LEVEL
#define PB_8_START_LEVEL LOW
#endif

#ifndef PB_9_START_LEVEL
#define PB_9_START_LEVEL LOW
#endif

#ifndef PB_10_START_LEVEL
#define PB_10_START_LEVEL LOW
#endif

#ifndef PB_11_START_LEVEL
#define PB_11_START_LEVEL LOW
#endif

#ifndef PB_12_START_LEVEL
#define PB_12_START_LEVEL LOW
#endif

#ifndef PB_13_START_LEVEL
#define PB_13_START_LEVEL LOW
#endif

#ifndef PB_14_START_LEVEL
#define PB_14_START_LEVEL LOW
#endif

#ifndef PB_15_START_LEVEL
#define PB_15_START_LEVEL LOW
#endif

/* PORT C */

#ifndef PC_0_START_LEVEL
#define PC_0_START_LEVEL LOW
#endif

#ifndef PC_1_START_LEVEL
#define PC_1_START_LEVEL LOW
#endif

#ifndef PC_2_START_LEVEL
#define PC_2_START_LEVEL LOW
#endif

#ifndef PC_3_START_LEVEL
#define PC_3_START_LEVEL LOW
#endif

#ifndef PC_4_START_LEVEL
#define PC_4_START_LEVEL LOW
#endif

#ifndef PC_5_START_LEVEL
#define PC_5_START_LEVEL LOW
#endif

#ifndef PC_6_START_LEVEL
#define PC_6_START_LEVEL LOW
#endif

#ifndef PC_7_START_LEVEL
#define PC_7_START_LEVEL LOW
#endif

#ifndef PC_8_START_LEVEL
#define PC_8_START_LEVEL LOW
#endif

#ifndef PC_9_START_LEVEL
#define PC_9_START_LEVEL LOW
#endif

#ifndef PC_10_START_LEVEL
#define PC_10_START_LEVEL LOW
#endif

#ifndef PC_11_START_LEVEL
#define PC_11_START_LEVEL LOW
#endif

#ifndef PC_12_START_LEVEL
#define PC_12_START_LEVEL LOW
#endif

#ifndef PC_13_START_LEVEL
#define PC_13_START_LEVEL LOW
#endif

#ifndef PC_14_START_LEVEL
#define PC_14_START_LEVEL LOW
#endif

#ifndef PC_15_START_LEVEL
#define PC_15_START_LEVEL LOW
#endif

/* PORT D */

#ifndef PD_0_START_LEVEL
#define PD_0_START_LEVEL LOW
#endif

#ifndef PD_1_START_LEVEL
#define PD_1_START_LEVEL LOW
#endif

#ifndef PD_2_START_LEVEL
#define PD_2_START_LEVEL LOW
#endif

#ifndef PD_3_START_LEVEL
#define PD_3_START_LEVEL LOW
#endif

#ifndef PD_4_START_LEVEL
#define PD_4_START_LEVEL LOW
#endif

#ifndef PD_5_START_LEVEL
#define PD_5_START_LEVEL LOW
#endif

#ifndef PD_6_START_LEVEL
#define PD_6_START_LEVEL LOW
#endif

#ifndef PD_7_START_LEVEL
#define PD_7_START_LEVEL LOW
#endif

#ifndef PD_8_START_LEVEL
#define PD_8_START_LEVEL LOW
#endif

#ifndef PD_9_START_LEVEL
#define PD_9_START_LEVEL LOW
#endif

#ifndef PD_10_START_LEVEL
#define PD_10_START_LEVEL LOW
#endif

#ifndef PD_11_START_LEVEL
#define PD_11_START_LEVEL LOW
#endif

#ifndef PD_12_START_LEVEL
#define PD_12_START_LEVEL LOW
#endif

#ifndef PD_13_START_LEVEL
#define PD_13_START_LEVEL LOW
#endif

#ifndef PD_14_START_LEVEL
#define PD_14_START_LEVEL LOW
#endif

#ifndef PD_15_START_LEVEL
#define PD_15_START_LEVEL LOW
#endif

/* PORT E */

#ifndef PE_0_START_LEVEL
#define PE_0_START_LEVEL LOW
#endif

#ifndef PE_1_START_LEVEL
#define PE_1_START_LEVEL LOW
#endif

#ifndef PE_2_START_LEVEL
#define PE_2_START_LEVEL LOW
#endif

#ifndef PE_3_START_LEVEL
#define PE_3_START_LEVEL LOW
#endif

#ifndef PE_4_START_LEVEL
#define PE_4_START_LEVEL LOW
#endif

#ifndef PE_5_START_LEVEL
#define PE_5_START_LEVEL LOW
#endif

#ifndef PE_6_START_LEVEL
#define PE_6_START_LEVEL LOW
#endif

#ifndef PE_7_START_LEVEL
#define PE_7_START_LEVEL LOW
#endif

#ifndef PE_8_START_LEVEL
#define PE_8_START_LEVEL LOW
#endif

#ifndef PE_9_START_LEVEL
#define PE_9_START_LEVEL LOW
#endif

#ifndef PE_10_START_LEVEL
#define PE_10_START_LEVEL LOW
#endif

#ifndef PE_11_START_LEVEL
#define PE_11_START_LEVEL LOW
#endif

#ifndef PE_12_START_LEVEL
#define PE_12_START_LEVEL LOW
#endif

#ifndef PE_13_START_LEVEL
#define PE_13_START_LEVEL LOW
#endif

#ifndef PE_14_START_LEVEL
#define PE_14_START_LEVEL LOW
#endif

#ifndef PE_15_START_LEVEL
#define PE_15_START_LEVEL LOW
#endif

/* PORT F */

#ifndef PF_0_START_LEVEL
#define PF_0_START_LEVEL LOW
#endif

#ifndef PF_1_START_LEVEL
#define PF_1_START_LEVEL LOW
#endif

#ifndef PF_2_START_LEVEL
#define PF_2_START_LEVEL LOW
#endif

#ifndef PF_3_START_LEVEL
#define PF_3_START_LEVEL LOW
#endif

#ifndef PF_4_START_LEVEL
#define PF_4_START_LEVEL LOW
#endif

#ifndef PF_5_START_LEVEL
#define PF_5_START_LEVEL LOW
#endif

#ifndef PF_6_START_LEVEL
#define PF_6_START_LEVEL LOW
#endif

#ifndef PF_7_START_LEVEL
#define PF_7_START_LEVEL LOW
#endif

#ifndef PF_8_START_LEVEL
#define PF_8_START_LEVEL LOW
#endif

#ifndef PF_9_START_LEVEL
#define PF_9_START_LEVEL LOW
#endif

#ifndef PF_10_START_LEVEL
#define PF_10_START_LEVEL LOW
#endif

#ifndef PF_11_START_LEVEL
#define PF_11_START_LEVEL LOW
#endif

#ifndef PF_12_START_LEVEL
#define PF_12_START_LEVEL LOW
#endif

#ifndef PF_13_START_LEVEL
#define PF_13_START_LEVEL LOW
#endif

#ifndef PF_14_START_LEVEL
#define PF_14_START_LEVEL LOW
#endif

#ifndef PF_15_START_LEVEL
#define PF_15_START_LEVEL LOW
#endif


/* PORT G */

#ifndef PG_0_START_LEVEL
#define PG_0_START_LEVEL LOW
#endif

#ifndef PG_1_START_LEVEL
#define PG_1_START_LEVEL LOW
#endif

#ifndef PG_2_START_LEVEL
#define PG_2_START_LEVEL LOW
#endif

#ifndef PG_3_START_LEVEL
#define PG_3_START_LEVEL LOW
#endif

#ifndef PG_4_START_LEVEL
#define PG_4_START_LEVEL LOW
#endif

#ifndef PG_5_START_LEVEL
#define PG_5_START_LEVEL LOW
#endif

#ifndef PG_6_START_LEVEL
#define PG_6_START_LEVEL LOW
#endif

#ifndef PG_7_START_LEVEL
#define PG_7_START_LEVEL LOW
#endif

#ifndef PG_8_START_LEVEL
#define PG_8_START_LEVEL LOW
#endif

#ifndef PG_9_START_LEVEL
#define PG_9_START_LEVEL LOW
#endif

#ifndef PG_10_START_LEVEL
#define PG_10_START_LEVEL LOW
#endif

#ifndef PG_11_START_LEVEL
#define PG_11_START_LEVEL LOW
#endif

#ifndef PG_12_START_LEVEL
#define PG_12_START_LEVEL LOW
#endif

#ifndef PG_13_START_LEVEL
#define PG_13_START_LEVEL LOW
#endif

#ifndef PG_14_START_LEVEL
#define PG_14_START_LEVEL LOW
#endif

#ifndef PG_15_START_LEVEL
#define PG_15_START_LEVEL LOW
#endif

/* PORT H */

#ifndef PH_0_START_LEVEL
#define PH_0_START_LEVEL LOW
#endif

#ifndef PH_1_START_LEVEL
#define PH_1_START_LEVEL LOW
#endif

#ifndef PH_2_START_LEVEL
#define PH_2_START_LEVEL LOW
#endif

#ifndef PH_3_START_LEVEL
#define PH_3_START_LEVEL LOW
#endif

#ifndef PH_4_START_LEVEL
#define PH_4_START_LEVEL LOW
#endif

#ifndef PH_5_START_LEVEL
#define PH_5_START_LEVEL LOW
#endif

#ifndef PH_6_START_LEVEL
#define PH_6_START_LEVEL LOW
#endif

#ifndef PH_7_START_LEVEL
#define PH_7_START_LEVEL LOW
#endif

#ifndef PH_8_START_LEVEL
#define PH_8_START_LEVEL LOW
#endif

#ifndef PH_9_START_LEVEL
#define PH_9_START_LEVEL LOW
#endif

#ifndef PH_10_START_LEVEL
#define PH_10_START_LEVEL LOW
#endif

#ifndef PH_11_START_LEVEL
#define PH_11_START_LEVEL LOW
#endif

#ifndef PH_12_START_LEVEL
#define PH_12_START_LEVEL LOW
#endif

#ifndef PH_13_START_LEVEL
#define PH_13_START_LEVEL LOW
#endif

#ifndef PH_14_START_LEVEL
#define PH_14_START_LEVEL LOW
#endif

#ifndef PH_15_START_LEVEL
#define PH_15_START_LEVEL LOW
#endif


/* PIN ID */

#define PA_0_ID             0
#define PA_1_ID             1
#define PA_2_ID             2
#define PA_3_ID             3
#define PA_4_ID             4
#define PA_5_ID             5
#define PA_6_ID             6
#define PA_7_ID             7
#define PA_8_ID             8
#define PA_9_ID             9
#define PA_10_ID           10
#define PA_11_ID           11
#define PA_12_ID           12
#define PA_13_ID           13
#define PA_14_ID           14
#define PA_15_ID           15
#define PB_0_ID            16
#define PB_1_ID            17
#define PB_2_ID            18
#define PB_3_ID            19
#define PB_4_ID            20
#define PB_5_ID            21
#define PB_6_ID            22
#define PB_7_ID            23
#define PB_8_ID            24
#define PB_9_ID            25
#define PB_10_ID           26
#define PB_11_ID           27
#define PB_12_ID           28
#define PB_13_ID           29
#define PB_14_ID           30
#define PB_15_ID           31
#define PC_0_ID            32
#define PC_1_ID            33
#define PC_2_ID            34
#define PC_3_ID            35
#define PC_4_ID            36
#define PC_5_ID            37
#define PC_6_ID            38
#define PC_7_ID            39
#define PC_8_ID            40
#define PC_9_ID            41
#define PC_10_ID           42
#define PC_11_ID           43
#define PC_12_ID           44
#define PC_13_ID           45
#define PC_14_ID           46
#define PC_15_ID           47
#define PD_0_ID            48
#define PD_1_ID            49
#define PD_2_ID            50
#define PD_3_ID            51
#define PD_4_ID            52
#define PD_5_ID            53
#define PD_6_ID            54
#define PD_7_ID            55
#define PD_8_ID            56
#define PD_9_ID            57
#define PD_10_ID           58
#define PD_11_ID           59
#define PD_12_ID           60
#define PD_13_ID           61
#define PD_14_ID           62
#define PD_15_ID           63
#define PE_0_ID            64
#define PE_1_ID            65
#define PE_2_ID            66
#define PE_3_ID            67
#define PE_4_ID            68
#define PE_5_ID            69
#define PE_6_ID            70
#define PE_7_ID            71
#define PE_8_ID            72
#define PE_9_ID            73
#define PE_10_ID           74
#define PE_11_ID           75
#define PE_12_ID           76
#define PE_13_ID           77
#define PE_14_ID           78
#define PE_15_ID           79

#ifdef GPIOF
#define PF_0_ID            80
#define PF_1_ID            81
#define PF_2_ID            82
#define PF_3_ID            83
#define PF_4_ID            84
#define PF_5_ID            85
#define PF_6_ID            86
#define PF_7_ID            87
#define PF_8_ID            88
#define PF_9_ID            89
#define PF_10_ID           90
#define PF_11_ID           91
#define PF_12_ID           92
#define PF_13_ID           93
#define PF_14_ID           94
#define PF_15_ID           95
#endif

#ifdef GPIOG
#define PG_0_ID           96
#define PG_1_ID           97
#define PG_2_ID           98
#define PG_3_ID           99
#define PG_4_ID          100
#define PG_5_ID          101
#define PG_6_ID          102
#define PG_7_ID          103
#define PG_8_ID          104
#define PG_9_ID          105
#define PG_10_ID         106
#define PG_11_ID         107
#define PG_12_ID         108
#define PG_13_ID         109
#define PG_14_ID         110
#define PG_15_ID         111
#endif

#ifdef GPIOH
#define PH_0_ID          112
#define PH_1_ID          113
#define PH_2_ID          114
#define PH_3_ID          115
#define PH_4_ID          116
#define PH_5_ID          117
#define PH_6_ID          118
#define PH_7_ID          119
#define PH_8_ID          120
#define PH_9_ID          121
#define PH_10_ID         122
#define PH_11_ID         123
#define PH_12_ID         124
#define PH_13_ID         125
#define PH_14_ID         126
#define PH_15_ID         127
#endif

extern const gpio_def GpioDefsTab[];
extern gpio_val_s GpioValTab[MAX_GPIO];

#endif