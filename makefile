BIN_PATH = ~/toolchains/gcc-arm-none-eabi-9-2019-q4-major/bin
OPENOCD_PATH = /usr/local/Cellar/open-ocd/0.10.0/share/openocd
VFP_LIB_PATH = ~/toolchains/gcc-arm-none-eabi-9-2019-q4-major/arm-none-eabi/lib/thumb/v7e-m+fp/hard

CC = $(BIN_PATH)/arm-none-eabi-gcc
AS = $(BIN_PATH)/arm-none-eabi-as
LD = $(BIN_PATH)/arm-none-eabi-ld
AR = $(BIN_PATH)/arm-none-eabi-ar
OBJCOPY = $(BIN_PATH)/arm-none-eabi-objcopy
OBJDUMP = $(BIN_PATH)/arm-none-eabi-objdump

# General C compilation flags
C_FLAGS = \
	-O0 \
	-g \
	-Wall \
	-Werror \
	-std=c99

# Cortex-M4 specific flags to set code execution state (thumb vs ARM) and the target's architecture
C_FLAGS += \
	-mthumb \
	-mcpu=cortex-m4

# Cortex-M4 floating point flags
#
# -mfloat-abi=soft/softfp/hard
#     soft
#     The compiler will not generate HW FPU instructions and will instead resort to full SW emulation for floating-
#     point support. This emulation is done through calls to soft float library routines found within the internal
#     SW floating point library GCC was configured to use. The compiler will also generate prologue and epilogue
#     functions to pass the floating point arguments via integer registers (i.e. following the soft float ABI
#     calling convention).
#
#     softfp
#     The compiler will generate HW FPU instructions but will still use the soft float ABI calling convention. Code
#     generated from the soft and softfp float ABIs are compatible with one another because they utilize the same
#     calling convention.
#
#     hard
#     The compiler will generate HW FPU instructions and use the floating point ABI (i.e. floating point function
#     arguments are passed directly into the FPU registers). When using this option, you must specify an FPU using
#     the -mfpu option.
#
# -mfpu=fpv4-sp-d16
#     Specifies the type of floating-point hardware (or emulation) available on the target. In this case, the FPU
#     specified conforms to the fpv4-sp (i.e. single precision variant of the FPv4 architecture, see
#     https://www.keil.com/support/man/docs/armlink/armlink_pge1362075484206.htm for more details) architecture and
#     has 16 double-precision registers (the d16 portion of the argument).
#
# -D __FPU_ENABLED
#     #define for startup C code to enable the FPU coprocessor.
C_FLAGS += \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16 \
	-D __FPU_ENABLED

# System clock source selection and configuration (via -D of __SYS_CORE_CLK_SRC macro)
#|-----------------------|------------------------|------------------------------|--------------------------------|
#| -D value              | PLL P/R Prescalers     | Resultant SYSCLK Frequencies | System Clock Source            |
#|-----------------------|------------------------|------------------------------|--------------------------------|
#| sys_clk_src_HSI       | N/A                    | 16 MHz                       | High-speed internal oscillator |
#| sys_clk_src_HSE       | N/A                    | 8  MHz                       | High-speed external crystal    |
#| sys_clk_src_HSE_BYP   | N/A                    | N/A                          | External user-provided clock   |
#| sys_clk_src_PLL_HSE_P | 2, 4, 6, 8             | 180, 90, 60, 45 MHz          | PLL (clocked by HSE) P output  |
#| sys_clk_src_PLL_HSE_R | 2, 3, 4, 5, 6, 7       | 180, 120, 90, 72, 60, 51 MHz | PLL (clocked by HSE) R output  |
#| sys_clk_src_PLL_HSI_P | 2, 4, 6, 8             | 180, 90, 60, 45 MHz          | PLL (clocked by HSI) P output  |
#| sys_clk_src_PLL_HSI_R | 2, 3, 4, 5, 6, 7       | 180, 120, 90, 72, 60, 51 MHz | PLL (clocked by HSI) R output  |
#|-----------------------|------------------------|------------------------------|--------------------------------|
C_FLAGS += \
	-D __SYS_CORE_CLK_SRC=sys_clk_src_PLL_HSE_P \
	-D __PLLP_FACTOR=2 \
	-D __PLLR_FACTOR=2

# System bus frequency selection (via -D of __AHB_PRESCALER, __APB1_PRESCALER, and __APB2_PRESCALER)
#|----------------|-----------------------------------|------------------------------------------------------|
#| Prescalers     | AHB Frequency Division Factor     | Notes                                                |
#|----------------|-----------------------------------|------------------------------------------------------|
#| AHB Prescaler  | 1, 2, 4, 8, 16, 64, 128, 256, 512 | Divides system clk by the value                      |
#| APB1 Prescaler | 1, 2, 4, 8, 16                    | Divides AHB clk by the value, APB1 must be <= 45 MHz |
#| APB2 Prescaler | 1, 2, 4, 8, 16                    | Divides AHB clk by the value, APB2 must be <= 90 MHz |
#|----------------|-----------------------------------|------------------------------------------------------|
C_FLAGS += \
	-D __AHB_PRESCALER=1 \
	-D __APB1_PRESCALER=1 \
	-D __APB2_PRESCALER=1

# Directories
C_FLAGS += \
	-I ../../core \
	-I ../..

# Linker flags
LD_FLAGS = \
	-T ../../linker_scripts/default.ld \
	-nostartfiles \
	-Map output/linker_map.map

# Linker library search paths
LD_FLAGS += \
	-L $(VFP_LIB_PATH)
#     ^^^ This library path is needed for VFP compatible c, gcc, and math libraries when the FPU is used

# Linker libraries
LD_FLAGS += \
	-lc \
	-lg \
	-lm

.PHONY: clean

libdartlead.a : startup_stm32f446re.o
	@$(AR) cr $@ startup_stm32f446re.o

startup_stm32f446re.o : startup/startup_stm32f446re.c
	@$(CC) $(C_FLAGS) -c startup/startup_stm32f446re.c \
		-o startup_stm32f446re.o

clean:
	-@rm -f *.o
	-@rm -f *.a
	-@rm -f *.map
	-@rm -f *.elf
	-@rm -f *.bin