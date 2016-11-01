#include <stdio.h>


static int Comb(int n, int k);


int main(void) {
	
	int n = 5;
	int k = 3;
	int r = Comb(n, k);
	printf("Resultado: Comb(%d, %d) = %d\n", n, k, r);
	return 0;
}


static int Comb_aux(int n, int k, int nivel) {
	int i;

	for (i = 0; i < nivel; ++i) {
		printf("  ");
	}

	printf("%d: COMB(%d, %d) = ", nivel, n, k);

	if (n < 1 || k < 1) {
		printf("0\n");
		return 0;
	}

	if (k == 1) {
		printf("%d\n", n);
		return n;
	}

	if (n == k) {
		printf("1\n");
		return 1;
	}

	nivel++;
	printf("COMB(%d, %d) + COMB(%d, %d)\n",
		n - 1, k - 1,
		n - 1, k);
	return Comb_aux(n - 1, k - 1, nivel) + Comb_aux(n - 1, k, nivel);
}


int Comb(int n, int k) {

	return Comb_aux(n, k, 0);
}
