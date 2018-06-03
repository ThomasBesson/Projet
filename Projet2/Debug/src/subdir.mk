################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/algo.c \
../src/dijkstra.c \
../src/fevent.c \
../src/ffigure.c \
../src/finit.c \
../src/ftext.c \
../src/graphes.c \
../src/liste.c \
../src/liste_arc.c \
../src/liste_hachage.c \
../src/main.c \
../src/pile.c \
../src/tas.c

OBJS += \
./src/algo.o \
./src/dijkstra.o \
./src/fevent.o \
./src/ffigure.o \
./src/finit.o \
./src/ftext.o \
./src/graphes.o \
./src/liste.o \
./src/liste_arc.o \
./src/liste_hachage.o \
./src/main.o \
./src/pile.o \
./src/tas.o

C_DEPS += \
./src/algo.d \
./src/dijkstra.d \
./src/fevent.d \
./src/ffigure.d \
./src/finit.d \
./src/ftext.d \
./src/graphes.d \
./src/liste.d \
./src/liste_arc.d \
./src/liste_hachage.d \
./src/main.d \
./src/pile.d \
./src/tas.d


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I../inc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
