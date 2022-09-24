#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;

	while(cin >> n && n){
		long long sum=0;
		multiset<int> ms;
		
		while(n--){
			int bills;
			cin >> bills;
			while(bills--){
				int aux;
				cin >> aux;
				ms.insert(aux);
			}
			multiset<int>::iterator in=ms.begin(), fi = --ms.end();
			sum += *fi - *in;
			ms.erase(in);
			ms.erase(fi);
		}
		cout << sum << endl;
	}

	return 0;
}