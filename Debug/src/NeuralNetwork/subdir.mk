################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NeuralNetwork/Connection.cpp \
../src/NeuralNetwork/InputNeuron.cpp \
../src/NeuralNetwork/NeuralNetwork.cpp \
../src/NeuralNetwork/NeuralNetworkMutational.cpp \
../src/NeuralNetwork/WorkingNeuron.cpp 

OBJS += \
./src/NeuralNetwork/Connection.o \
./src/NeuralNetwork/InputNeuron.o \
./src/NeuralNetwork/NeuralNetwork.o \
./src/NeuralNetwork/NeuralNetworkMutational.o \
./src/NeuralNetwork/WorkingNeuron.o 

CPP_DEPS += \
./src/NeuralNetwork/Connection.d \
./src/NeuralNetwork/InputNeuron.d \
./src/NeuralNetwork/NeuralNetwork.d \
./src/NeuralNetwork/NeuralNetworkMutational.d \
./src/NeuralNetwork/WorkingNeuron.d 


# Each subdirectory must supply rules for building sources it contributes
src/NeuralNetwork/%.o: ../src/NeuralNetwork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/SFML -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


