### Backtracking 

> 모든 조합의 수를 살펴보지만 **조건이 만족할때** 만 이라는 조건이 있다.

백준 알고리즘 15649 문제를 통해 알아보자

## 문제

자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

## 입력

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

## 출력

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

## 예제 입력 1 

```
3 1
```

## 예제 출력 1 

```
1
2
3
```

## 예제 입력 2 

```
4 2
```

## 예제 출력 2 

```
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
```

## 예제 입력 3 

```
4 4
```

## 예제 출력 3 

```
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
```

```c
#include <iostream>
using namespace std;

const int MAX = 8 + 1;

int N, M;
int arr[MAX];
bool visited[MAX];

void backTracking(int cnt) 
{	
	if(cnt == M) 
	{
		for(int i=0 ; i<M ; i++)
			cout << arr[i] << " " ;
		cout << "\n" ;
		return ;
	}

	for(int i=0 ; i<N ; i++)	
	{						
		if(visited[i]) //조건이 있다.
			continue ;
		visited[i] = true ;
		arr[cnt] = i+1 ;					
		backTracking(cnt + 1) ; // ++cnt, cnt++ 와같은 표기식은 하지 않도록 주의한다.
		visited[i] = false ;		
	}			
}

int main(void)
{
	cin >> N >> M ;
	backTracking(0) ;
	return 0 ;
}
```

