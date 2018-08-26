################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Layer.cpp \
../src/Main.cpp \
../src/Net.cpp \
../src/Neuron.cpp \
../src/TrainingData.cpp 

OBJS += \
./src/Layer.o \
./src/Main.o \
./src/Net.o \
./src/Neuron.o \
./src/TrainingData.o 

CPP_DEPS += \
./src/Layer.d \
./src/Main.d \
./src/Net.d \
./src/Neuron.d \
./src/TrainingData.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


