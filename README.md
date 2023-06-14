# Open-SOCD
An open source SOCD cleaner based on the Attiny 84



## Installation

I use a Tiny AVR Programmer from Sparkfun https://www.sparkfun.com/products/11801

download the .hex file [here](https://github.com/jake-s2021/Open-SOCD/releases)

and make sure you have avrdude installed on your target operating system

Windows: install [WinAVR](https://sourceforge.net/projects/winavr/)

Linux and MacOS: install these dependancies

```
gcc-avr avr-libc avrdude
``` 

Use this command in PowerShell/terminal to upload the hex file. your -c option will change depending on what programmer you use.

```
avrdude -v -p attiny84 -c usbtiny -e -Uefuse:w:0xFF:m -Uhfuse:w:0b11010111:m -Ulfuse:w:0xE2:m -U flash:w:socd.hex:i -F -P usb

```


