#include <stdio.h>
#include <stdlib.h>

static int potencia(int base, int expoente);

int main(void) {
	int base = 2;
	int expoente = 8;
	int resultado = potencia(base, expoente);
	printf("potencia(%d, %d) = %d\n", base, expoente, resultado);
	return 0;
}

int potencia(int base, int expoente) {
	
	if (expoente == 0) return 1;
	return base * potencia(base, expoente - 1);
}
