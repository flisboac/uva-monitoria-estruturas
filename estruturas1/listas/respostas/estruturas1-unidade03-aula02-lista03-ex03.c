#include <stdio.h>

int MDC(int x, int y) {
	if (x == y) return x;
	if (x > y) return MDC(x - y, y);
	return MDC(y, x);
}

int main(void) {
	int x, y;

	printf("x = ");
	fflush(stdin);
	scanf("%d", &x);

	printf("y = ");
	fflush(stdin);
	scanf("%d", &y);

	printf("MDC(%d, %d) = %d\n", x, y, MDC(x, y));
	return 0;
}
