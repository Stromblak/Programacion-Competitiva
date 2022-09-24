#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int n;
	cin >> n;

	getchar();
	getchar();

	while(n--){
		float count=0;
		string str;
		map<string, int> mp;

		while(getline(cin, str) && str.length() != 0 ){
			mp[str]++;
			count++;
		}    
		
		for(map<string, int>::iterator it=mp.begin(); it!=mp.end(); it++){
			cout << it->first + " " << fixed << setprecision(4) << it->second/count*100 << endl;
		}
		if(n) cout << endl;

	}
	return 0;
}