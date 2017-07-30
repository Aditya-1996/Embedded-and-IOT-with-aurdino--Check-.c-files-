################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
uartRobot.lss \

FLASH_IMAGE += \
uartRobot.hex \

EEPROM_IMAGE += \
uartRobot.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: uartRobot.elf secondary-outputs

# Tool invocations
uartRobot.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,uartRobot.map -mmcu=atmega2560 -o "uartRobot.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

uartRobot.lss: uartRobot.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S uartRobot.elf  >"uartRobot.lss"
	@echo 'Finished building: $@'
	@echo ' '

uartRobot.hex: uartRobot.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex uartRobot.elf  "uartRobot.hex"
	@echo 'Finished building: $@'
	@echo ' '

uartRobot.eep: uartRobot.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex uartRobot.elf  "uartRobot.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: uartRobot.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 uartRobot.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: uartRobot.elf
	@echo 'Invoking: AVRDude'
	C:\Program Files\Arduino\hardware\tools\avr\bin\avrdude -pm2560 -cwiring -PCOM8 -b115200 -D -Uflash:w:uartRobot.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) uartRobot.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
