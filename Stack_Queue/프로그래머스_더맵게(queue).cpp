#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K);

int main(void){
    cout << "heelow " ;
    vector<int> scoville = {1,2,3,9,10,12} ;
    int K = 7 ;
    int a = solution(scoville,  K) ;
	cout << a ;
    return 0 ;
}

int solution(vector<int> scoville, int K) {
	int answer = 0 ;
	// sort(scoville.begin(), scoville.end(),desc);
	// for(int i=0; i<scoville.size(); i++){
	// 	cout << scoville.at(i);
	// }
	priority_queue<int,vector<int>,greater<int>> temp ;
	for(int i=0; i<scoville.size(); i++){
		temp.push(scoville[i]);
	}

	while (temp.top()< K && temp.size() >1)
	{
		int first, second;
		answer++;
		first = temp.top(); temp.pop();
		second = temp.top(); temp.pop();
		temp.push(first + second*2);		
	}	

	if(temp.top() <K)
		return -1 ;
				
	return answer;
}