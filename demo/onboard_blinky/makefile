BIN_PATH = ~/toolchains/gcc-arm-none-eabi-9-2019-q4-major/bin
OPENOCD_PATH = /usr/local/Cellar/open-ocd/0.10.0/share/openocd
VFP_LIB_PATH = ~/toolchains/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/lib/thumb/v7e-m+fp/hard

CC = $(BIN_PATH)/arm-none-eabi-gcc
AS = $(BIN_PATH)/arm-none-eabi-as
LD = $(BIN_PATH)/arm-none-eabi-ld
AR = $(BIN_PATH)/arm-none-eabi-ar
OBJCOPY = $(BIN_PATH)/arm-none-eabi-objcopy
OBJDUMP = $(BIN_PATH)/arm-none-eabi-objdump

# 180 MHz SYSCLK, 180 MHZ AHB clk, 45 MHz APB1 clk, 90 MHz APB2 clk
C_FLAGS = \
	-O0 \
	-g \
	-Wall \
	-Werror \
	-std=c99 \
	-mthumb \
	-mcpu=cortex-m4 \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16 \
	-D __FPU_ENABLED \
	-D __SYS_CORE_CLK_SRC=sys_clk_src_PLL_HSE_P \
	-D __PLLP_FACTOR=2 \
	-D __PLLR_FACTOR=2 \
	-D __AHB_PRESCALER=1 \
	-D __APB1_PRESCALER=4 \
	-D __APB2_PRESCALER=2 \
	-I ../../core \
	-I ../../peripheral_library/public

LD_FLAGS = \
	-T ../../linker_scripts/default.ld \
	-nostartfiles \
	-Map output/linker_map.map \
	-L $(VFP_LIB_PATH) \
	-lc \
	-lg \
	-lm

.PHONY: clean

onboard_blinky.elf : startup_stm32f446re.o system_stm32f446re.o main.o onboard_led.o gpio.o
	@$(LD) $(LD_FLAGS) \
		output/startup_stm32f446re.o \
		output/system_stm32f446re.o \
		output/main.o \
		output/onboard_led.o \
		output/gpio.o \
		-o output/$@

onboard_blinky.bin : onboard_blinky.elf
	@$(OBJCOPY) -O binary output/onboard_blinky.elf output/$@

startup_stm32f446re.o : ../../startup/startup_stm32f446re.c
	@$(CC) $(C_FLAGS) -c $< \
		-o output/$@

system_stm32f446re.o : ../../startup/system_stm32f446re.c
	@$(CC) $(C_FLAGS) -c $< \
		-o output/$@

main.o : src/main.c
	@$(CC) $(C_FLAGS) -c $< \
		-o output/$@

onboard_led.o : ../../peripheral_library/private/onboard_led.c
	@$(CC) $(C_FLAGS) -c $< \
		-o output/$@

gpio.o : ../../peripheral_library/private/GPIO.c
	@$(CC) $(C_FLAGS) -c $< \
		-o output/$@

clean:
	-@rm -f output/*.o
	-@rm -f output/*.a
	-@rm -f output/*.map
	-@rm -f output/*.elf
	-@rm -f output/*.bin