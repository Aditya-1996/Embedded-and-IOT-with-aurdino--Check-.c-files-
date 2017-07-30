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
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
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
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FirstProjectIOT.lss \

FLASH_IMAGE += \
FirstProjectIOT.hex \

EEPROM_IMAGE += \
FirstProjectIOT.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: FirstProjectIOT.elf secondary-outputs

# Tool invocations
FirstProjectIOT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,FirstProjectIOT.map,--cref -mrelax -Wl,--gc-sections -mmcu=atmega2560 -o "FirstProjectIOT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FirstProjectIOT.lss: FirstProjectIOT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FirstProjectIOT.elf  >"FirstProjectIOT.lss"
	@echo 'Finished building: $@'
	@echo ' '

FirstProjectIOT.hex: FirstProjectIOT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FirstProjectIOT.elf  "FirstProjectIOT.hex"
	@echo 'Finished building: $@'
	@echo ' '

FirstProjectIOT.eep: FirstProjectIOT.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex FirstProjectIOT.elf  "FirstProjectIOT.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FirstProjectIOT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 FirstProjectIOT.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: FirstProjectIOT.elf
	@echo 'Invoking: AVRDude'
	C:\Program Files\Arduino\hardware\tools\avr\bin\avrdude -pm2560 -cstk500v2 -PCOM7 -b115200 -D -Uflash:w:FirstProjectIOT.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) FirstProjectIOT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
