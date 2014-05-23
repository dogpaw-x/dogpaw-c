DEBUG = 1
.PHONY: all clean

CFLAGS = -Wall
ifeq ($(DEBUG), 1)
	CFLAGS += -Wextra -DDEBUG=1
else
	CFLAGS += -DDEBUG=0
endif

SRCDIR = src
SRC := $(wildcard $(SRCDIR)/*.c)
SRCNAM := $(notdir $(SRC))
ODIR := obj
OBJ := $(patsubst %.c,$(ODIR)/%.o,$(SRCNAM))
TARGET = dogpaw

all: $(TARGET)

dogpaw: $(OBJ)
	$(CC) $^ -o $@

$(OBJ): Makefile | $(ODIR)

$(ODIR):
	@mkdir $@

$(ODIR)/%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -rf $(ODIR)/*.o $(TARGET)

sinclude $(SRC:.c=.d)

%.d: %.c
	@set -e; rm -f $@; \
		$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
		sed 's,\(.*\)\.o[:]*,$(ODIR)/\1.o $@:,' < $@.$$$$ > $@; \
		rm -f $@.$$$$

vpath %.c src
vpath %.h src
vpath %.o obj
