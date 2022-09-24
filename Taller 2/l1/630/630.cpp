#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

bool comp(string s1, string s2){
	if(s1.size() != s2.size()) return false;

	set<char> s;
	for(char c: s1) s.insert(c);
	for(char c: s2) if(s.count(c) == 0) return false;

	return true;
}

int main(){
	int n;
	cin >> n;

	while(n--){	
		int m;
		cin >> m;

		vector<string> v1, v2;
		string aux;

		while(m--){
			cin >> aux;
			v1.push_back(aux);
		}

		while(true){
			cin >> aux;
			if(aux == "END") break;
			v2.push_back(aux);
		}

		for(string s1: v2){
			vector<string> an;
			for(string s2: v1) if(comp(s1, s2)) an.push_back(s2);

			cout << "Anagrams for: " << s1 << endl;
			if(an.empty()) cout << "No anagrams for: " << s1 << endl;
			else for(int i=0; i<an.size(); i++) cout << "  " << i+1 << ") " << an[i] << endl;
		}


		if(n != 0) cout << endl;
	}


	return 0;
}
