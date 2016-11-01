#if 0

Diagrama (saída do programa):

	>> F(4) = 2 * F(4 - 4) + 5)
	    << F(0) = 3
	<< F(4) = 2 * 3 + 5 = 11
	Resultado: F(4) = 11

	>> F(8) = 2 * F(8 - 4) + 5)
	    >> F(4) = 2 * F(4 - 4) + 5)
	        << F(0) = 3
	    << F(4) = 2 * 3 + 5 = 11
	<< F(8) = 2 * 11 + 5 = 27
	Resultado: F(8) = 27

	>> F(16) = 2 * F(16 - 4) + 5)
	    >> F(12) = 2 * F(12 - 4) + 5)
	        >> F(8) = 2 * F(8 - 4) + 5)
	            >> F(4) = 2 * F(4 - 4) + 5)
	                << F(0) = 3
	            << F(4) = 2 * 3 + 5 = 11
	        << F(8) = 2 * 11 + 5 = 27
	    << F(12) = 2 * 27 + 5 = 59
	<< F(16) = 2 * 59 + 5 = 123
	Resultado: F(16) = 123

#endif

#include <stdio.h>
#include <stdio.h>


static int F(int n);


int main(void) {
	
	int n = 4;
	int r = F(n);
	printf("Resultado: F(%d) = %d\n\n", n, r);

	n = 8;
	r = F(n);
	printf("Resultado: F(%d) = %d\n\n", n, r);

	n = 16;
	r = F(n);
	printf("Resultado: F(%d) = %d\n", n, r);

	return 0;
}


static int F_aux(int n, int nivel) {
	int i, valor, total;
	const char* indent = "    ";

	for (i = 0; i < nivel; ++i) printf(indent);

	if (n < 4) {
		printf("<< F(%d) = 3\n", n);
		return 3;
	}

	printf(">> F(%d) = 2 * F(%d - 4) + 5)\n", n, n);

	valor = F_aux(n - 4, nivel + 1);
	total = 2 * valor + 5;

	for (i = 0; i < nivel; ++i) printf(indent);
	printf("<< F(%d) = 2 * %d + 5 = %d\n", n, valor, total);

	return total;
}


int F(int n) {

	return F_aux(n, 0);
}
