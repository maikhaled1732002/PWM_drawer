################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/mdio/mdio_programe.c 

OBJS += \
./MCAL/mdio/mdio_programe.o 

C_DEPS += \
./MCAL/mdio/mdio_programe.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/mdio/%.o: ../MCAL/mdio/%.c MCAL/mdio/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


