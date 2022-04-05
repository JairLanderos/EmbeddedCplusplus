################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/system_stm32f4xx.c 

CPP_SRCS += \
../Src/main.cpp \
../Src/servo.cpp 

OBJS += \
./Src/main.o \
./Src/servo.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/system_stm32f4xx.d 

CPP_DEPS += \
./Src/main.d \
./Src/servo.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F446xx -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Inc" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F446xx -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Inc" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Fam. Landeros Franco/Desktop/Embedded Systems/C++ course/Servo/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


