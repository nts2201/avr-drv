#!/bin/bash

AVR_TARGET=(at90can32 \
at90can64 \
at90can128 \
at90pwm1 \
at90pwm2 \
at90pwm2b \
at90pwm3 \
at90pwm3b \
at90pwm216 \
at90pwm316 \
at90usb82 \
at90usb162 \
at90usb646 \
at90usb647 \
at90usb1286 \
at90usb1287 \
atmega8 \
atmega8u2 \
atmega16 \
atmega16a \
atmega16m1 \
atmega16u4 \
atmega32 \
atmega32c1 \
atmega32m1 \
atmega32u2 \
atmega32u4 \
atmega32u6 \
atmega48 \
atmega48a \
atmega48p \
atmega64 \
atmega64c1 \
atmega64m1 \
atmega88 \
atmega88a \
atmega88p \
atmega88pa \
atmega128 \
atmega128rfa1 \
atmega161 \
atmega162 \
atmega163 \
atmega164p \
atmega164a \
atmega165 \
atmega165p \
atmega168 \
atmega168a \
atmega168p \
atmega169 \
atmega169p \
atmega169pa \
atmega323 \
atmega324p \
atmega324a \
atmega324pa \
atmega325 \
atmega325p \
atmega328 \
atmega328p \
atmega329 \
atmega329p \
atmega329pa \
atmega640 \
atmega644 \
atmega644a \
atmega644p \
atmega644pa \
atmega645 \
atmega649 \
atmega649p \
atmega1280 \
atmega1281 \
atmega1284p \
atmega2560 \
atmega2561 \
atmega3250 \
atmega3250p \
atmega3290 \
atmega3290p \
atmega6450 \
atmega6490 \
atmega8535 \
attiny48 \
attiny88)

rm buildDir/avr-drv-spi
for name in ${AVR_TARGET[@]}
do
  echo -n "Making SPI librairy for" $name
  mkdir -p avr-drv/lib/$name
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=spi make -s -C SPI clean
  MCU=$name OUTDIR=../avr-drv/lib/$name TARGET=spi make -s -k -C SPI
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-spi

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-spi
  fi
done
MCU=at90can128 OUTDIR=../avr-drv/lib/at90can128 TARGET=spi make -s -C SPI clean
mkdir -p avr-drv/include
cp -f SPI/spi.h avr-drv/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-spi`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-spi`

echo "Done"
