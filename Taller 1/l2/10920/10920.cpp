#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	long long t, n;
	while(cin >> t >> n && t && n){
		long long c=1, c2=0;

		while((2*c-1)*(2*c-1) < n) c++;
		while((2*c-1)*(2*c-1) - 2*(c-1)*c2 > n) c2++;

		long long aux = n - ((2*c-1)*(2*c-1) - 2*(c-1)*c2);
		if(c2 == 0) cout << "Line = " <<  t/2+c << ", column = " << t/2+c << "." << endl;
		else if(c2 == 1) cout << "Line = " << t/2-c+aux+2 << ", column = " << t/2+c << "." << endl;
		else if(c2 == 2) cout << "Line = " << t/2-c+2 << ", column = " << t/2-c+aux+2 << "." << endl;
		else if(c2 == 3) cout << "Line = " << t/2+c-aux << ", column = " << t/2-c+2 << "." << endl;
		else if(c2 == 4) cout << "Line = " << t/2+c << ", column = " << t/2+c-aux << "." << endl;
	}
	return 0;
}