#!/bin/bash

sed -i 's/#define    \([A-Z]*_[0-9]*_MODE\)/#define    \1    UNUSED/g' gpio_defs_copy.h
sleep 0.3
sed -i 's/#define 	\([A-Z]*_[0-9]*_SPEED\)/#define    \1    SPEED_HIGH/g' gpio_defs_copy.h
sleep 0.3
sed -i 's/#define 	\([A-Z]*_[0-9]*_OUTPUT\)/#define    \1    PUSH_PULL/g' gpio_defs_copy.h
sleep 0.3
sed -i 's/#define 	\([A-Z]*_[0-9]*_PULL_TYPE\)/#define    \1    NO_PULL/g' gpio_defs_copy.h

sleep 0.3

for ((i=0; i<=15; i++))
do
  sed -i "s/#define 	P[A-Z]*_${i}_PIN/#define PA_${i}_PIN    IO_PIN_${i}/" gpio_defs_copy.h
  sleep 0.3
done