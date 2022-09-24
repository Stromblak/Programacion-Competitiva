#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 10763

int main(){
	int n;
	while(cin >> n && n){
		map<pair<int, int>, int> mp;
		while(n--){
			int s1, s2;
			cin >> s1 >> s2;
			mp[ {min(s1, s2), max(s1, s2)} ]++;
		}

		int flag = 0;
		for(auto a: mp) if(a.second % 2) flag = 1;

		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;

	}
	return 0;
}