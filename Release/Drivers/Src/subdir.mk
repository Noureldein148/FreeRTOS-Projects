################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/ADC.c \
../Drivers/Src/DIO_program.c \
../Drivers/Src/Ext_INT.c \
../Drivers/Src/Global_INT.c \
../Drivers/Src/LCD.c \
../Drivers/Src/LED.c \
../Drivers/Src/Timer_program.c \
../Drivers/Src/UART.c 

OBJS += \
./Drivers/Src/ADC.o \
./Drivers/Src/DIO_program.o \
./Drivers/Src/Ext_INT.o \
./Drivers/Src/Global_INT.o \
./Drivers/Src/LCD.o \
./Drivers/Src/LED.o \
./Drivers/Src/Timer_program.o \
./Drivers/Src/UART.o 

C_DEPS += \
./Drivers/Src/ADC.d \
./Drivers/Src/DIO_program.d \
./Drivers/Src/Ext_INT.d \
./Drivers/Src/Global_INT.d \
./Drivers/Src/LCD.d \
./Drivers/Src/LED.d \
./Drivers/Src/Timer_program.d \
./Drivers/Src/UART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o: ../Drivers/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Workspace_eclipse\RTOSApp\Drivers\Inc" -I"E:\Workspace_eclipse\RTOSApp\FreeRTOS_Trial\Inc" -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


