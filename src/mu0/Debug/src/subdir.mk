################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bus.cpp \
../src/Composant.cpp \
../src/Instruction.cpp \
../src/InterfaceGraphique.cpp \
../src/Memoire.cpp \
../src/Microprocesseur.cpp \
../src/Mu0.cpp \
../src/Multiplexeur.cpp \
../src/Porte.cpp \
../src/Registre.cpp \
../src/UAL.cpp \
../src/main.cpp 

OBJS += \
./src/Bus.o \
./src/Composant.o \
./src/Instruction.o \
./src/InterfaceGraphique.o \
./src/Memoire.o \
./src/Microprocesseur.o \
./src/Mu0.o \
./src/Multiplexeur.o \
./src/Porte.o \
./src/Registre.o \
./src/UAL.o \
./src/main.o 

CPP_DEPS += \
./src/Bus.d \
./src/Composant.d \
./src/Instruction.d \
./src/InterfaceGraphique.d \
./src/Memoire.d \
./src/Microprocesseur.d \
./src/Mu0.d \
./src/Multiplexeur.d \
./src/Porte.d \
./src/Registre.d \
./src/UAL.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


