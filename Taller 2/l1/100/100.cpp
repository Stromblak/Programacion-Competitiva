#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int alg(int n){
	int l = 1;
	while(n != 1){
		if(n%2 == 0){
			n = n/2;
		}else n = 3*n + 1;
		l++;
	}
	return l;
}

int main(){
	int a, b;
	while(cin >> a >> b){
		int maximo = 0;
		for(int i=min(a, b); i<=max(a, b); i++){
			int aux = alg(i);
			if(aux > maximo) maximo = aux;
		}
		cout << a << " " << b << " " << maximo << endl;

	}
	return 0;
}

