################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/keypad_driver/key_programe.c 

OBJS += \
./HAL/keypad_driver/key_programe.o 

C_DEPS += \
./HAL/keypad_driver/key_programe.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/keypad_driver/%.o: ../HAL/keypad_driver/%.c HAL/keypad_driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


