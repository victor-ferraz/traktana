# MPLAB IDE generated this makefile for use with GNU make.
# Project: Traktana.mcp
# Date: Wed Jan 18 15:06:31 2012

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

./obj/Traktana.hex : ./obj/Traktana.cof
	$(HX) ".\obj\Traktana.cof"

./obj/Traktana.cof : tmp/main.o tmp/uart.o tmp/steppers.o tmp/motor_pid.o
	$(CC) -mcpu=30F3014 "tmp\main.o" "tmp\uart.o" "tmp\steppers.o" "tmp\motor_pid.o" "C:\Users\Rafael\Desktop\traktana\sw\traktana_fw\lib\libdsp-coff.a" "C:\Users\Rafael\Desktop\traktana\sw\traktana_fw\lib\libdsp-elf.a" -o"./obj\Traktana.cof" -Wl,-Tp30F3014.gld,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=__ICD2RAM=1,-Map="./obj\Traktana.map",--report-mem

tmp/main.o : ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h src/main.c
	$(CC) -mcpu=30F3014 -x c -c "src\main.c" -o"./tmp\main.o" -I"./h" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

tmp/uart.o : ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/include/stddef.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/include/string.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/peripheral_30F_24H_33F/uart.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h src/uart.c
	$(CC) -mcpu=30F3014 -x c -c "src\uart.c" -o"./tmp\uart.o" -I"./h" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

tmp/steppers.o : ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/peripheral_30F_24H_33F/timer.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h src/steppers.c
	$(CC) -mcpu=30F3014 -x c -c "src\steppers.c" -o"./tmp\steppers.o" -I"./h" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

tmp/motor_pid.o : ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/include/stdarg.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/include/stdio.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/peripheral_30F_24H_33F/uart.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/peripheral_30F_24H_33F/adc12.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/peripheral_30F_24H_33F/timer.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30F3014.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/dsPIC30F/h/p30fxxxx.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/peripheral_30F_24H_33F/outcompare.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/include/math.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/include/stddef.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/include/stdlib.h ../../../../../../program\ files\ (x86)/microchip/mplabc30/v3.31/support/generic/h/dsp.h src/motor_pid.c
	$(CC) -mcpu=30F3014 -x c -c "src\motor_pid.c" -o"./tmp\motor_pid.o" -I"./h" -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -g -Wall

clean : 
	$(RM) "tmp\main.o" "tmp\uart.o" "tmp\steppers.o" "tmp\motor_pid.o" ".\obj\Traktana.cof" ".\obj\Traktana.hex"

