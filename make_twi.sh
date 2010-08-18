#!/bin/bash

AVR_TARGET=(at90can32 \
at90can64 \
at90can128 \
at90usb646 \
at90usb647 \
at90usb1286 \
at90usb1287 \
atmega8 \
atmega16 \
atmega16a \
atmega16hvb \
atmega32 \
atmega32hvb \
atmega32u4 \
atmega32u6 \
atmega48 \
atmega48a \
atmega48p \
atmega64 \
atmega88 \
atmega88a \
atmega88p \
atmega88pa \
atmega128 \
atmega128rfa1 \
atmega163 \
atmega164p \
atmega164a \
atmega168 \
atmega168a \
atmega168p \
atmega323 \
atmega324p \
atmega324a \
atmega324pa \
atmega328 \
atmega328p \
atmega406 \
atmega640 \
atmega644 \
atmega644a \
atmega644p \
atmega644pa \
atmega1280 \
atmega1281 \
atmega1284p \
atmega2560 \
atmega2561 \
attiny48 \
attiny88 )

rm buildDir/avr-drv-twi
for name in ${AVR_TARGET[@]}
do
  echo -n "Making TWI librairy for" $name
  mkdir -p avr-drv/lib/$name
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=twi make -s -C TWI clean
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=twi make -s -C TWI
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-twi

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-twi
  fi
done
MCU=at90can128 OUTDIR=../avr-drv/lib/at90can128 TARGET=twi make -s -C TWI clean
mkdir -p avr-drv/include
cp -f TWI/twi.h avr-drv/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-twi`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-twi`

echo "Done"
