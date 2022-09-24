#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n, m;
	while(cin >> n >> m && n && m){
		map<int, vector<int>> map;
		for(int i=0; i<n; i++){
			int aux;
			cin >> aux;
			map[aux].push_back(i+1);
		}

		while(m--){
			int a, b;
			cin >> a >> b;
			if(map[b].size() >= a) cout << map[b][a-1] << endl;
			else cout << "0" << endl;

		}
	}

	return 0;
}