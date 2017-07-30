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
urattest.lss \

FLASH_IMAGE += \
urattest.hex \

EEPROM_IMAGE += \
urattest.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: urattest.elf secondary-outputs

# Tool invocations
urattest.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,urattest.map -mmcu=atmega2560 -o "urattest.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

urattest.lss: urattest.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S urattest.elf  >"urattest.lss"
	@echo 'Finished building: $@'
	@echo ' '

urattest.hex: urattest.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex urattest.elf  "urattest.hex"
	@echo 'Finished building: $@'
	@echo ' '

urattest.eep: urattest.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex urattest.elf  "urattest.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: urattest.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 urattest.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: urattest.elf
	@echo 'Invoking: AVRDude'
	C:\Program Files\Arduino\hardware\tools\avr\bin\avrdude -pm2560 -cstk500v2 -PCOM7 -b115200 -D -Uflash:w:urattest.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) urattest.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
