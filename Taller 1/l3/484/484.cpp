#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	map<int, int> m;
	vector<int> v;
	while(cin >> n){
		if(m[n] == 0) v.push_back(n);
		m[n]++;
	}

	for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
		cout << *it << " " << m[*it] << endl;
	}
}