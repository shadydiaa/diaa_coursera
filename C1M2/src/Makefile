#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple make file for building system on two platforms :
#       1)the host environment 
#       2)the target embedded system MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated file
#
# Platform Overrides:
#      PLATFORM - Target platform (HOST, MSP432)
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Architectures Specific Flags
CPU = cortex-m4 
ARCH = thumb
SPECS = nosys.specs
  
# Compiler Flags and Defines
CC = gcc
LD = ld
BASENAME=c1m2
TARGET=$(BASENAME).out
CFLAGS = -Wall -Werror -g -O0 -std=c99
LDFLAGS = -Wl,-Map=$(BASENAME).map
		 
# Switch between HOST and MSP432
ifeq ($(PLATFORM),MSP432)
	CC=arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LINKER_FILE =../msp432p401r.lds
	CFLAGS+=-mcpu=$(CPU) -m$(ARCH) -specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	LDFLAGS+=-T$(LINKER_FILE) 
	SOURCES=$(MSP432_SOURCES)
	CPPFLAGS=$(MSP432_INCLUDES)
	OBJDUMP = arm-none-eabi-objdump
	size = arm-none-eabi-size
else 
	CC=gcc
	SOURCES=$(HOST_SOURCES)
	CPPFLAGS=$(HOST_INCLUDES)
	OBJDUMP = objdump
	size = size
endif

# Generate object and dependency files 
OBJS=$(SOURCES:.c=.o)
DEPS=$(SOURCES:.c=.d)

# Generate the preprocessed output of all c-program implementation files
%.i:%.c
	$(CC)  $(CFLAGS) $(CPPFLAGS) -D$(PLATFORM) -E $^ -o $@

# Generate assembly output of c-program implementation files and the final output executable
%.asm:%.c
	$(CC)  $(CFLAGS) $(CPPFLAGS) -D$(PLATFORM) -S $^ -o $@

# Generate the object file for all c-source files
%.o:%.c
	$(CC)  $(CFLAGS) $(CPPFLAGS) -D$(PLATFORM) -c $^ -o $@

# Generate dependency Files for each source file 
%.d:%.c
	$(CC)  $(CFLAGS) $(CPPFLAGS) -D$(PLATFORM) -c $^ -o $@

$(BASENAME).asm : $(TARGET)
	$(OBJDUMP) -d $(TARGET) >> $@


# Generate object and dependency files but not linking 
.PHONY:compile-all
compile-all:$(OBJS) $(DEPS)

# Generate object and dependency files with linking and generate output executable file 
.PHONY:build 
build:$(TARGET)
$(TARGET):$(OBJS) $(DEPS) 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -D$(PLATFORM) $(OBJS) -o $@
	$(size) $(TARGET)


# Remove all generated files 
.PHONY:clean
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS) *.i *.asm $(BASENAME).map