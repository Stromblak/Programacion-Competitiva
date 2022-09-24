#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;
	while(n > 0){
		int a, b, aux=1;	
		cin >> a;
		
		int v[n], i=0;

		while(--n){
			cin >> b;

			if(abs(a-b) < n+1+i  && abs(a-b)){
				if(!i) v[i] = abs(a-b);
				else{
					for(int j=0; j<i; j++){
						if(v[j] == abs(a-b)){
							aux = 0;
						}			
					}
					v[i] = abs(a-b);
				}
			}else aux = 0;

			a = b;
			i++;
		}

		if(aux) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
		cin >> n;
	}
	return 0;
}