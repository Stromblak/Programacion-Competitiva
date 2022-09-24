#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;

	while(cin >> n && n){
		int aux, sum=0;
		priority_queue<int, vector<int>, greater<int>> pq;

		for(int i=0; i<n; i++){
			cin >> aux; 
			pq.push(aux);
		}

		while(pq.size() > 1){
			aux = 0;
			aux += pq.top();
			pq.pop();
			aux += pq.top();
			pq.pop();
			sum += aux;
			pq.push(aux);
		}
		cout << sum << endl;

	}

	return 0;
}