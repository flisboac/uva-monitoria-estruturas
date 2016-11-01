#include <stdio.h>
#include <limits.h>

static int Comb(int n, int k);


int main(void) {
	
	int n = 5;
	int k = 3;
	int r = Comb(n, k);
	printf("Resultado: Comb(%d, %d) = %d\n", n, k, r);
	return 0;
}


int Comb(int n, int k) {

	
	if (n < 1 || k < 1) return 0; // Condĩções iniciais
	if (k == 1) return n; // Condição de parada 1
	if (n == k) return 1; // Condição de parada 2
	return Comb(n - 1, k - 1) + Comb(n - 1, k);
}
