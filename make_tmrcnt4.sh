#!/bin/bash

AVR_TARGET=(atmega128rfa1 \
atmega640 \
atmega1280 \
atmega1281 \
atmega2560 \
atmega2561 )

rm buildDir/avr-drv-tmrcnt4
for name in ${AVR_TARGET[@]}
do
  echo -n "Making Timer/Counter 4 librairy for" $name
  mkdir -p avr-drv/lib/$name
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=tmrcnt4 make -s -C TimerCounter clean
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=tmrcnt4 make -s -k -C TimerCounter
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-tmrcnt4

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-tmrcnt4
  fi
done
MCU=at90can128 OUTDIR=../avr-drv/lib/at90can128 TARGET=tmrcnt4 make -s -C TimerCounter clean
mkdir -p avr-drv/include
cp -f TimerCounter/tmrcnt4.h avr-drv/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-tmrcnt4`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-tmrcnt4`

echo "Done"
