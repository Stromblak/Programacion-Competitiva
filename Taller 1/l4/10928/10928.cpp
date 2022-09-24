#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia
//	PD: Hecho en curso anterior

int main(){
	int n;
	cin >> n;
	while(n--){
		int p;
		cin >> p;
		vector<pair<int, int>> v(p);
		getchar();

		for(int i=0; i<p; i++){
			v[i].second = i+1;
			string str;
			getline(cin, str);
			v[i].first++;
			for(char c: str) if(c == ' ') v[i].first++;
		}
		sort(v.begin(), v.end());
		
		for(int i=0; i<p; i++){
			cout << v[i].second;
			if(i+1 < p && v[i].first == v[i+1].first) cout << " ";
			else break;
		}
		cout << endl;
	}

	return 0;
}