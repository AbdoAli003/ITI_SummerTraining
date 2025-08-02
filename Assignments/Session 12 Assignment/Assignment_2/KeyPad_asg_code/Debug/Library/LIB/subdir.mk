################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/abdoa/Desktop/myLab/Library/LIB/delay.c 

OBJS += \
./Library/LIB/delay.o 

C_DEPS += \
./Library/LIB/delay.d 


# Each subdirectory must supply rules for building sources it contributes
Library/LIB/delay.o: C:/Users/abdoa/Desktop/myLab/Library/LIB/delay.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\abdoa\Desktop\myLab\Library" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


