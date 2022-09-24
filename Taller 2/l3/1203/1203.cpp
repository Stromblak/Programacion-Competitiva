#include <bits/stdc++.h>
using namespace std;

//	Nombre:		Pablo Zapata		
//	ID UVa: 	1210486
//	Problema:	UVa 1203	
//	Solucion:	Propia

int main(){
	int k;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	map<int, int> ti;
	map<int, int> ta;


	while(true){
		string s;
		cin >> s;
		if(s != "#"){	
			int a, b;
			cin >> a >> b;
			pq.push( {b, a} );
			ti[a] = b;
			ta[a] = 1;
		}else{
			cin >> k;
			break;
		}
	}

	for(int i=0; i<k; i++){
		int nom = pq.top().second;
		cout << nom << endl;
		pq.pop();
		ta[nom]++;
		pq.push( {ti[nom] * ta[nom], nom} );


	}



	return 0;
}