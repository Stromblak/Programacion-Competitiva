#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;
	getchar();
		
	string linea;
	map<string, int> mp;
	set<string> v;
	while(n--){
		getline(cin, linea);
		stringstream s1(linea);
		string aux;
		s1 >> aux;
		mp[aux]++;
		v.insert(aux);
	}
	for(string i: v) cout << i << " " << mp[i] << endl;

	return 0;
}