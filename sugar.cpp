#include <stdio.h>

int main() {
	int num = 0;
	int data = 0;
	scanf_s("%d", &num);
	if ((num >= 3) && (num <= 5000))
		if ((num == 7) || (num == 4)) {
			printf("-1\n");
			return 0;
		}
		else if (num % 5 == 0)
			data = num / 5;
		else if (((num % 5) == 3) || (num % 5) == 1)
			data = num / 5 + 1;
		else if (((num % 5) == 2) || (num % 5) == 4)
			data = num / 5 + 2;
		else
			data = -1;

	printf("%d", data);

	return 0;
}