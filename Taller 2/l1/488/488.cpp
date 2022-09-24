#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

void onda(int a){
	for(int i=1; i<=a; i++){
		for(int j=0; j<i; j++) cout << i;
		cout << endl;
	}
	for(int i=a-1; i>0; i--){
		for(int j=0; j<i; j++) cout << i;
		cout << endl;
	}

}

int main(){
	int n;
	cin >> n;

	while(n--){
		int a, b;
		cin >> a >> b;
		
		for(int i=0; i<b; i++){
			onda(a);

			if(i != b-1) cout << endl;
		}
		if(n != 0) cout << endl;
	}
	
	return 0;
}