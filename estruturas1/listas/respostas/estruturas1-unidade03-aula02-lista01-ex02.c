#include <stdio.h>


#define TAMANHO(V, T) (sizeof(V) / sizeof(T))

// Protótipos das funções solicitadas no enunciado da questão.
// Veja a implementação de cada uma delas no fim do código-fonte.
static int Max_recursivo(const int* inicio, const int* fim);
static int Max_iterativo(const int* inicio, const int* fim);


int main(void) {

	// Nosso vetor.
	int vetor[] = { 2, 4, 1, 3, 9 };
	const size_t tamanho = TAMANHO(vetor, int);

	// Os "iteradores".
	// fim neste caso aponta para o elemento após o último!
	// Ou seja:
	// - se tamanho = 5
	//   ([0] [1] [2] [3] [4]) [ ] [ ] [ ] [ ] ...
	//     ^               ^    ^-- : fim = &vetor[tamanho]
	//     |               `------- : último = &vetor[tamanho - 1]
	//     `------------------------: início = vetor
	// Dereferenciar fim é um erro, pois estaremos dereferenciando memória
	// não alocada.
	const int* inicio = vetor;
	const int* fim = vetor + tamanho;

	// Calculando...
	int max_r = Max_recursivo(inicio, fim);
	int max_i = Max_iterativo(inicio, fim);

	// Mostrando resultados
	printf("Max_recursivo = %d\n", max_r);
	printf("Max_iterativo = %d\n", max_i);
	return 0;
}


int Max_iterativo(const int* inicio, const int* fim) {
	const int* max = inicio;

	for (; inicio != fim; ++inicio) {
		if (*inicio > *max) {
			max = inicio;
		}
	}

	return *max;
}


// Uma função auxiliar
static int Max_recursivo_aux(const int* inicio, const int* fim, const int* maior) {

	if (inicio == fim) return (*maior);   // Chegamos ao último. É a nossa condição de parada.
	if (*inicio > *maior) maior = inicio; // O cálculo do max em si é feito aqui.
	return Max_recursivo_aux(++inicio, fim, maior);
}


int Max_recursivo(const int* inicio, const int* fim) {

	return Max_recursivo_aux(inicio, fim, inicio);
}
