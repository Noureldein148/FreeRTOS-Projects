################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Trial/Src/PollQ.c \
../FreeRTOS_Trial/Src/croutine.c \
../FreeRTOS_Trial/Src/event_groups.c \
../FreeRTOS_Trial/Src/heap_1.c \
../FreeRTOS_Trial/Src/integer.c \
../FreeRTOS_Trial/Src/list.c \
../FreeRTOS_Trial/Src/port.c \
../FreeRTOS_Trial/Src/queue.c \
../FreeRTOS_Trial/Src/tasks.c 

OBJS += \
./FreeRTOS_Trial/Src/PollQ.o \
./FreeRTOS_Trial/Src/croutine.o \
./FreeRTOS_Trial/Src/event_groups.o \
./FreeRTOS_Trial/Src/heap_1.o \
./FreeRTOS_Trial/Src/integer.o \
./FreeRTOS_Trial/Src/list.o \
./FreeRTOS_Trial/Src/port.o \
./FreeRTOS_Trial/Src/queue.o \
./FreeRTOS_Trial/Src/tasks.o 

C_DEPS += \
./FreeRTOS_Trial/Src/PollQ.d \
./FreeRTOS_Trial/Src/croutine.d \
./FreeRTOS_Trial/Src/event_groups.d \
./FreeRTOS_Trial/Src/heap_1.d \
./FreeRTOS_Trial/Src/integer.d \
./FreeRTOS_Trial/Src/list.d \
./FreeRTOS_Trial/Src/port.d \
./FreeRTOS_Trial/Src/queue.d \
./FreeRTOS_Trial/Src/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Trial/Src/%.o: ../FreeRTOS_Trial/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Workspace_eclipse\RTOSApp\Drivers\Inc" -I"E:\Workspace_eclipse\RTOSApp\FreeRTOS_Trial\Inc" -Wall -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


