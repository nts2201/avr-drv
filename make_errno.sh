#!/bin/bash

AVR_TARGET=(at90s2313 \
at90s2323 \
at90s2333 \
at90s2343 \
attiny22 \
attiny26 \
at90s4414 \
at90s4433 \
at90s4434 \
at90s8515 \
at90c8534 \
at90s8535 \
ata6289 \
attiny13 \
attiny13a \
attiny2313 \
attiny2313a \
attiny24 \
attiny24a \
attiny4313 \
attiny44 \
attiny44a \
attiny84 \
attiny25 \
attiny45 \
attiny85 \
attiny261 \
attiny261a \
attiny461 \
attiny461a \
attiny861 \
attiny861a \
attiny43u \
attiny87 \
attiny48 \
attiny88 \
at86rf401 \
at43usb320 \
at43usb355 \
at76c711 \
atmega103 \
at90usb82 \
at90usb162 \
atmega8u2 \
atmega16u2 \
atmega32u2 \
attiny167 \
atmega8 \
atmega48 \
atmega48a \
atmega48p \
atmega88 \
atmega88a \
atmega88p \
atmega88pa \
atmega8515 \
atmega8535 \
atmega8hva \
atmega4hvd \
atmega8hvd \
at90pwm1 \
at90pwm2 \
at90pwm2b \
at90pwm3 \
at90pwm3b \
at90pwm81 \
atmega16 \
atmega16a \
atmega161 \
atmega162 \
atmega163 \
atmega164a \
atmega164p \
atmega165 \
atmega165a \
atmega165p \
atmega168 \
atmega168a \
atmega168p \
atmega169 \
atmega169a \
atmega169p \
atmega169pa \
atmega16c1 \
atmega16hva \
atmega16hva2 \
atmega16hvb \
atmega16m1 \
atmega16u4 \
atmega32 \
atmega323 \
atmega324a \
atmega324p \
atmega324pa \
atmega325 \
atmega325p \
atmega3250 \
atmega3250p \
atmega328 \
atmega328p \
atmega329 \
atmega329p \
atmega329pa \
atmega3290 \
atmega3290p \
atmega32c1 \
atmega32hvb \
atmega32m1 \
atmega32u4 \
atmega32u6 \
atmega406 \
atmega64 \
atmega640 \
atmega644 \
atmega644a \
atmega644p \
atmega644pa \
atmega645 \
atmega645a \
atmega645p \
atmega6450 \
atmega6450a \
atmega6450p \
atmega649 \
atmega649a \
atmega649p \
atmega6490 \
atmega6490a \
atmega6490p \
atmega64c1 \
atmega64m1 \
atmega64hve \
at90can32 \
at90can64 \
at90pwm216 \
at90pwm316 \
at90scr100 \
at90usb646 \
at90usb647 \
at94k \
atmega128 \
atmega1280 \
atmega1281 \
atmega1284p \
atmega128rfa1 \
at90can128 \
at90usb1286 \
at90usb1287 \
m3000f \
m3000s \
m3001b \
atmega2560 \
atmega2561 \
at90s1200 \
attiny11 \
attiny12 \
attiny15 \
attiny28 )

rm buildDir/avr-drv-errno
for name in ${AVR_TARGET[@]}
do
  echo -n "Making avr-drv-errno librairy for" $name
  mkdir -p deliver/lib/$name
  MCU=$name OUTDIR=../deliver/lib/$name make -s -C errno clean
  MCU=$name OUTDIR=../deliver/lib/$name make -C errno &> /dev/null
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-errno

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-errno
  fi
done
MCU=at90can128 OUTDIR=../deliver/lib/at90can128 make -s -C errno clean
mkdir -p deliver/include
cp -f errno/*.h deliver/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-errno`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-errno`

echo "Done"
