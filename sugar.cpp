#include <iostream>	
using namespace std;

int process1(int in);
int process2(int in);
int process3(int in);
int process4(int in);
int processn(int pnum, int in);
int oh = 5;
int sam = 3;
int ok = 0;

int main(void)
{
	//git 변경사항 테스트
	int input;		
	int result;
	cin >> input;

	result = process1(input);
	if (result != 0)
	{
		cout << result;
		return 0;
	}	

	//result = process2(input);
	//if (result != 0)
	//{
	//	cout << result;
	//	return 0;
	//}

	//result = process3(input);
	//if (result != 0)
	//{
	//	cout << result;
	//	return 0;
	//}

	//result = process4(input);
	//if (result != 0)
	//{
	//	cout << result;
	//	return 0;
	//}
	else if (ok == 0)
	{
		for (int i = 2; i < 500; i++)
		{
			processn(i, input);
			if (ok == 1)
			{
				cout << result;
				return 0;
			}
			
		}
	}
	else
	{
		result = -1;
		cout << result;
	}
	
	 
	

	return 0;
	
}

int process1(int in)
{
	int result;
	if ((in == oh) || (in == sam)) return 1;		
	else
	{
		result = 0;
		ok = 0;
		return result;
	}
}

int process2(int in)
{
	int result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			result = (oh*i) + (sam * j);
			if ((i + j) != 2) continue;
			if (result == in) return 2;
			
		}
	}
	return 0;
}

int process3(int in)
{
	int result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			result = (oh*i) + (sam * j);
			if ((i + j) != 3) continue;
			if (result == in) return 3;
			
		}
	}
	return 0;
}

int process4(int in)
{
	int result;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j >= 0; j--)
		{
			result = (oh*i) + (sam * j);
			if ((i + j) != 4) continue;
			if (result == in) return 4;
			
		}
	}
	return 0;
}

int processn(int pnum, int in)
{
	int result;
	for (int i = 0; i < pnum+1; i++)
	{
		for (int j = pnum; j >= 0; j--)
		{
			result = (oh*i) + (sam * j);
			if ((i + j) != pnum) continue;
			if (result == in)
			{
				ok = 1;
				return pnum;
			}

		}
	}
	return 0;
}