#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;
	while(n){
		int x, y;
		cin >> x >> y;

		while(n--){
			int a, b;
			cin >> a >> b;

			if(a-x == 0 || b-y == 0) cout << "divisa" << endl;
			else if(a-x < 0){
				if(b-y < 0) cout << "SO" << endl;
				else cout << "NO" << endl;
			}else{
				if(b-y < 0) cout << "SE" << endl;
				else cout << "NE" << endl;
			}
		}
		cin >> n;
	}
	return 0;
}