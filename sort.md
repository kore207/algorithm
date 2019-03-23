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

