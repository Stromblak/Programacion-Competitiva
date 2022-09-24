#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;

	getchar();
	for(int i=0; i<n; i++){	
		string linea;
		getline(cin, linea);

		string n1, n2;
		bool b = false;

		for(char c: linea){
			if(isdigit(c) && !b) n1 += c;
			else b = true;
			if(isdigit(c) && b) n2 += c;
		}

		double p = stof(n1)*.5;
		if(!n2.empty()) p += stof(n2)*.05;

		cout << "Case " << i+1 << ": " << p << endl;
	}


	return 0;
}