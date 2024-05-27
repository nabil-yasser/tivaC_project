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
CC						= 
OBJCOPY					= 
OBJDUMP					= 
AVRSIZE					= 
AVRDUDE					= 
PROGRAMMER				= 
CPPCHECK				= cppcheck
FORMAT					= clang-format

# =========================================================================== #
# ================                DIRECTORIES                ================ #
# =========================================================================== #
BUILD_DIR				= build
OBJ_DIR					= $(BUILD_DIR)/obj
BIN_DIR					= $(BUILD_DIR)/bin
TARGET					= 

# =========================================================================== #
# ================                 FILESNAME                 ================ #
# =========================================================================== #
SOURCES_HAS_HEADERS		= src/mcal/mcu/mcu.c\
						  src/mcal/intCtrl/intCtrl.c\
						  src/mcal/io/io.c\

			  
SOURCES					= src/main.c \
						  $(SOURCES_HAS_HEADERS)
			  
HEADERS					= $(SOURCES_HAS_HEADERS:%.c=%.h)
OBJECTS					= $(SOURCES:%.c=$(OBJ_DIR)/%.o)
FORMAT_HEADERS			= src/config/*.c\
						  src/config/*.h

# =========================================================================== #
# ================         COMPILING & LINKING FLAGS         ================ #
# =========================================================================== #
DEVICE					= 
F_CPU					= 
BAUD					= 
	
# =========================================================================== #
# ================                  PHONIES                  ================ #
# =========================================================================== #
.PHONY: clean cppcheck format

clean:
	@rm -fr $(BUILD_DIR) *.elf *.hex

cppcheck:
	@$(CPPCHECK) --quiet --inline-suppr --enable=all \
	--suppress=missingIncludeSystem --error-exitcode=1 $(SOURCES) 

format:
	@$(FORMAT) -i $(SOURCES) $(HEADERS) $(FORMAT_HEADERS)

# =========================================================================== #
# ================                END OF FILE                ================ #
# =========================================================================== #
