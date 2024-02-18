################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Trial/Source/CMSIS_RTOS_V2/cmsis_os2.c 

OBJS += \
./FreeRTOS_Trial/Source/CMSIS_RTOS_V2/cmsis_os2.o 

C_DEPS += \
./FreeRTOS_Trial/Source/CMSIS_RTOS_V2/cmsis_os2.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Trial/Source/CMSIS_RTOS_V2/%.o: ../FreeRTOS_Trial/Source/CMSIS_RTOS_V2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Workspace_eclipse\RTOSApp\Drivers\Inc" -I"E:\Workspace_eclipse\RTOSApp\FreeRTOS_Trial\Source\include" -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


