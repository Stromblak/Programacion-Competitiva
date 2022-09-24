#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 10020

int main(){
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;

		int l, r;
		map<int, int> mp;
		while(cin >> l >> r && (l || r)) if(r > mp[l]) mp[l] = r;
		vector<pair<int, int>> v;
		for(auto a: mp) v.push_back(a);
		sort(v.begin(), v.end());

		int pos = 0, seg = 0;
		pair<int,int> s = {0, 0};
		vector<pair<int, int>> vseg;
		for(auto a: v){
			if(pos >= m) break;
			if(a.first <= pos && a.second > s.second) s = a;
			if(a.first >= pos){
				if(s.second == 0) break;
				pos = s.second;
				vseg.push_back(s);
				if(a.first <= pos && a.second > s.second) s = a;
			}
		}
		if(pos < m) vseg.clear();

		cout << vseg.size() << endl;
		for(auto a: vseg) cout << a.first << " " << a.second << endl;
		if(n) cout << endl;

	}

	return 0;
}