#include <stdio.h>

int main() {
	int num1, num2, num3, Total;
	float Average;

	printf("Input 3 scores: ");
	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("Your scores: %d %d %d\n", num1, num2, num3);

	Total = num1 + num2 + num3;
	printf("Total: %d\n", Total);

	Average = (float)Total / 3;
	printf("Average: %f\n", Average);
	printf(">5?: %d\n", Average > 5 ? 1 : 0);

	return 0;
}