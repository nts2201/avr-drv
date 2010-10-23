#!/bin/bash

mkdir -p ./avr-drv/include/io_pin
cp ./io_pin/*.h ./avr-drv/include/io_pin

./make_errno.sh
./make_adc.sh
./make_can.sh
./make_extint.sh
./make_spi.sh
./make_tmrcnt0.sh
./make_tmrcnt1.sh
./make_tmrcnt2.sh
./make_tmrcnt3.sh
./make_tmrcnt4.sh
./make_tmrcnt5.sh
./make_twi.sh
./make_twi_int.sh
./make_usart.sh


