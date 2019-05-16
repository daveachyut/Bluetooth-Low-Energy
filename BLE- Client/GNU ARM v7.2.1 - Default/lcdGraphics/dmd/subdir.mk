################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcdGraphics/dmd/dmd_display.c 

OBJS += \
./lcdGraphics/dmd/dmd_display.o 

C_DEPS += \
./lcdGraphics/dmd/dmd_display.d 


# Each subdirectory must supply rules for building sources it contributes
lcdGraphics/dmd/dmd_display.o: ../lcdGraphics/dmd/dmd_display.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__StackLimit=0x20000000' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG13P632F512GM48=1' -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//util/silicon_labs/silabs_core/graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.3//platform/middleware/glib/glib" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\emdrv\uartdrv\inc" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\halconfig\inc\hal-config" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\bootloader\api" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\hardware\kit\common\drivers" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\app\bluetooth\common\stack_bridge" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\radio\rail_lib\common" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\emdrv\sleep\inc" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\protocol\bluetooth\ble_stack\inc\common" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\Device\SiliconLabs\EFR32BG13P\Source\GCC" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\emdrv\common\inc" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\protocol\bluetooth\ble_stack\inc\soc" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\emdrv\sleep\src" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\emlib\src" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\Device\SiliconLabs\EFR32BG13P\Include" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\radio\rail_lib\chip\efr32" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\emlib\inc" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\bootloader" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\CMSIS\Include" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\hardware\kit\EFR32BG13_BRD4104A\config" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\Device\SiliconLabs\EFR32BG13P\Source" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\hardware\kit\common\bsp" -I"C:\Users\achyu\Desktop\Assign 5\BLE- Client\hardware\kit\common\halconfig" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"lcdGraphics/dmd/dmd_display.d" -MT"lcdGraphics/dmd/dmd_display.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


