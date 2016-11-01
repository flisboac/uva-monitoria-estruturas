#include <stdio.h>
#include <stdlib.h>

#define NEW(_tipo_, _qtd_) alocarMemoria(sizeof(_tipo_), _qtd_)

#define PUSH(_pilha_, _n_, _k_) \
	(_pilha_)->dados[(_pilha_)->tamanho].n = _n_; \
	(_pilha_)->dados[(_pilha_)->tamanho++].k = _k_

#define POP(_pilha_) (_pilha_)->dados[--(_pilha_)->tamanho]

typedef struct NoPilha {
	
	int n;
	int k;
} NoPilha;


typedef struct Pilha {

	NoPilha* dados;
	size_t capacidade;
	size_t tamanho;
	int resultado;
} Pilha;


static int Comb(int n, int k);

static void* alocarMemoria(size_t tamanhoElemento, size_t qtdElementos);
static Pilha* Comb_iniciar(int n, int k);
static int Comb_iterar(Pilha* pilha);
static void Comb_imprimir(Pilha* pilha);
static void Comb_finalizar(Pilha* pilha);


int main(void) {
	
	int n = 5;
	int k = 3;
	int r = Comb(n, k);
	printf("Comb(%d, %d) = %d\n", n, k, r);
	return 0;
}


int Comb(int n, int k) {
	Pilha* pilha = Comb_iniciar(n, k);

	do {
		Comb_imprimir(pilha);
	} while (!Comb_iterar(pilha));

	Comb_finalizar(pilha);
	return pilha->resultado;
}


Pilha* Comb_iniciar(int n, int k) {

	Pilha* pilha;

	// Deliberadamente "tratando" dos erros de alocação em alocarMemoria, para melhor
	// entendimento do algoritmo
	pilha = NEW(Pilha, 1);
	pilha->capacidade = 0;
	pilha->tamanho = 0;
	pilha->resultado = 0;

	if (k >= 1 && n >= k) {
		pilha->capacidade = n - 2;
		pilha->dados = NEW(NoPilha, pilha->capacidade);

		PUSH(pilha, n, k);
	}

	return pilha;
}


int Comb_iterar(Pilha* pilha) {
	NoPilha chamadaAtual;
	int n, k;

	if (pilha->tamanho != 0) {
		chamadaAtual = POP(pilha);
		n = chamadaAtual.n;
		k = chamadaAtual.k;

		if (k == 1) {
			pilha->resultado += n;

		} else if (n == k) {
			pilha->resultado += 1;

		} else {
			PUSH(pilha, n - 1, k - 1);
			PUSH(pilha, n - 1, k);
		}
	}

	return pilha->tamanho == 0;
}


void Comb_imprimir(Pilha* pilha) {
	size_t i;
	NoPilha* ultimo = NULL;

	if (pilha->tamanho > 0) {
		ultimo = &pilha->dados[pilha->tamanho - 1];
	}

	for (i = 0; i < pilha->tamanho - 1; ++i) printf("  ");

	if (ultimo != NULL) {
		printf("Nível: %lu, Resultado: %d - COMB(%d, %d)\n",
			(unsigned long) pilha->tamanho, pilha->resultado,
			ultimo->n, ultimo->k);

	} else {
		printf("Nível: %lu, Resultado: %d\n",
			(unsigned long) pilha->tamanho, pilha->resultado);
	}
}


void Comb_finalizar(Pilha* pilha) {
	free(pilha->dados);
	free(pilha);
}


void* alocarMemoria(size_t tamanhoElemento, size_t qtdElementos) {
	void* retorno = malloc(tamanhoElemento * qtdElementos);
	if (retorno == NULL) {
		printf("Erro ao alocar memória.\n");
		exit(EXIT_FAILURE);
	}
	return retorno;
}
