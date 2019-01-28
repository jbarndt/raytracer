################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp 

OBJS += \
./main.o 

CPP_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -o "$@" "$<" -D__WXOSX_COCOA__ -D_FILE_OFFSET_BITS=64 -DwxDEBUG_LEVEL=0 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -I/usr/local/lib/wx/include/osx_cocoa-unicode-3.1 -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/World" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/build" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/UserInterface" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/BRDFs" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/BTDFs" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Cameras" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/GeometricObjects" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Lights" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Mappings" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Materials" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Noises" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Samplers" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Textures" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Tracers" -I"/Users/Jon/eclipse-workspace/wxRayTracer/raytracer/Utilities" -I/usr/local/include/wx-3.1 -O0 -g3 -Wall -c -fmessage-length=0 `usr/local/bin/wx-config --cppflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"
	@echo 'Finished building: $<'
	@echo ' '


