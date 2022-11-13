CC			:= ppu-gcc
CXX			:= ppu-g++
LD			:= ppu-ld 
OBJCOPY		:= ppu-objcopy
AR 			:= ppu-ar
STRIP		:= ppu-strip
ODIR    	:= bin
SDIR    	:= src
LIBSDIR		=
LIBS 		=
IDIRS		:= $(PS3DEV)/ppu/ppu/include
CFLAGS 		:= $(foreach dir,$(IDIRS),-I$(dir)) -O2 -Wall -mcpu=cell -fno-builtin -fno-exceptions -fdata-sections -ffunction-sections -std=gnu++0x
LFLAGS		:= -T Linker -nostartfiles -nostdlib -nodefaultlibs -Wl,-s -L. $(foreach dir,$(IDIRS),-I$(dir)) -Wl,--gc-sections
SFLAGS  	= 
CFILES		:= $(shell find $(SDIR) -name \*.cpp)
SFILES		:= $(shell find $(SDIR) -name \*.s)
OBJS 		:= $(patsubst $(SDIR)/%,$(ODIR)/%,$(CFILES:.cpp=.o)) $(patsubst $(SDIR)/%,$(ODIR)/%,$(SFILES:.s=.o))

TARGET		= $(ODIR)/$(notdir $(CURDIR)).elf
	
$(TARGET): $(ODIR) $(OBJS) Linker
	$(CXX) $(LFLAGS) -o $@ $(ODIR)/crt0.o $(OBJS)
	$(OBJCOPY) -O binary $(ODIR)/$(notdir $(CURDIR)).elf $(ODIR)/$(notdir $(CURDIR)).bin
	@rm -f $(TARGET) $(ODIR)/*.o
	
$(ODIR)/%.o: $(SDIR)/%.s
	$(CXX) $(CFLAGS) -c -o $@ $<
	
$(ODIR)/%.o: $(SDIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CFLAGS) -c -o $(ODIR)/crt0.o crt0.s
	$(CXX) $(CFLAGS) -c -o $@ $<

$(ODIR):
	@mkdir $@
	
.PHONY: clean

clean:
	rm -f $(TARGET) $(ODIR)/*.o $(ODIR)/*.bin
