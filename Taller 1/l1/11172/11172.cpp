#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;
	while(n--){
		int a, b;
		cin >> a >> b;
		if(a == b) cout << "=" << endl;
		else if(a < b) cout << "<" << endl;
		else cout << ">" << endl;
	}
	return 0;
}