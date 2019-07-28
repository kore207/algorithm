### 퀵소트 

---

* 피봇을 어디에 두냐에 따라 여러가지 알고리즘이 존재한다.
* 피봇 맨 오른쪽 
* ~~~
    void QuickSort(int a[], int start, int end)
    {
    	int index ; //사용할 로컬 변수들 선언 index는 partrition이 이루어진 위치 추적
    	int i ; //for debug
    	if(start < end) //start 인덱스가 end 인덱스보다 적으면 아직 정렬 할 element들이 남아 있으므로 계속 진행하고, element 가 하나 남았을때 재귀 조건 종료
    	{
    		Partirion(A, start, end) ; //누구를 기준으로 줄세웠는지 인덱스를 리턴
    		QuickSort(A, start, index-1) ; // 인덱스를 중심으로 왼쪽 element 들을 다시 정렬 시도		
    		QuickSort(A, index+1, end) ; //index를 중심으로 오른쪽 element들을 다시 정렬
    	}
    
    	return ; //element가 하나 남았으니 더이상 정렬시도 할 필요없으지 재귀조건 종료
    	
    }
    
    int Partition(int a[], int start, int end) 
    {
    	int pivot = A[end] ;
    	int i ;
    	int index = start ;
    	
    	int temp ;
    	
    	for(i=start ; i<end ; i++)
    	{
    		if(A[i] <= pivot) 
    		{//피봇보다 작은것들을 앞쪽으로 옮긴다.
                temp = A[i] ;
                A[i] = A[index] ;
                A[index] = temp ;
                index++ ;
    		}
    	}
    	
    	temp = A[index] ; //인덱스와 피봇의 위치를 바꾼다. 
    	A[index] = A[end] ;
    	return index ;
    }
    
    
    ~~~