#include <stdio.h>

int fib(int round) {
	if (round == 0) return 0;
	if (round == 1) return 1;
	return fib(round - 1) + fib(round - 2);
}

int main() {
	printf("%d\n", fib(10));
	return 0;
}