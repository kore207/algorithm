### 정렬(Sort) 알고리즘

#### 선택 정렬(Selection Sort ) O(n^2)

* 현재 위치에 들어갈 값을 찾아 정렬하는 배열, 혀냊 위치에 저장 될 값의 크기가 작냐, 크냐에 따라 최소 선택 정렬(Min-selection sort)와 최대 선택 정렬(Max-selection sort)로 구분 한다.

* ###### 장점 : 구현이 쉽다. 정렬을 위한 비교 횟수는 많지만 실제로 교환하는 횟수는 적기 떄문에 많은 교환이 일어나야 하는 자료상태에서 효율적으로 사용될 수 있다.

* ###### 단점: 버블 정렬에 비해서는 조금 더 빠르지만 느린편에 속함

```c
void selectionSort(vector<int> v){
    for(int i=0 ; i<v.size()-1 ; i++)
    {
        int tmp=i ;
        for(int j=i+1 ; j<v.size() ; j++)
        {
            if(v[tmp]>=v[j]) tmp = j ;
        }
        swap(v[i], v[tmp]) ;
	}
}
```





#### 버블 정렬(Bubble Sort) O(n^2)

* 버블 정렬은 매번 연속된 두개 인덱스를 비교하여, 정한 기준의 값을 뒤로 넘겨 정렬하는 방법

* ###### 장점 : 구현이 쉽고 코드 자체가 직관적이다.

* ###### 장점 : 굉장히 비효율적이다. 최악이든 최선이든 O(n^2)이라는 시간복잡도를 갖는다. 

~~~ c
int main(void)
{
  int i, j, tmp;
  int array[10] = { 1, 10 ,5 ,8 ,7, 6, 4, 3, 2, 9};
  for(i=0; i<9-1; i++)
  {
    if(array[i] > array[i+1])
    {
      tmp = array[i];
      array[i] = array[i+1];
      array[i+1] = tmp;
    }
  }
  return 0;
}
~~~



### 삽입 정렬 O(n^2)

* 삽입 정렬은 현재 위치에서, 그 이하의 배열들을 비교하여 자신이 들어갈 위치를 찾아  그 위치에 삽입하는 배열 알고리즘

* ###### 장점 : 최선의 경우 O(N)이라는 빠른 효율성을 갖는다.

* ###### 단점 : 최악의 경우 O(n^2) , 즉 데이터의 상태 및 데이터의 크기에 따라서 성능의 편차가 굉장히 심하다.

~~~ c
int main(void)
{
  int i, j, tmp;
  int array[10] = { 1, 10 ,5 ,8 ,7, 6, 4, 3, 2, 9};
  for(i = 0; i<9; i ++)
  {
    j = i;
    while(array[j] > array[j+1] && j>0)  //비교는 앞에서보다 뒤에서 하는게 배열 인덱스 값을 건드리지 않을수 있어 좋다,
    {
      tmp = array[j];
    	array[j] = array[j+1];
      array[j+1] = tmp;
      j--;
    }
  }
  return 0;  
}
~~~



### 퀵 정렬 (평균)O(n*logn) 

##### 최악의 경우엔 O(n^2)

* ###### 장점 : 기준값에 의한 분할을 통해서 구현하는 정렬법으로, 분할 과정에서 logN이라는 시간이 걸리게 되고 전체적으로 NlogN 이 되어 실행시간이 준수한 편.

* ###### 단점 : 기준값 (pivot)에 따라서 시간 복잡도가 크게 달라진다. 최악의 경우 O(n^2)이 된다.

~~~ c
//피벗 (기준값)
int number = 10;
int data[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9}

void quickSort(int *data, int start, int end){
  if(start >= end){ //원소가 1개 인경우
    return;
  }
  
  int key = start; //key 는 첫번째 원소
  int i = start + 1;
  int j = end;
  int temp;
  
  while(i <= j){
    while(data[i] <= data[key]){ //key 값 보다 큰 값이 나올때까지
      i++;
    }
    while(data[j] >= data[key] && j > start){ //key 값보다 작은값이 나올때까지 
      j--;
    }
    if(i >j){// 현재 엇갈린 상태면 키 값과 교체
      temp = data[j];
      data[j] = data[key];
      data[key] = temp;
    }
    else    {//엇갈리지 않으면 큰값과 작은 값을 교체
      temp = data[j];
      data[j] = data[i];
      data[i] = temp;
    }
  }
  
  quickSort(data, start, j-1);
  quickSort(data, j+1, end);
}

int main(void)
{
 	quickSort(data, 0 , number-1) 
}
~~~



### 병합 정렬 (feat.반으로 나눠서 정렬) O(NlogN)

* 분할 정복 방식으로 설계된 알고리즘. 분할 정복은 큰 문제를 반으로 쪼개 문제를 해결해 나가는 방식.
  * nlogn의 시간 복잡도 

1. 리스트의 길이가 1이 될때까지 반으로 잘게 나눈다. (devide)
2. 다 나누어 지면  `정렬`  하면서 합친다. (merge)

* ###### 장점 : 퀵소팅과 달리, pivot을 설정하지 않고 무조건 절반으로 분할하기 때문에 pivot에 따라 성능이 좌우 되는 경우가 없다. 

* ###### 단점 : 추가적인 메모리가 필요하다.

~~~c
#include <iostream>
using namespace std ;

int SortArray[1000001] ;
int MaxSize ;

void mergesort(int Array[], int left, int right)  ;
void merge(int Array[], int left, int right, int mid) ;

int main(void) 
{	
	cin >> MaxSize ;
	int inputArray[MaxSize] ;
	for(int i=0 ; i<MaxSize ; i++)
		cin >> inputArray[i] ;

	mergesort(inputArray, 0, MaxSize-1) ;

	for(int i=0 ; i<MaxSize ; i++)
		cout << SortArray[i] ; 

	return 0 ;
}

void mergesort(int Array[], int left, int right) 
{
	if(left < right)
	{
		int mid = (left + right) / 2 ;
		mergesort(Array, left, mid) ;
		mergesort(Array, mid+1, right) ;
		merge(Array, left, right, mid) ;
	}
}

void merge(int Array[], int left, int right, int mid)
{
	int i = left;
	int j = mid + 1 ;
	int k = left ;

	while(i<=mid && j<=right)
	{
		if(Array[i] <= Array[j]) 		
			SortArray[k++] = Array[i++] ;		
		else		
			SortArray[k++] = Array[j++] ;		
	} //devide 

	//남아있는 배열 붙여넣기 
	if(i>mid) 
	{
		for(int l=j ; l<=right ; l++)
			SortArray[k++] = Array[l];
	}
	else
	{
		for(int l=i ; l<=mid ; l++)
			SortArray[k++] = Array[l] ;		
  	}	

	for(int l=left ; l<=right ; l++)
		Array[l] = SortArray[l] ;
}

~~~



### 힙 정렬

- 힙트리 구조를 이용한다

- 이진 트리 -> 노드를 2개씩 이어 붙이는 구조

    * 최상단 : 루트 /최하단: 리프
    * 완전 이진 트리: 데이터가 왼쪽 오른쪽 순서대로 차곡차곡 들어감
    * 최대 힙 구조 -> 부모가 항상 큼 (힙 생성 알고리즘을 통해 만들어줌)

    

### 배열 N칸 씩 이동
```c
 for(int i=0 ; i<ang; i++)
    {
        float keyx = TrXY[0].X;
        float keyy = TrXY[0].Y;
        for(int j=0 ; j< MAX_STEP-1; j++)
        {
            TrXY[j].X = TrXY[j+1].X;
            TrXY[j].Y = TrXY[j+1].Y;
        }
        TrXY[MAX_STEP-1].X = keyx ;
        TrXY[MAX_STEP-1].Y = keyy ;
    }

```