################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bus.cpp \
../src/Camiao.cpp \
../src/Carro.cpp \
../src/Cliente.cpp \
../src/Empresa.cpp \
../src/Funcionario.cpp \
../src/Pessoa.cpp \
../src/Servico.cpp \
../src/Standart.cpp \
../src/Veiculo.cpp \
../src/main.cpp 

OBJS += \
./src/Bus.o \
./src/Camiao.o \
./src/Carro.o \
./src/Cliente.o \
./src/Empresa.o \
./src/Funcionario.o \
./src/Pessoa.o \
./src/Servico.o \
./src/Standart.o \
./src/Veiculo.o \
./src/main.o 

CPP_DEPS += \
./src/Bus.d \
./src/Camiao.d \
./src/Carro.d \
./src/Cliente.d \
./src/Empresa.d \
./src/Funcionario.d \
./src/Pessoa.d \
./src/Servico.d \
./src/Standart.d \
./src/Veiculo.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


