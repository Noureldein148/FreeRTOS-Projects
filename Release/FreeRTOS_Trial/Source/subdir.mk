################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Trial/Source/croutine.c \
../FreeRTOS_Trial/Source/event_groups.c \
../FreeRTOS_Trial/Source/list.c \
../FreeRTOS_Trial/Source/queue.c \
../FreeRTOS_Trial/Source/stream_buffer.c \
../FreeRTOS_Trial/Source/tasks.c \
../FreeRTOS_Trial/Source/timers.c 

OBJS += \
./FreeRTOS_Trial/Source/croutine.o \
./FreeRTOS_Trial/Source/event_groups.o \
./FreeRTOS_Trial/Source/list.o \
./FreeRTOS_Trial/Source/queue.o \
./FreeRTOS_Trial/Source/stream_buffer.o \
./FreeRTOS_Trial/Source/tasks.o \
./FreeRTOS_Trial/Source/timers.o 

C_DEPS += \
./FreeRTOS_Trial/Source/croutine.d \
./FreeRTOS_Trial/Source/event_groups.d \
./FreeRTOS_Trial/Source/list.d \
./FreeRTOS_Trial/Source/queue.d \
./FreeRTOS_Trial/Source/stream_buffer.d \
./FreeRTOS_Trial/Source/tasks.d \
./FreeRTOS_Trial/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Trial/Source/%.o: ../FreeRTOS_Trial/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Workspace_eclipse\RTOSApp\Drivers\Inc" -I"E:\Workspace_eclipse\RTOSApp\FreeRTOS_Trial\Source\include" -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


