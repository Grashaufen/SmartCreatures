################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Creature.cpp \
../src/CreatureStats.cpp \
../src/NeuralNetworkCreature.cpp \
../src/main.cpp 

OBJS += \
./src/Creature.o \
./src/CreatureStats.o \
./src/NeuralNetworkCreature.o \
./src/main.o 

CPP_DEPS += \
./src/Creature.d \
./src/CreatureStats.d \
./src/NeuralNetworkCreature.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/SFML -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


