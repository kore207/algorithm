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



여기까지는 기본적인 backtracking 에 관련한 문제였고 대표적인 N-Queen 문제를 살펴보자

#### 문제 

크기가 N * N 인 체스판 위에 퀸 N 개를 서로 공격할 수 없게 놓는 문제이다. N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

* 백트래킹은 크게 4가지 절차로 구성되어 있다.

  **DFS 수행 - 유망한 노드 검토 - 서브 트리 이동 - 백트래킹 수행**

1. DFS 수행 - 먼저 평소와 같이 깊이우선탐색인 DFS 를 수행하여 노드를 찾는다.
2. 유망한 노드 검토 - 방문한 노드를 포함해서 유망한 노드이면 서브트리로 이동하고 그렇지 않으면 백트래킹을 수행한다.
3. 방문한 노드의 하위 노드로 이동하여 다시 재귀를 통해 DFS 를 수행한다.
4. 백트래킹 수행 - 방문한 노드를 가지치기를 하고 상위 노드로 백트래킹 한 후 DFS 를 다시 수행한다.

```c
#include <iostream>

using namespace std;

int N;
int col[15];
int result = 0;

bool promising(int i)
{
    for(int j=0;j<i;j++)
    {
        // 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
        if(col[j] == col[i] || abs(col[i]-col[j]) == (i-j))
            return false;
    }
    return true;
}
void N_Queen(int i)
{
    if(i == N)
        result += 1;
    else
    {
        for(int j=0;j<N;j++)
        {
            col[i] = j;
            if(promising(i))
                N_Queen(i+1);
        }
    }
}

int main()
{
    cin>>N;

    N_Queen(0);

    cout<<result<<endl;

    return 0;
}
```

