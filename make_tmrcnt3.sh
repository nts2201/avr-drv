#!/bin/bash

AVR_TARGET=(at90can32 \
at90can64 \
at90can128 \
at90usb646 \
at90usb647 \
at90usb1286 \
at90usb1287 \
atmega128rfa1 \
atmega640 \
atmega1280 \
atmega1281 \
atmega2560 \
atmega2561 )

rm buildDir/avr-drv-tmrcnt3
for name in ${AVR_TARGET[@]}
do
  echo -n "Making Timer/Counter 3 librairy for" $name
  mkdir -p avr-drv/lib/$name
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=tmrcnt3 make -s -C TimerCounter clean
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=tmrcnt3 make -s -k -C TimerCounter
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-tmrcnt3

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-tmrcnt3
  fi
done
MCU=at90can128 OUTDIR=../avr-drv/lib/at90can128 TARGET=tmrcnt3 make -s -C TimerCounter clean
mkdir -p avr-drv/include
cp -f TimerCounter/tmrcnt3.h avr-drv/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-tmrcnt3`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-tmrcnt3`

echo "Done"
