
layout src

target extended-remote localhost:3333

set $DBGMCU_IDCODE = 0xE0042000
set $DEV_ID = (*$DBGMCU_IDCODE) & 0xFFF
set $REV_ID = ((*$DBGMCU_IDCODE)>>16) & 0xFFFF

if $DEV_ID == 0x412 || $DEV_ID == 0x410 || $DEV_ID == 0x414 || $DEV_ID == 0x430 || $DEV_ID == 0x418
	printf "Load scripts for STM32F1xx."
	source stm32f1.gdb
end  