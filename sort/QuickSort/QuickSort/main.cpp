//
//  main.cpp
//  QuickSort
//
//  Created by Kim GT  on 28/07/2019.
//  Copyright © 2019 Kim GT . All rights reserved.
//

#include <iostream>
using namespace std ;
int Partition(int A[], int start, int end) ;
int Partition(int A[], int start, int end)
{
    int pivot = A[end] ;
    int i ;
    int index = start ;
    
    int temp ;
    for(i=start ; i< end; i++)
    {
        if(A[i] <= pivot)
        {
            temp = A[i] ;
            A[i] = A[index] ;
            A[index] =temp ;
            index ++ ;
        }
    }
    
    temp = A[index] ;
    A[index] = A[end] ;
    return index ;
}


void QuickSort(int A[], int start, int end)
{
    int index ;
    //int i ;
    if(start < end)
    {
        index = Partition(A, start, end) ;
        QuickSort(A, start, index-1) ;
        QuickSort(A, start, end) ;
        cout << "this" <<endl;
        
    }
    return ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int A[10] = {8, 9, 10, 1, 5, 4, 3, 7, 6, 2} ;
    
    QuickSort(A, 0, 9) ;
    for(int i=0; i<10; i++)
        cout << A[i] <<endl;
    return 0;
}
