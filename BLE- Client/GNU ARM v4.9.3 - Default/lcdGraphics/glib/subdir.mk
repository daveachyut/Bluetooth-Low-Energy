################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcdGraphics/glib/bmp.c \
../lcdGraphics/glib/glib.c \
../lcdGraphics/glib/glib_bitmap.c \
../lcdGraphics/glib/glib_circle.c \
../lcdGraphics/glib/glib_font_narrow_6x8.c \
../lcdGraphics/glib/glib_font_normal_8x8.c \
../lcdGraphics/glib/glib_font_number_16x20.c \
../lcdGraphics/glib/glib_line.c \
../lcdGraphics/glib/glib_polygon.c \
../lcdGraphics/glib/glib_rectangle.c \
../lcdGraphics/glib/glib_string.c 

OBJS += \
./lcdGraphics/glib/bmp.o \
./lcdGraphics/glib/glib.o \
./lcdGraphics/glib/glib_bitmap.o \
./lcdGraphics/glib/glib_circle.o \
./lcdGraphics/glib/glib_font_narrow_6x8.o \
./lcdGraphics/glib/glib_font_normal_8x8.o \
./lcdGraphics/glib/glib_font_number_16x20.o \
./lcdGraphics/glib/glib_line.o \
./lcdGraphics/glib/glib_polygon.o \
./lcdGraphics/glib/glib_rectangle.o \
./lcdGraphics/glib/glib_string.o 

C_DEPS += \
./lcdGraphics/glib/bmp.d \
./lcdGraphics/glib/glib.d \
./lcdGraphics/glib/glib_bitmap.d \
./lcdGraphics/glib/glib_circle.d \
./lcdGraphics/glib/glib_font_narrow_6x8.d \
./lcdGraphics/glib/glib_font_normal_8x8.d \
./lcdGraphics/glib/glib_font_number_16x20.d \
./lcdGraphics/glib/glib_line.d \
./lcdGraphics/glib/glib_polygon.d \
./lcdGraphics/glib/glib_rectangle.d \
./lcdGraphics/glib/glib_string.d 


# Each subdirectory must supply rules for building sources it contributes
lcdGraphics/glib/bmp.o: ../lcdGraphics/glib/bmp.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/bmp.d" -MT"lcdGraphics/glib/bmp.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib.o: ../lcdGraphics/glib/glib.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib.d" -MT"lcdGraphics/glib/glib.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_bitmap.o: ../lcdGraphics/glib/glib_bitmap.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_bitmap.d" -MT"lcdGraphics/glib/glib_bitmap.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_circle.o: ../lcdGraphics/glib/glib_circle.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_circle.d" -MT"lcdGraphics/glib/glib_circle.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_font_narrow_6x8.o: ../lcdGraphics/glib/glib_font_narrow_6x8.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_font_narrow_6x8.d" -MT"lcdGraphics/glib/glib_font_narrow_6x8.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_font_normal_8x8.o: ../lcdGraphics/glib/glib_font_normal_8x8.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_font_normal_8x8.d" -MT"lcdGraphics/glib/glib_font_normal_8x8.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_font_number_16x20.o: ../lcdGraphics/glib/glib_font_number_16x20.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_font_number_16x20.d" -MT"lcdGraphics/glib/glib_font_number_16x20.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_line.o: ../lcdGraphics/glib/glib_line.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_line.d" -MT"lcdGraphics/glib/glib_line.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_polygon.o: ../lcdGraphics/glib/glib_polygon.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_polygon.d" -MT"lcdGraphics/glib/glib_polygon.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_rectangle.o: ../lcdGraphics/glib/glib_rectangle.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_rectangle.d" -MT"lcdGraphics/glib/glib_rectangle.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcdGraphics/glib/glib_string.o: ../lcdGraphics/glib/glib_string.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/glib/glib_string.d" -MT"lcdGraphics/glib/glib_string.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


