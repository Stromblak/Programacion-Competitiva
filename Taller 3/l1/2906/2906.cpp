#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	Beecrowd 2906

int main(){

	int n;
	while(cin >> n){

		map<string, set<string>> mp;

		string s;
		for(int i=0; i<n; i++){
			cin >> s;

			string nombre, email;
			int flag = 0;
			for(auto c: s){
				if(flag == 0 && (isalpha(c) || isalnum(c) )) nombre.push_back(c);
				if(c == '+') flag = 1;
				if(c == '@') flag = 2;
				if(flag == 2) email.push_back(c);
			}

			mp[email].insert(nombre);
		}

		
		int u = 0;
		for(auto a: mp) u += a.second.size();
		cout << u << endl;
	}

	return 0;
}
