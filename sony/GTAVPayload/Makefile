CC			:= ppu-lv2-gcc
CXX			:= ppu-lv2-g++
LD			:= ppu-lv2-ld
OBJCOPY		:= ppu-lv2-objcopy
AR 			:= ppu-lv2-ar
STRIP		:= ppu-lv2-strip
ODIR    	:= bin
SDIR    	:= src
LIBSDIR		=
LIBS 		=
IDIRS		:= $(PS3DEV)/ppu/ppu/include
CFLAGS 		:= $(foreach dir,$(IDIRS),-I$(dir)) -O2 -Wall -mcpu=cell -fno-builtin -fno-exceptions -fdata-sections -ffunction-sections -std=gnu++98
LFLAGS		:= -T Linker -nostartfiles -nostdlib -nodefaultlibs -Wl,-s -L. $(foreach dir,$(IDIRS),-I$(dir))
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
