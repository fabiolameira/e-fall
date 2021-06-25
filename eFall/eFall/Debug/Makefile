################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../__vm/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../MIDDLE.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
MIDDLE.o

OBJS_AS_ARGS +=  \
MIDDLE.o

C_DEPS +=  \
MIDDLE.d

C_DEPS_AS_ARGS +=  \
MIDDLE.d

OUTPUT_FILE_PATH +=eFall.elf

OUTPUT_FILE_PATH_AS_ARGS +=eFall.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./MIDDLE.o: .././MIDDLE.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -D_VMDEBUG=1 -DARDUINO=108013 -DARDUINO_MAIN -Dprintf=iprintf -D__MBED_NANO__ -DARDUINO_ARCH_NRF52840 -DARDUINO_ARDUINO_NANO33BLE -DARDUINO_ARCH_MBED_NANO -DARDUINO_LIBRARY_DISCOVERY_PHASE=0  -I"../../../eFall" -I"C:/Users/fabio/Documents/Arduino/libraries/Arduino_LSM9DS1-1.1.0/src" -I"C:/Users/fabio/AppData/Local/arduino15/packages/arduino/hardware/mbed_nano/2.2.0/libraries/Wire" -I"C:/Users/fabio/AppData/Local/arduino15/packages/arduino/hardware/mbed_nano/2.2.0/cores/arduino" -I"C:/Users/fabio/AppData/Local/arduino15/packages/arduino/hardware/mbed_nano/2.2.0/cores/arduino/api" -I"C:/Users/fabio/AppData/Local/arduino15/packages/arduino/hardware/mbed_nano/2.2.0/cores/arduino/mbed" -I"C:/Users/fabio/AppData/Local/arduino15/packages/arduino/hardware/mbed_nano/2.2.0/cores/arduino/USB" -I"C:\Users\fabio\AppData\Local\ARDUIN~1\packages\arduino\hardware\MBED_N~1\2200BD~1.0\variants\ARDUIN~1" -I"C:\Users\fabio\AppData\Local\ARDUIN~1\packages\arduino\hardware\MBED_N~1\2200BD~1.0\cores\arduino\api\DEPREC~1" -I"C:\Users\fabio\AppData\Local\ARDUIN~1\packages\arduino\hardware\MBED_N~1\2200BD~1.0\cores\arduino\api\DEPREC~2" -I"prefixC:\Users\fabio\AppData\Local\arduino15\packages\arduino\hardware\mbed_nano\2.2.0\cores\arduino" -I"C:/Users/fabio/AppData/Local/arduino15/packages/arduino/hardware/mbed_nano"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega2560 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega2560" -c -include=arduino.h -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="eFall.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega2560 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega2560"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "eFall.elf" "eFall.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "eFall.elf" "eFall.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "eFall.elf" > "eFall.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "eFall.elf" "eFall.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "eFall.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "eFall.elf" "eFall.a" "eFall.hex" "eFall.lss" "eFall.eep" "eFall.map" "eFall.srec" "eFall.usersignatures"
	