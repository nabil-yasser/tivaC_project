# =============================================================================
# Filename: Makefile
# 
# Author: Nabil Yasser - Embedded Software Engineer
# 
# GitHub: https://github.com/nabil-yasser
#
# Brief : This file is used to build the project
#
# =============================================================================

# =========================================================================== #
# ================                 TOOLCHAINS                ================ #
# =========================================================================== #
CC						= avr-gcc
OBJCOPY					= avr-objcopy
OBJDUMP					= avr-objdump
AVRSIZE					= avr-size
AVRDUDE					= avrdude
PROGRAMMER				= usbasp
CPPCHECK				= cppcheck
FORMAT					= clang-format

# =========================================================================== #
# ================                DIRECTORIES                ================ #
# =========================================================================== #
BUILD_DIR				= build
OBJ_DIR					= $(BUILD_DIR)/obj
BIN_DIR					= $(BUILD_DIR)/bin
TARGET					= atmega16

# =========================================================================== #
# ================                 FILESNAME                 ================ #
# =========================================================================== #
SOURCES_HAS_HEADERS		= 
			  
SOURCES					= src/main.c \
						  $(SOURCES_HAS_HEADERS)
			  
HEADERS					= $(SOURCES_HAS_HEADERS:%.c=%.h)
OBJECTS					= $(SOURCES:%.c=$(OBJ_DIR)/%.o)
FORMAT_HEADERS			= src/utils/*.h\
						  src/config/*.h

# =========================================================================== #
# ================         COMPILING & LINKING FLAGS         ================ #
# =========================================================================== #
DEVICE					= 
F_CPU					= 
BAUD					= 

WFLAGS					= -Wall -Wextra -Wshadow -Wstrict-prototypes
CFLAGS					= -mmcu=$(DEVICE) -DF_CPU=$(F_CPU)UL -DBAUD=$(BAUD)
CFLAGS					+= $(WFLAGS) -Og -g -ggdb -std=gnu99
CFLAGS					+= -funsigned-char -funsigned-bitfields -fpack-struct
CFLAGS					+= -fshort-enums -ffunction-sections -fdata-sections

LDFLAGS					= -mmcu=$(DEVICE) -Wl,-Map,"$(BUILD_DIR)/main.map"
LDFLAGS					+= -Wl,--gc-sections -Wl,--relax

# =========================================================================== #
# ================       COMPILING & LINKING OPERATION       ================ #
# =========================================================================== #

## Hex file generator
$(TARGET).hex: $(TARGET).elf
	@$(OBJCOPY) -R .eeprom -O ihex $^ $@

## Linking
$(TARGET).elf: $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CC) $(LDFLAGS) $^ -o $@

## Compiling
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $^
	
# =========================================================================== #
# ================                  PHONIES                  ================ #
# =========================================================================== #
.PHONY: all flash clean size cppcheck format

all: $(TARGET).hex

clean:
	@rm -fr $(BUILD_DIR) *.elf *.hex

size: $(TARGET).elf
	@$(AVRSIZE) -C --mcu=$(DEVICE) $^

flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p m16 -u -U flash:w:$(TARGET).hex

cppcheck:
	@$(CPPCHECK) --quiet --inline-suppr --enable=all \
	--suppress=missingIncludeSystem --error-exitcode=1 $(SOURCES) 

format:
	@$(FORMAT) -i $(SOURCES) $(HEADERS) $(FORMAT_HEADERS)

# =========================================================================== #
# ================                END OF FILE                ================ #
# =========================================================================== #
