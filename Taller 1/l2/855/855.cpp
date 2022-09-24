#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int t;
	cin >> t;
	while(t--){
		int s, a, f;
		cin >> s >> a >> f;
		int s3[f], a3[f];

		for(int i=0; i<f; i++) cin >> s3[i] >> a3[i];
		sort(a3, a3+f);
		sort(s3, s3+f);

		printf("(Street: %d, Avenue: %d)\n", s3[f/2 -(1-f%2)], a3[f/2 -(1-f%2)]);	
	}
	return 0;
}