
MKDIR=mkdir -p
RM=rm -f
CP=cp -r

WIN_EXE_CC=i686-w64-mingw32-gcc -m32 -o
LIN_EXE_CC=gcc -o

FONTES=$(wildcard *.c)
RESPOSTAS=$(wildcard *.txt)
ALVOS_WIN=$(patsubst %.c,%.exe,$(FONTES))
ALVOS_LIN=$(patsubst %.c,%_lin,$(FONTES))

all: _build

_build: $(ALVOS_WIN) $(ALVOS_LIN)

_install: _build
	$(MKDIR) "$(PASTA_INSTALACAO)/$(SUBPASTA)"
	$(CP) $(ALVOS_LIN) $(ALVOS_WIN) $(FONTES) $(RESPOSTAS) "$(PASTA_INSTALACAO)/$(SUBPASTA)"

_clean:
	$(RM) $(ALVOS_WIN)
	$(RM) $(ALVOS_LIN)

.SUFFIXES=.c .exe .lin

%.exe: %.c
	$(WIN_EXE_CC) $@ $< $(CFLAGS)

%_lin: %.c
	$(LIN_EXE_CC) $@ $< $(CFLAGS)

