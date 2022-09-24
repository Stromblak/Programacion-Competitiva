#include <bits/stdc++.h>
using namespace std;

//	Nombre:		Pablo Zapata		
//	ID UVa: 	1210486
//	Problema:	UVa 12582	
//	Solucion:	Propia

int main(){
	int n;
	cin >> n;
	for(int j = 0; j<n; j++){
		string ss;
		cin >> ss;


		map<char, int> m;
		stack<char> s;

		s.push(ss[0]);
		ss.erase(ss.begin());

		for(char c: ss){
			if(s.top() == c){
				if(s.size() == 1) break;
				s.pop();
				m[s.top()]++;
			}
			else{
				s.push(c);
				m[c]++;
			}
		}


		cout << "Case " << j+1 << endl;
		for(auto a: m) cout << a.first << " = " << a.second << endl;
	}

	return 0;
}