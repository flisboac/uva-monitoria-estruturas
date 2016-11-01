#if 0

Diagrama (saída do programa):

	>> potencia(2, 8) = 2 * potencia(2, 7)
	    >> potencia(2, 7) = 2 * potencia(2, 6)
	        >> potencia(2, 6) = 2 * potencia(2, 5)
	            >> potencia(2, 5) = 2 * potencia(2, 4)
	                >> potencia(2, 4) = 2 * potencia(2, 3)
	                    >> potencia(2, 3) = 2 * potencia(2, 2)
	                        >> potencia(2, 2) = 2 * potencia(2, 1)
	                            >> potencia(2, 1) = 2 * potencia(2, 0)
	                                << potencia(2, 0) = 1
	                            << potencia(2, 1) = 2 * 1 = 2
	                        << potencia(2, 2) = 2 * 2 = 4
	                    << potencia(2, 3) = 2 * 4 = 8
	                << potencia(2, 4) = 2 * 8 = 16
	            << potencia(2, 5) = 2 * 16 = 32
	        << potencia(2, 6) = 2 * 32 = 64
	    << potencia(2, 7) = 2 * 64 = 128
	<< potencia(2, 8) = 2 * 128 = 256
	Resultado: potencia(2, 8) = 256


#endif

#include <stdio.h>
#include <stdio.h>


static int potencia(int base, int expoente);


int main(void) {
	
	int b = 2;
	int e = 8;
	int r = potencia(b, e);
	printf("Resultado: potencia(%d, %d) = %d\n\n", b, e, r);

	return 0;
}


static int potencia_aux(int base, int expoente, int nivel) {
	int i, valor, total;
	const char* indent = "    ";

	for (i = 0; i < nivel; ++i) printf(indent);

	if (expoente == 0) {
		printf("<< potencia(%d, 0) = 1\n", base);
		return 1;
	}

	printf(">> potencia(%d, %d) = %d * potencia(%d, %d)\n",
		base, expoente,
		base, base, expoente - 1
	);

	valor = potencia_aux(base, expoente - 1, nivel + 1);
	total = base * valor;

	for (i = 0; i < nivel; ++i) printf(indent);
	
	printf("<< potencia(%d, %d) = %d * %d = %d\n",
		base, expoente,
		base, valor,
		total
	);

	return total;
}


int potencia(int base, int expoente) {

	return potencia_aux(base, expoente, 0);
}
