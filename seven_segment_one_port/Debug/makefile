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
seven_segment_one_port.lss \

FLASH_IMAGE += \
seven_segment_one_port.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: seven_segment_one_port.elf secondary-outputs

# Tool invocations
seven_segment_one_port.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,seven_segment_one_port.map -mmcu=atmega32 -o "seven_segment_one_port.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

seven_segment_one_port.lss: seven_segment_one_port.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S seven_segment_one_port.elf  >"seven_segment_one_port.lss"
	@echo 'Finished building: $@'
	@echo ' '

seven_segment_one_port.hex: seven_segment_one_port.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex seven_segment_one_port.elf  "seven_segment_one_port.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: seven_segment_one_port.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 seven_segment_one_port.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) seven_segment_one_port.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
