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
atmega1284p \
atmega2560 \
atmega2561 )

rm buildDir/avr-drv-tmrcnt3
for name in ${AVR_TARGET[@]}
do
  echo -n "Making Timer/Counter 5 librairy for" $name
  mkdir -p deliver/lib/$name
  MCU=$name OUTDIR=../deliver/lib/$name TARGET=tmrcnt3 make -s -C TimerCounter clean
  MCU=$name OUTDIR=../deliver/lib/$name TARGET=tmrcnt3 make -C TimerCounter &> /dev/null
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-tmrcnt3

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-tmrcnt3
  fi
done
MCU=at90can128 OUTDIR=../deliver/lib/at90can128 TARGET=tmrcnt3 make -s -C TimerCounter clean
mkdir -p deliver/include
cp -f TimerCounter/tmrcnt3.h deliver/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-tmrcnt3`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-tmrcnt3`

echo "Done"
