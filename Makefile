CD=cd
RMDIR=rm -rf
MKDIR=mkdir -p
ZIP=zip -r

NOME_PROJETO=uva-monitoria-estruturas
PASTA_RAIZ=$(shell pwd)
PASTA_INSTALACAO=$(PASTA_RAIZ)/$(NOME_PROJETO)
NOME_DIST_ZIP=$(NOME_PROJETO).zip

CFLAGS=--std=c99 -Wall -s -O2

SUBREGRAS= \
	_build \
	_install \
	_clean
SUBPASTAS= \
	estruturas1/listas \
	estruturas1/listas/respostas

all: dist

build:
	$(MAKE) "_$@"

install: build
	$(MKDIR) $(PASTA_INSTALACAO)
	$(MAKE) "_$@"

dist: install
	$(CD) $(PASTA_INSTALACAO)/..
	$(ZIP) $(NOME_DIST_ZIP) $(notdir $(PASTA_INSTALACAO))

clean:
	$(RMDIR) $(PASTA_INSTALACAO)
	$(RMDIR) $(NOME_DIST_ZIP)
	$(MAKE) "_$@"

$(SUBREGRAS):
	for pasta in $(SUBPASTAS); do \
		$(CD) "$(PASTA_RAIZ)/$$pasta"; \
		$(MAKE) $@ \
			SUBPASTA="$$pasta"                         \
			PASTA_RAIZ="$(PASTA_RAIZ)"              \
			PASTA_INSTALACAO="$(PASTA_INSTALACAO)" \
			CFLAGS="$(CFLAGS)"; \
	done; \
	$(CD) $(PASTA_RAIZ);
