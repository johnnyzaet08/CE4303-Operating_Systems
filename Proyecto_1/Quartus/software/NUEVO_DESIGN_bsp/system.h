/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'NUEVO_DESIGN'
 * SOPC Builder design path: ../../NUEVO_DESIGN.sopcinfo
 *
 * Generated: Mon Oct 02 11:38:28 CST 2023
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x04040020
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "small"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1b
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x04040020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 0
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INST_ADDR_WIDTH 0x1b
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x04040000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x04040020
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_DATA_ADDR_WIDTH 0x1b
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x04040020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 0
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INST_ADDR_WIDTH 0x1b
#define NIOS2_RESET_ADDR 0x04040000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS


/*
 * KEYS configuration
 *
 */

#define ALT_MODULE_CLASS_KEYS altera_avalon_pio
#define KEYS_BASE 0x4000070
#define KEYS_BIT_CLEARING_EDGE_REGISTER 0
#define KEYS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEYS_CAPTURE 0
#define KEYS_DATA_WIDTH 4
#define KEYS_DO_TEST_BENCH_WIRING 0
#define KEYS_DRIVEN_SIM_VALUE 0
#define KEYS_EDGE_TYPE "NONE"
#define KEYS_FREQ 50000000
#define KEYS_HAS_IN 1
#define KEYS_HAS_OUT 0
#define KEYS_HAS_TRI 0
#define KEYS_IRQ -1
#define KEYS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KEYS_IRQ_TYPE "NONE"
#define KEYS_NAME "/dev/KEYS"
#define KEYS_RESET_VALUE 0
#define KEYS_SPAN 16
#define KEYS_TYPE "altera_avalon_pio"


/*
 * LEDS configuration
 *
 */

#define ALT_MODULE_CLASS_LEDS altera_avalon_pio
#define LEDS_BASE 0x4000080
#define LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_CAPTURE 0
#define LEDS_DATA_WIDTH 10
#define LEDS_DO_TEST_BENCH_WIRING 0
#define LEDS_DRIVEN_SIM_VALUE 0
#define LEDS_EDGE_TYPE "NONE"
#define LEDS_FREQ 50000000
#define LEDS_HAS_IN 0
#define LEDS_HAS_OUT 1
#define LEDS_HAS_TRI 0
#define LEDS_IRQ -1
#define LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_IRQ_TYPE "NONE"
#define LEDS_NAME "/dev/LEDS"
#define LEDS_RESET_VALUE 0
#define LEDS_SPAN 16
#define LEDS_TYPE "altera_avalon_pio"


/*
 * RAM configuration
 *
 */

#define ALT_MODULE_CLASS_RAM altera_avalon_onchip_memory2
#define RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define RAM_BASE 0x4080000
#define RAM_CONTENTS_INFO ""
#define RAM_DUAL_PORT 0
#define RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define RAM_INIT_CONTENTS_FILE "NUEVO_DESIGN_RAM"
#define RAM_INIT_MEM_CONTENT 1
#define RAM_INSTANCE_ID "NONE"
#define RAM_IRQ -1
#define RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_NAME "/dev/RAM"
#define RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define RAM_RAM_BLOCK_TYPE "AUTO"
#define RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define RAM_SINGLE_CLOCK_OP 0
#define RAM_SIZE_MULTIPLE 1
#define RAM_SIZE_VALUE 160000
#define RAM_SPAN 160000
#define RAM_TYPE "altera_avalon_onchip_memory2"
#define RAM_WRITABLE 1


/*
 * ROM configuration
 *
 */

#define ALT_MODULE_CLASS_ROM altera_avalon_onchip_memory2
#define ROM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ROM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ROM_BASE 0x4040000
#define ROM_CONTENTS_INFO ""
#define ROM_DUAL_PORT 0
#define ROM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ROM_INIT_CONTENTS_FILE "NUEVO_DESIGN_ROM"
#define ROM_INIT_MEM_CONTENT 1
#define ROM_INSTANCE_ID "NONE"
#define ROM_IRQ -1
#define ROM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ROM_NAME "/dev/ROM"
#define ROM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ROM_RAM_BLOCK_TYPE "AUTO"
#define ROM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ROM_SINGLE_CLOCK_OP 0
#define ROM_SIZE_MULTIPLE 1
#define ROM_SIZE_VALUE 160000
#define ROM_SPAN 160000
#define ROM_TYPE "altera_avalon_onchip_memory2"
#define ROM_WRITABLE 0


/*
 * SDRAM configuration
 *
 */

#define ALT_MODULE_CLASS_SDRAM altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x0
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/SDRAM"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 7.8125
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 67108864
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.4
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 15.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 15.0
#define SDRAM_T_WR 14.0


/*
 * SEG1 configuration
 *
 */

#define ALT_MODULE_CLASS_SEG1 altera_avalon_pio
#define SEG1_BASE 0x4000060
#define SEG1_BIT_CLEARING_EDGE_REGISTER 0
#define SEG1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEG1_CAPTURE 0
#define SEG1_DATA_WIDTH 7
#define SEG1_DO_TEST_BENCH_WIRING 0
#define SEG1_DRIVEN_SIM_VALUE 0
#define SEG1_EDGE_TYPE "NONE"
#define SEG1_FREQ 50000000
#define SEG1_HAS_IN 0
#define SEG1_HAS_OUT 1
#define SEG1_HAS_TRI 0
#define SEG1_IRQ -1
#define SEG1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEG1_IRQ_TYPE "NONE"
#define SEG1_NAME "/dev/SEG1"
#define SEG1_RESET_VALUE 0
#define SEG1_SPAN 16
#define SEG1_TYPE "altera_avalon_pio"


/*
 * SEG2 configuration
 *
 */

#define ALT_MODULE_CLASS_SEG2 altera_avalon_pio
#define SEG2_BASE 0x4000050
#define SEG2_BIT_CLEARING_EDGE_REGISTER 0
#define SEG2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEG2_CAPTURE 0
#define SEG2_DATA_WIDTH 7
#define SEG2_DO_TEST_BENCH_WIRING 0
#define SEG2_DRIVEN_SIM_VALUE 0
#define SEG2_EDGE_TYPE "NONE"
#define SEG2_FREQ 50000000
#define SEG2_HAS_IN 0
#define SEG2_HAS_OUT 1
#define SEG2_HAS_TRI 0
#define SEG2_IRQ -1
#define SEG2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEG2_IRQ_TYPE "NONE"
#define SEG2_NAME "/dev/SEG2"
#define SEG2_RESET_VALUE 0
#define SEG2_SPAN 16
#define SEG2_TYPE "altera_avalon_pio"


/*
 * SEG3 configuration
 *
 */

#define ALT_MODULE_CLASS_SEG3 altera_avalon_pio
#define SEG3_BASE 0x4000040
#define SEG3_BIT_CLEARING_EDGE_REGISTER 0
#define SEG3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEG3_CAPTURE 0
#define SEG3_DATA_WIDTH 7
#define SEG3_DO_TEST_BENCH_WIRING 0
#define SEG3_DRIVEN_SIM_VALUE 0
#define SEG3_EDGE_TYPE "NONE"
#define SEG3_FREQ 50000000
#define SEG3_HAS_IN 0
#define SEG3_HAS_OUT 1
#define SEG3_HAS_TRI 0
#define SEG3_IRQ -1
#define SEG3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEG3_IRQ_TYPE "NONE"
#define SEG3_NAME "/dev/SEG3"
#define SEG3_RESET_VALUE 0
#define SEG3_SPAN 16
#define SEG3_TYPE "altera_avalon_pio"


/*
 * SEG4 configuration
 *
 */

#define ALT_MODULE_CLASS_SEG4 altera_avalon_pio
#define SEG4_BASE 0x4000030
#define SEG4_BIT_CLEARING_EDGE_REGISTER 0
#define SEG4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEG4_CAPTURE 0
#define SEG4_DATA_WIDTH 7
#define SEG4_DO_TEST_BENCH_WIRING 0
#define SEG4_DRIVEN_SIM_VALUE 0
#define SEG4_EDGE_TYPE "NONE"
#define SEG4_FREQ 50000000
#define SEG4_HAS_IN 0
#define SEG4_HAS_OUT 1
#define SEG4_HAS_TRI 0
#define SEG4_IRQ -1
#define SEG4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEG4_IRQ_TYPE "NONE"
#define SEG4_NAME "/dev/SEG4"
#define SEG4_RESET_VALUE 0
#define SEG4_SPAN 16
#define SEG4_TYPE "altera_avalon_pio"


/*
 * SEG5 configuration
 *
 */

#define ALT_MODULE_CLASS_SEG5 altera_avalon_pio
#define SEG5_BASE 0x4000020
#define SEG5_BIT_CLEARING_EDGE_REGISTER 0
#define SEG5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEG5_CAPTURE 0
#define SEG5_DATA_WIDTH 7
#define SEG5_DO_TEST_BENCH_WIRING 0
#define SEG5_DRIVEN_SIM_VALUE 0
#define SEG5_EDGE_TYPE "NONE"
#define SEG5_FREQ 50000000
#define SEG5_HAS_IN 0
#define SEG5_HAS_OUT 1
#define SEG5_HAS_TRI 0
#define SEG5_IRQ -1
#define SEG5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEG5_IRQ_TYPE "NONE"
#define SEG5_NAME "/dev/SEG5"
#define SEG5_RESET_VALUE 0
#define SEG5_SPAN 16
#define SEG5_TYPE "altera_avalon_pio"


/*
 * SEG6 configuration
 *
 */

#define ALT_MODULE_CLASS_SEG6 altera_avalon_pio
#define SEG6_BASE 0x4000010
#define SEG6_BIT_CLEARING_EDGE_REGISTER 0
#define SEG6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEG6_CAPTURE 0
#define SEG6_DATA_WIDTH 7
#define SEG6_DO_TEST_BENCH_WIRING 0
#define SEG6_DRIVEN_SIM_VALUE 0
#define SEG6_EDGE_TYPE "NONE"
#define SEG6_FREQ 50000000
#define SEG6_HAS_IN 0
#define SEG6_HAS_OUT 1
#define SEG6_HAS_TRI 0
#define SEG6_IRQ -1
#define SEG6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEG6_IRQ_TYPE "NONE"
#define SEG6_NAME "/dev/SEG6"
#define SEG6_RESET_VALUE 0
#define SEG6_SPAN 16
#define SEG6_TYPE "altera_avalon_pio"


/*
 * SW configuration
 *
 */

#define ALT_MODULE_CLASS_SW altera_avalon_pio
#define SW_BASE 0x4000000
#define SW_BIT_CLEARING_EDGE_REGISTER 0
#define SW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SW_CAPTURE 0
#define SW_DATA_WIDTH 10
#define SW_DO_TEST_BENCH_WIRING 0
#define SW_DRIVEN_SIM_VALUE 0
#define SW_EDGE_TYPE "NONE"
#define SW_FREQ 50000000
#define SW_HAS_IN 1
#define SW_HAS_OUT 0
#define SW_HAS_TRI 0
#define SW_IRQ -1
#define SW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SW_IRQ_TYPE "NONE"
#define SW_NAME "/dev/SW"
#define SW_RESET_VALUE 0
#define SW_SPAN 16
#define SW_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/null"
#define ALT_STDERR_BASE 0x0
#define ALT_STDERR_DEV null
#define ALT_STDERR_TYPE ""
#define ALT_STDIN "/dev/null"
#define ALT_STDIN_BASE 0x0
#define ALT_STDIN_DEV null
#define ALT_STDIN_TYPE ""
#define ALT_STDOUT "/dev/null"
#define ALT_STDOUT_BASE 0x0
#define ALT_STDOUT_DEV null
#define ALT_STDOUT_TYPE ""
#define ALT_SYSTEM_NAME "NUEVO_DESIGN"


/*
 * TIMER configuration
 *
 */

#define ALT_MODULE_CLASS_TIMER altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x40000a0
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 50000000
#define TIMER_IRQ 0
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 49999
#define TIMER_MULT 0.001
#define TIMER_NAME "/dev/TIMER"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none

#endif /* __SYSTEM_H_ */
