#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 10340

int main(){
	string s1, s2;
	while(cin >> s1 >> s2){
		int i=0, count = 0;
		queue<char> q1, q2;
		for(char c: s1) q1.push(c);
		for(char c: s2) q2.push(c);

		while(!q2.empty() && !q1.empty()){
			if(q2.front() == q1.front()) q1.pop();
			q2.pop();
		}

		if(q1.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;

	}

	return 0;
}