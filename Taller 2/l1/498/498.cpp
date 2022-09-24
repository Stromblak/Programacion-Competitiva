#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

//Pablo Zapata
//Solucion Propia

int main(){
	string linea;

	while(getline(cin, linea)){
		lli aux;

		stringstream s1(linea);	
		vector<lli> c;
		while(s1 >> aux) c.push_back(aux);

		getline(cin, linea);
		stringstream s2(linea);
		vector<lli> x;
		while(s2 >> aux) x.push_back(aux);

		for(int i=0; i<x.size(); i++){
			lli r = 0;
			for(lli j: c) r = r*x[i] + j;
			cout << r;
			if(i != x.size()-1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}