#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void main() {

	vector<string> participant = { "leo", "kiki", "eden" };
	vector<string> completion = { "eden", "kiki" };

	unordered_map<string, int> participants;
	for (string name : participant) {
		++participants[name]; // < name , 1 >  꼴이 된다 .
	}

	string temp;
	for (string name : completion) {
		--participants[name]; // < name, 0 > 꼴이 되므로 중복되지 않은건 1로 남아있다.

	}
	for (auto pair : participants) {
		if (pair.second > 0) {			
			 temp = pair.first; // pari -> <first, seconde> 
		}
	}	
	return;	
	
}