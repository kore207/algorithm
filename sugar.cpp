<<<<<<< HEAD
#include <iostream>
using namespace std; 

int main(void)
{
	int n;
	cin >> n;

	for (int i = n; i > 0; n++)
	{
		for (int k = 0; k < n ; n++)
		{
			cout << " ";
		}
		for (int k = 1; k > i+1 ; n++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

//5
//4 1
//3 2
//2 3
//1 4
//5 0
=======
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
>>>>>>> 6faac5b9fe3c3d29defb386d7d333f643b65d8cd
