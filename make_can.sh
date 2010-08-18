#!/bin/bash

AVR_TARGET=(at90can32 \
at90can64 \
at90can128 \
atmega32c1 \
atmega64c1 \
atmega16m1 \
atmega32m1 \
atmega64m1)

rm buildDir/avr-drv-can
for name in ${AVR_TARGET[@]}
do
  echo -n "Making CAN librairy for" $name
  mkdir -p avr-drv/lib/$name
  MCU=$name OUTDIR=../avr-drv/lib/$name make -s -C CAN clean
  MCU=$name OUTDIR=../avr-drv/lib/$name make -s -k -C CAN
  code=$?
  if (( code )); then
    echo -e '\E[31m'"\tFAIL"; tput sgr0
    echo "||"$name"||FAIL||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-can

  else
    echo -e '\E[32m'"\tPASS"; tput sgr0
    echo "||"$name"||PASS||" | tr [:lower:] [:upper:] | sed 's/MEGA/mega/' | sed 's/TINY/tiny/' >> buildDir/avr-drv-can
  fi
done
MCU=at90can128 OUTDIR=../avr-drv/lib/at90can128 make -s -C CAN clean
mkdir -p avr-drv/include
cp -f CAN/*.h avr-drv/include

echo -n "PASS" `grep -c PASS buildDir/avr-drv-can`
echo " FAIL" `grep -c FAIL buildDir/avr-drv-can`

echo "Done"
