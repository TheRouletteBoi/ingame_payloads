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
CFLAGS 		:= $(foreach dir,$(IDIRS),-I$(dir)) -O3 -Wall -fno-builtin -fno-exceptions -ffunction-sections -fdata-sections -ffreestanding -std=gnu99 -m64
LFLAGS		:= -T Linker -nostartfiles -nostdlib -nodefaultlibs -Wl,-static -Wl,-s -L. $(foreach dir,$(IDIRS),-I$(dir)) -Wl,--gc-sections -Wl
SFLAGS  	= 
CFILES		:= $(shell find $(SDIR) -name \*.c)
SFILES		:= $(shell find $(SDIR) -name \*.s)
OBJS 		:= $(patsubst $(SDIR)/%,$(ODIR)/%,$(CFILES:.c=.o)) $(patsubst $(SDIR)/%,$(ODIR)/%,$(SFILES:.s=.o))

TARGET		= $(ODIR)/$(notdir $(CURDIR)).elf
	
$(TARGET): $(ODIR) $(OBJS) Linker
	$(CC) $(LFLAGS) -o $@ $(ODIR)/crt0.o $(OBJS)
	$(OBJCOPY) -O binary $(ODIR)/$(notdir $(CURDIR)).elf $(ODIR)/$(notdir $(CURDIR)).bin
	@rm -f $(TARGET) $(ODIR)/*.o
	
$(ODIR)/%.o: $(SDIR)/%.s
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $(ODIR)/crt0.o crt0.s
	$(CC) $(CFLAGS) -c -o $@ $<

$(ODIR):
	@mkdir $@
	
.PHONY: clean

clean:
	rm -f $(TARGET) $(ODIR)/*.o $(ODIR)/*.bin
