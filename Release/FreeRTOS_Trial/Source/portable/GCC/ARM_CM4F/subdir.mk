################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Trial/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./FreeRTOS_Trial/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./FreeRTOS_Trial/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Trial/Source/portable/GCC/ARM_CM4F/%.o: ../FreeRTOS_Trial/Source/portable/GCC/ARM_CM4F/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Workspace_eclipse\RTOSApp\Drivers\Inc" -I"E:\Workspace_eclipse\RTOSApp\FreeRTOS_Trial\Source\include" -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


