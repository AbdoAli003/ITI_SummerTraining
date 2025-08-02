################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Library/MCAL/DIO/subdir.mk
-include Library/LIB/subdir.mk
-include Library/HAL/SSD/subdir.mk
-include Library/HAL/LCD/subdir.mk
-include Library/HAL/KEYPAD/subdir.mk
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
KeyPad_asg.lss \

FLASH_IMAGE += \
KeyPad_asg.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KeyPad_asg.elf secondary-outputs

# Tool invocations
KeyPad_asg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KeyPad_asg.map -mmcu=atmega32 -o "KeyPad_asg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KeyPad_asg.lss: KeyPad_asg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KeyPad_asg.elf  >"KeyPad_asg.lss"
	@echo 'Finished building: $@'
	@echo ' '

KeyPad_asg.hex: KeyPad_asg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KeyPad_asg.elf  "KeyPad_asg.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KeyPad_asg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KeyPad_asg.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KeyPad_asg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
