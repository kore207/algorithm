### 정렬(Sort) 알고리즘

#### 버블 정렬 O(n^2)

~~~ c
int main(void)
{
  int i, j, tmp;
  int array[10] = { 1, 10 ,5 ,8 ,7, 6, 4, 3, 2, 9};
  for(i=0; i<9-i; i++)
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

~~~ c
int main(void)
{
  int i, j, tmp;
  int array[10] = { 1, 10 ,5 ,8 ,7, 6, 4, 3, 2, 9};
  for(i = 0; i<9; i ++)
  {
    j = i;
    while(array[j] > array[j+1])
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



### 병합 정렬 (feat.반으로 나눠서 정렬)

~~~c
#include <stdio.h>

int number = 8 ;
int sorted[8] ; //정렬 배열은 반드시 전역 변수로 선언

void merge(int a[], int m, int middle, int n){
    int i = m ;
    int k = middle + 1 ;
    int k = m ;
    //작운 순서대로 배열에 삽입
    while(i <= middle && j <= n){
        if(a[i] <= a[j]){
            sorted[k] = a[i] ;
            i++ ;            
        }else {
            sorted[k] = a[j] ;
            j++;
        }
        k++; // 비교해서 기준에 맞는 값들을 차례대로 삽입        
    }
    if(i > middle) {
        for(int t = j; t<= middle; t++){
            sorted[k] = a[t];
            k++ ;
        }
    }
    //정렬된 배열을 삽입
    for(int t = m ; t <= n ; t++){
        a[t] = sorted[t] ;
    }
}

void mergeSort(int a[], int m, int n){
    //크기가 1보다 큰 경우
    if(m < n){
        int middle = (m + n) / 2;
        mergeSort(a, m , middle);
        mergeSort(a, middle + 1 , n);
        merge(a, m , middle, n);
    }
}
~~~



### 힙 정렬

- 힙트리 구조를 이용한다

- 이진 트리 -> 노드를 2개씩 이어 붙이는 구조

    * 최상단 : 루트 /최하단: 리프
    * 완전 이진 트리: 데이터가 왼쪽 오른쪽 순서대로 차곡차곡 들어감
    * 최대 힙 구조 -> 부모가 항상 큼 (힙 생성 알고리즘을 통해 만들어줌)

    

