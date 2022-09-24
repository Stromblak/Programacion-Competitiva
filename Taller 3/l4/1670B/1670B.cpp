#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	Codeblocks 1670B

int main(){
	int n;
	cin >> n;
	while(n--){
		int t;
		string p;
		cin >> t >> p >> t;

		vector<int> al(30);


		for(int i=0; i<t; i++){
			char aux;
			cin >> aux;
			al[(int)aux - 97] = 1;
		}

		int max = 0;
		vector<int> pos;
		pos.push_back(0);

		for(int i=1; i<p.size(); i++) if(al[ (int)p[i]-97 ]) pos.push_back(i);
		for(int i=0; i<pos.size()-1; i++) if(pos[i+1] - pos[i] > max) max = pos[i+1] - pos[i];

		cout << max << endl;
	}
	return 0;
}