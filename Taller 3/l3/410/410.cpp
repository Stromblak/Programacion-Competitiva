#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 410

//	No aprecio que el orden de las capsulas del output no importe y no se mencione


int main(){
	int c, s, n = 0;
	while(cin >> c >> s && c){
		double AM = 0;
		vector<int> v;
		for(int i=0; i<s; i++){
			int scp;
			cin >> scp;
			v.push_back(scp);
			AM += scp;
		}
		AM /= c;

		sort(v.begin(), v.end(), greater<int>());

		vector<int> v1, v2;
		if(v.size() >= c) for(int i=0; i<c; i++) v1.push_back( v[i] );
		else for(int i=0; i<v.size(); i++) v1.push_back( v[i] );
		for(int i=c; i<v.size(); i++) v2.push_back( v[i] );


		double im = 0;
		n++;
		cout << "Set #" << n << endl;
		for(int i=0; i<c; i++){
			double CM = 0;

			cout << " " << i << ":";
			if(i < v1.size()){
				cout << " " << v1[i];
				CM += v1[i];
			}

			if(c-1-i < v2.size()){
				cout << " " << v2[c-1-i];
				CM += v2[c-1-i];
			}

			cout << endl;
			im += abs(CM - AM);
		}
		cout << fixed << setprecision(5) << "IMBALANCE = " << im << endl << endl;

	}

	return 0;
}
