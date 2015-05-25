# Howto use AVR-drv #

## Prebuild package ##

You should grab the package in the download section and extract it in /opt/avr-drv

## Building from source ##

Well, lets face it, this is not the easiest thing, but it is for sure not hard. Machine used to build release is as follow:
  * Ubuntu 10.04 x64
  * avr-libc 1.7.0

You will need:
  * avr-drv source
  * XML description part from AVR Studio version 4.18 build 716
  * a rabbit leg

Assuming that avr-drc sources are in /home/user/avr-drv
  * Place xml in xmlPartDescription directory
  * Patch avr-libc headers, more or less
    * ~/src/avr-libc/trunk/avr-libc/include/avr$ sudo patch -i /home/user/avr-drv/patch/avr-libc\_1.7.0.patch
  * Patch XML files, more or less
    * avr-drv/xmlPartDescription$ patch -p2 -i ../patch/xmlPartDescription.patch
  * Run from src directory, run the makefile
  * Result is placed in avr-drv directory, you can copy it to /opt/

## Doxygen ##

Doxygen can be found here: http://avr-drv.googlecode.com/svn/doc/html/index.html