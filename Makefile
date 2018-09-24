SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .o

CFLAGS   = -Wall -Wextra -mtune=native
WARN_OFF = -Wno-implicit-function-declaration
CFLAGS1  = $(CFLAGS) $(WARN_OFF)
LDFLAGS  = 
LDFLAGS1 = $(LDFLAGS)  -lm
srcdir	 =./
builddir =build/

TARGETS	 = stat pipe

.PHONY: all
all: $(TARGETS)

# use of stat
stat: $(srcdir)stat.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)
pipe: $(srcdir)pipe.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)
.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true

