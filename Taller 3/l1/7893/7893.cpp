#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	ICPC 7893

int main(){

	int n, k;
	while(cin >> n >> k){
		vector<int> v;
		priority_queue<int> pq;

		int costo = 0;
		for(int i=0; i<n; i++){
			int aux;
			cin >> aux;
			v.push_back(aux);
		}

		reverse(v.begin(), v.end());

		for(int i=0; i<n; i++){
			pq.push(v[i]);
			if((n-i) % (k+1) == 0) pq.pop();
		}



		while(!pq.empty()){
			costo += pq.top();
			pq.pop();
		}
		cout << costo << endl;

	}	
	return 0;
}