#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 10670

int main(){
	int c;
	cin >> c;
	for(int cc=0; cc<c; cc++){
		int no, mo, l;
		cin >> no >> mo >> l;

		vector<tuple<string, int, int>> v;
		for(int i=0; i<l; i++){
			string aux, nom, n1, n2;
			cin >> aux;

			int f = 0;
			for(auto a: aux){
				if(f == 0){
					if(a != ':') nom += a;
					else f++;
				}else if(f == 1){
					if(a != ',') n1 += a;
					else f++;
				}else n2 += a;
			}

			v.push_back( {nom, stoi(n1), stoi(n2)} );
		}


		set<pair<int, string>> s;
		for(auto a: v){
			int costo = 0, n = no, m = mo;
			int uno = get<1>(a), div = get<2>(a);

			while(true){
				if(n/2 >= m){
					if(div <= (n - n/2)*uno) costo += div;
					else costo += (n - n/2)*uno;
					n = n/2;
				}else{
					costo += (n-m)*uno;
					break;
				}
			}

			s.insert( {costo, get<0>(a)} );
		}

		cout << "Case " << cc+1 << endl;
		for(auto a: s) cout << a.second << " " << a.first << endl;
	}

	return 0;
}