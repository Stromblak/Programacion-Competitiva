#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;
	int m = n;
	while(n--){
		int c, r;
		cin >> c >> r;
		vector<int> v;

		printf("Case #%d:", m-n);
		if(c == r) cout<< " " << 0;
		for(int g=1; g<=sqrt(c-r); g++){
			if(!((c-r)%g)){
				if(r < g) v.push_back(g);
				if(r < (c-r)/g && g!=(c-r)/g) v.push_back((c-r)/g);
			}
		}

		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++) cout << " " << v[i];
		cout << endl;
	}
	return 0;
}