#include <stdio.h>

static int somatorioQuadrado(int base, size_t iteracoes);

int main(void) {
	int base = 2;
	int iteracoes = 4;
	int resultado = somatorioQuadrado(base, iteracoes);
	printf("somatorioQuadrado(%d, %d) = %d\n", base, iteracoes, resultado);
	return 0;
}

int somatorioQuadrado(int base, size_t iteracoes) {
	
	if (iteracoes < 1) return 0;
	if (iteracoes == 1) return (base * base);
	return (base * base) + somatorioQuadrado(base, iteracoes - 1);
}
