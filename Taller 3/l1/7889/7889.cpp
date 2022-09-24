#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	ICPC 7889

int main(){

	int n;
	while(cin >> n){

		vector<int> v;
		for(int i=0; i<n; i++){
			int aux;
			cin >> aux;
			v.push_back(aux);
		}

		sort(v.begin(), v.end());

		vector<int> v1, v2;
		for(int i=0; i<n; i++){
			if(i%2) v1.push_back(v[i]);
			else v2.push_back(v[i]);
		}

		for(int i=0; i<v2.size(); i++) v1.push_back(v2[v2.size()-1-i]);



		double area = 0, ang = (2*M_PI )/n;
	
		for(int i=0; i<n-1; i++) area += .5 * sin(ang) * v1[i] * v1[i+1];
		area += .5 * sin(ang) * v1[v1.size()-1] * v1[0];

		cout << fixed << setprecision(3) << area << endl;


	}

	return 0;
}
