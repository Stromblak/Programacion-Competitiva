#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int mcd(int a, int b){
	int resto = 1;
	int dividendo = max(a, b), divisor = min(a,b);

	while(resto != 0){
		resto = dividendo % divisor;
		dividendo = divisor; 
		divisor = resto;
	}

	if(dividendo == 1) return 0;
	else return 1;
}

int main(){
	int n;
	while(cin >> n && n){
		int aux;
		vector<int> v;
		for(int i=0; i<n; i++){
			cin >> aux;
			v.push_back(aux);
		}

		double si = 0, no = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(mcd(v[i], v[j])) si++;
				else no++;
			}
		}
		if(no) cout << setprecision(6) << fixed << sqrt(((no+si)*6.0/no)) << endl;
		else cout << "No estimate for this data set." << endl;


	
	}
	return 0;
} 

