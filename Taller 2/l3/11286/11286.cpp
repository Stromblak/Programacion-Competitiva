#include <bits/stdc++.h>
using namespace std;

//	Nombre:		Pablo Zapata		
//	ID UVa: 	1210486
//	Problema:	UVa 11286	
//	Solucion:	Propia

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0) break;

		map<string, int> m;
		for(int j=0; j<n; j++){
			vector<int> v;
			for(int i=0; i<5; i++){
				int aux;
				cin >> aux;
				v.push_back(aux);
			}
			sort(v.begin(), v.end());
			string s;
			for(int i: v) s += to_string(i);
			m[s]++;
		}


		int max = 0, count;
		for(auto a: m){
			if(a.second > max){
				max = a.second;
				count = a.second;
			}else if(a.second == max) count += a.second;
		}

		cout << count << endl;

	}



	return 0;
}