#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;

	while(n--){
		string s[3][3];
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				string aux;
				cin >> aux;
				s[i][j] = aux;
			}	
		}

		int ev = 0, pos = 0;

		set<char> silver;
		for(int i=0; i<3; i++){
			if(s[i][2] == "even"){
				for(char c: s[i][0]) silver.insert(c);
				for(char c: s[i][1]) silver.insert(c);
				pos = i;
				ev++;
			}
		}

		string bal[2];
		vector<char> v;
		char falsa;

		if(ev == 0){
			for(int i=0; i<3; i++){
				if(s[ i%3 ][2] == s[ (i+1)%3 ][2]){
					bal[0] = s[ i%3 ][0] + s[ (i+1)%3 ][1];
					bal[1] = s[ i%3 ][1] + s[ (i+1)%3 ][0];
				}else{
					bal[0] = s[ i%3 ][0] + s[ (i+1)%3 ][0];
					bal[1] = s[ i%3 ][1] + s[ (i+1)%3 ][1];		
				}

				map<char, int> m;

				for(char c: bal[0]) m[c]++;
				for(auto c: m) if(c.second == 2) silver.insert(c.first);
				m.clear();	
				for(char c: bal[1]) m[c]++;
				for(auto c: m) if(c.second == 2) silver.insert(c.first);
		
				for(char c: bal[0]) m[c]++;
				for(auto c: m){
					if(c.second == 1) silver.insert(c.first);
					else v.push_back(c.first);
				}
			
			}
			for(auto c: v) if(silver.count(c) == 0) falsa = c;

		}else if(ev == 1){
			int i = (pos+1);
			if(s[ i%3 ][2] == s[ (i+1)%3 ][2]){
				bal[0] = s[ i%3 ][0] + s[ (i+1)%3 ][1];
				bal[1] = s[ i%3 ][1] + s[ (i+1)%3 ][0];
			}else{
				bal[0] = s[ i%3 ][0] + s[ (i+1)%3 ][0];
				bal[1] = s[ i%3 ][1] + s[ (i+1)%3 ][1];		
			}

			map<char, int> m;
			
			for(char c: bal[0]) m[c]++;
			for(auto c: m) if(c.second == 2) silver.insert(c.first);
			m.clear();	
			for(char c: bal[1]) m[c]++;
			for(auto c: m) if(c.second == 2) silver.insert(c.first);
	
			for(char c: bal[0]) m[c]++;
			for(auto c: m){
				if(c.second == 1) silver.insert(c.first);
				else v.push_back(c.first);
			}
			
			for(auto c: v) if(silver.count(c) == 0) falsa = c;

		}else{
			int notEven;
			for(int i=0; i<3; i++) if(s[i][2] != "even") notEven = i;

			for(char c: s[notEven][0]) if(silver.count(c) == 0) falsa = c;
			for(char c: s[notEven][1]) if(silver.count(c) == 0) falsa = c;


		}

		string peso;
		for(int i=0; i<3; i++){
			for(char c: s[i][0]){
				if(c == falsa){
					if(s[i][2] == "down") peso = "light.";
					else peso = "heavy.";
				}
			}
			for(char c: s[i][1]){
				if(c == falsa){
					if(s[i][2] == "down") peso = "heavy.";
					else peso = "light.";
				}
			}
		}
		
		cout << falsa << " is the counterfeit coin and it is " << peso << endl;
	}

	return 0;
}