#!/bin/bash

AVR_TARGET=(at90can32 \
at90can64 \
at90can128 \
at90pwm1 \
at90pwm2 \
at90pwm2b \
at90pwm3 \
at90pwm3b \
at90pwm81 \
at90pwm216 \
at90pwm316 \
at90usb646 \
at90usb647 \
at90usb1286 \
at90usb1287 \
atmega8 \
atmega16 \
atmega16a \
atmega16m1 \
atmega16u4 \
atmega32 \
atmega32c1 \
atmega32m1 \
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
atmega103 \
atmega128 \
atmega128rfa1 \
atmega163 \
atmega164p \
atmega164a \
atmega165 \
atmega165p \
atmega168 \
atmega168a \
atmega168p \
atmega169 \
atmega169a \
atmega169p \
atmega169pa \
atmega323 \
atmega324p \
atmega324a \
atmega324pa \
atmega325 \
atmega325p \
atmega328p \
atmega328 \
atmega329 \
atmega329p \
atmega329pa \
atmega640 \
atmega644 \
atmega644a \
atmega644p \
atmega644pa \
atmega645 \
atmega645a \
atmega645p \
atmega649 \
atmega649a \
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
atmega6450a \
atmega6450p \
atmega6490 \
atmega6490a \
atmega6490p \
atmega8535 \
attiny13 \
attiny13a \
attiny24 \
attiny24a \
attiny25 \
attiny26 \
attiny43u \
attiny44 \
attiny44a \
attiny45 \
attiny48 \
attiny84 \
attiny85 \
attiny88 \
attiny87 \
attiny167 \
attiny261 \
attiny261a \
attiny461 \
attiny861 \
attiny861a)

rm buildDir/avr-drv-adcoutput
for name in ${AVR_TARGET[@]}
do
  echo -n "Making ADC librairy for" $name
  mkdir -p deliver/lib/$name
  MCU=$name OUTDIR=../deliver/lib/$name make -s -C ADC clean
  MCU=$name OUTDIR=../deliver/lib/$name make -s -C ADC &> /dev/null
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-adcoutput

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-adcoutput
  fi
done
MCU=at90can128 OUTDIR=../deliver/lib/at90can128 make -s -C ADC clean
mkdir -p deliver/include
cp -f ADC/*.h deliver/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-adcoutput`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-adcoutput`

echo "Done"
