################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Artista.cpp \
../src/Cancion.cpp \
../src/Fecha.cpp \
../src/GestorArtistas.cpp \
../src/GestorUsuarios.cpp \
../src/Playlist.cpp \
../src/PruebaArtista.cpp \
../src/PruebaCancion.cpp \
../src/PruebaFecha.cpp \
../src/PruebaPlaylist.cpp \
../src/PruebaUsuario.cpp \
../src/Sistema.cpp \
../src/Usuario.cpp \
../src/progPrincipal.cpp 

CPP_DEPS += \
./src/Artista.d \
./src/Cancion.d \
./src/Fecha.d \
./src/GestorArtistas.d \
./src/GestorUsuarios.d \
./src/Playlist.d \
./src/PruebaArtista.d \
./src/PruebaCancion.d \
./src/PruebaFecha.d \
./src/PruebaPlaylist.d \
./src/PruebaUsuario.d \
./src/Sistema.d \
./src/Usuario.d \
./src/progPrincipal.d 

OBJS += \
./src/Artista.o \
./src/Cancion.o \
./src/Fecha.o \
./src/GestorArtistas.o \
./src/GestorUsuarios.o \
./src/Playlist.o \
./src/PruebaArtista.o \
./src/PruebaCancion.o \
./src/PruebaFecha.o \
./src/PruebaPlaylist.o \
./src/PruebaUsuario.o \
./src/Sistema.o \
./src/Usuario.o \
./src/progPrincipal.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Artista.d ./src/Artista.o ./src/Cancion.d ./src/Cancion.o ./src/Fecha.d ./src/Fecha.o ./src/GestorArtistas.d ./src/GestorArtistas.o ./src/GestorUsuarios.d ./src/GestorUsuarios.o ./src/Playlist.d ./src/Playlist.o ./src/PruebaArtista.d ./src/PruebaArtista.o ./src/PruebaCancion.d ./src/PruebaCancion.o ./src/PruebaFecha.d ./src/PruebaFecha.o ./src/PruebaPlaylist.d ./src/PruebaPlaylist.o ./src/PruebaUsuario.d ./src/PruebaUsuario.o ./src/Sistema.d ./src/Sistema.o ./src/Usuario.d ./src/Usuario.o ./src/progPrincipal.d ./src/progPrincipal.o

.PHONY: clean-src

