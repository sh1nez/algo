#include <stdio.h>

int main() {
	int n, t;
	int sum = 0, result = 0;
	scanf("%d %d",  &n, &t);
	int vector[n];
	int *border = vector;
	int tmp;
	for (int *input = vector; input<&vector[n]; ++input)
	{
		scanf("%d", input);
		sum += *input;
		while (sum > t) sum -= *border++;
		
		tmp = input - border;
		result = result > ++tmp ? result : tmp;
	}
	printf("%d\n", result);

    return 0;
}
