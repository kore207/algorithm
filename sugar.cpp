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