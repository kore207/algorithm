#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands);

int main(void){
	vector<int> array = {1,5,2,6,3,7,4};
	vector<vector<int>> commands = {{2,5,3},{4,4,1},{1,7,3}} ;

	solution(array, commands);

	return 0 ;
}

//내풀이
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
	
	for(int i = 0 ; i < commands.size(); i++){
		vector<int> temp ;
		temp.assign( array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
		sort(temp.begin(), temp.end());
		answer.push_back(temp[commands[i][2]]-1);
		cout << answer.at(i);
	}
    return answer;
}
//좋은 풀이
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}