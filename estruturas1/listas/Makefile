
MKDIR=mkdir -p
RM=rm -f
CP=cp -r

ARQUIVOS=$(wildcard *.docx *.doc)

_build:
	# Nada a fazer.

_install: _build
	$(MKDIR) "$(PASTA_INSTALACAO)/$(SUBPASTA)"
	$(CP) $(ARQUIVOS) "$(PASTA_INSTALACAO)/$(SUBPASTA)"

_clean:
	# Nada a fazer.

