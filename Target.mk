# Makefile to compile for the target board.
# 
# Program name for executable
PROGRAM = DigitalClock

# Project Home Directoy
PROJECT_HOME_DIR ?= .

# --- Arduino specific ---
# Change based on Arduino board
MCU = atmega328p
CPU_FRQ = 16000000L
B_RATE = 115200
DEV = /dev/cu.usbmodem14101
CORE_DIR = $(PROJECT_HOME_DIR)/Library/Arduino-Core/cores/Arduino
RTC_DIR = $(PROJECT_HOME_DIR)/Library/DS3231
PINS_DIR = $(PROJECT_HOME_DIR)/Library/Arduino-Core/variants/standard/

# Build Directoy
BUILD_DIR ?= $(PROJECT_HOME_DIR)/Build
SOURCE_DIR ?= $(PROJECT_HOME_DIR)/Source
TARGET_HEX ?= $(BUILD_DIR)/$(PROGRAM).hex
TARGET_ELF ?= $(BUILD_DIR)/$(PROGRAM).elf

# Source directories
SRC_DIRS += \
	$(SOURCE_DIR)/ClockModel/ \
	$(SOURCE_DIR)/Timer/ \
	$(SOURCE_DIR)/ClockView/ \
	$(SOURCE_DIR)/Button/ \
	$(SOURCE_DIR)/ClockController/ \
	$(SOURCE_DIR)/Hardware/ \

# AVR toolchain
CXX = avr-g++
AR = avr-gcc-ar
CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE = avr-size

# Source files
SRC = $(wildcard $(SOURCE_DIR)/*/*.cpp)
CPP_SRC_CORE = $(wildcard $(CORE_DIR)/*.cpp)
C_SRC_CORE = $(wildcard $(CORE_DIR)/*.c)
S_SRC_CORE = $(wildcard $(CORE_DIR)/*.S)

# Object files
OBJ := \
	$(SRC:%=$(BUILD_DIR)/%.o) \
	$(CPP_SRC_CORE:%=$(BUILD_DIR)/%.o) \
	$(C_SRC_CORE:%=$(BUILD_DIR)/%.o) \
	$(S_SRC_CORE:%=$(BUILD_DIR)/%.o) \

# Dependencies
DEP := $(OBJ:.o=.d) 

ELF_FLAGS += \
	-w -Os -g \
	-flto \
	-fuse-linker-plugin \
	-Wl,--gc-sections \
	-mmcu=$(MCU) -o \

FLAGS += \
	-ffunction-sections \
	-fdata-sections \
	-fno-threadsafe-statics \
	-Wno-error=narrowing \
	-mmcu=$(MCU) \
	-DF_CPU=$(CPU_FRQ) \
	-DARDUINO=10608 \
	-MMD \
	-flto \
	-DARDUINO_AVR_UNO \
	-DARDUINO_ARCH_AVR \
	-I$(CORE_DIR) \
	-I$(PINS_DIR) \
	-I$(RTC_DIR) \
	$(patsubst %,-I%, $(SRC_DIRS)) \

# cpp flags
CXXFLAGS += \
	-c -g -Os -w \
	-Wall \
	-std=gnu++11 \
	-fpermissive \
	-fno-exceptions \
	$(FLAGS)

# c flags
CFLAGS += \
	-c -g -Os -w \
	-std=gnu11 \
	-ffunction-sections \
	-fdata-sections \
	-fno-fat-lto-objects \
	$(FLAGS) \

# assembly flags
SFLAGS += \
	-c -g -x assembler-with-cpp \
	$(FLAGS) \

$(TARGET_HEX): $(TARGET_ELF)
	$(OBJCOPY) -O ihex -R .eeprom  $(TARGET_ELF) $(TARGET_HEX)
	@echo "Finish Building Target: $(TARGET_HEX)"

$(TARGET_ELF): $(BUILD_DIR)/$(PROGRAM).cpp.o $(OBJ) $(BUILD_DIR)/core.a
	$(CC) $(ELF_FLAGS) $(TARGET_ELF) $(BUILD_DIR)/$(PROGRAM).cpp.o $(BUILD_DIR)/core.a -L. -lm

$(BUILD_DIR)/core.a: $(OBJ)

# Links all the object files
$(BUILD_DIR)/$(PROGRAM): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(PROGRAM)

# c++ Source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@
	$(AR) rcs $(BUILD_DIR)/core.a $@

# Build c Source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
	$(AR) rcs $(BUILD_DIR)/core.a $@

# Assembly source
$(BUILD_DIR)/%.S.o: %.S
	$(MKDIR_P) $(dir $@)
	$(CC) $(SFLAGS) $< -o $@
	$(AR) rcs $(BUILD_DIR)/core.a $@

# Cleans all the object files and program executable
.PHONY: clean
clean:
	@echo "Removing $(BUILD_DIR)";
	@$(RM) -r $(BUILD_DIR);

# Flashes the program.hex image into the arduino
.PHONY: flash
flash: $(TARGET_HEX)
	avrdude -v -p$(MCU) -carduino -P$(DEV) -b$(B_RATE) -D -Uflash:w:$(TARGET_HEX):i

# gets the size of the program.
.PHONY: size
size: $(TARGET_ELF)
	$(SIZE) -A $(TARGET_ELF)

.PHONY: help
help:
	@echo "\tflash: To flash the .hex file into target."
	@echo "\tsize: To get the size of executable file."

# include all Dependencies
-include $(DEP)

MKDIR_P ?= mkdir -p
RM ?= rm