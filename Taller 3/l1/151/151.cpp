#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 151

int main(){
	int n;
	while(cin >> n && n){
		int menor = 0;
		queue<int> q2; 
		for(int i=0; i<n; i++) q2.push(i+1);


		for(int i=1; i<n; i++){	
			queue<int> q = q2;
			int p = 0;

			while(q.size() > 1){
				if(q.front() == 13) break;

				q.pop();
				for(int j=0; j<i-1; j++){
					int aux = q.front();
					q.pop();
					q.push(aux);
				}

			}
			if(q.size() == 1) menor = i;

			if(menor) break;

		}
		
		cout << menor << endl;
	}	
	return 0;
}