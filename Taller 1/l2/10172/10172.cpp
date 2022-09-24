#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int set;
	cin >> set;
	while(set--){
		int n, s, q ,t=0, sAux=0;;
		cin >> n >> s >> q;

		int nAux = n;
		vector<queue<int>> v;
		stack<int> c;

		for(int i=0; i<n; i++){
			queue<int> q;
			v.push_back(q);
		}

		while(nAux--){
			int m;
			cin >> m;
			while(m--){
				int aux;
				cin >> aux;
				v[sAux].push(aux);
			}
			sAux++;
		}

		nAux = 0;
		while(true){
			
			while(!c.empty() && (c.top() == nAux%n+1 || v[nAux%n].size() < q)){
				if(c.top() != nAux%n+1) v[nAux%n].push(c.top());
				c.pop();
				t++;
			}

			while(c.size()<s && !v[nAux%n].empty()){
				c.push(v[nAux%n].front());
				v[nAux%n].pop();
				t++;
			}
				
			int flag = 1;
			if(!c.empty()) flag = 0;
			for(int i=0; i<n; i++) if(!v[i].empty()) flag = 0;
			if(flag) break;

			nAux++;
			t += 2;
		}

		cout << t << endl;
	}
	return 0;
}