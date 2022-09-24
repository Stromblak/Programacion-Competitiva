#include <bits/stdc++.h>
using namespace std;

//	Nombre:		Pablo Zapata		
//	ID UVa: 	1210486
//	Problema:	UVa 10815	
//	Solucion:	Propia

int main(){
	string pal;
	set<string> s;

	while(cin >> pal){
		string aux;

		for(char c: pal){
			if(isalpha(c)) aux.push_back( tolower(c) );

			else{
				if(!aux.empty()) s.insert(aux);
				aux.clear();
			}
		}

		if(!aux.empty()) s.insert(aux);
	}

	for(string ss: s) cout << ss << endl;
	return 0;
}