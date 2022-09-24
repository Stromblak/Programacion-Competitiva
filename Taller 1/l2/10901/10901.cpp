#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

int main(){
	int c;
	cin >> c;
	while(c--){
		int n, t, m, t2 = 0;
		cin >> n >> t >> m;
		
		queue<int> l, r, f;
		string s = "left";
		vector<pair<int, int>> v;

		while(m--){
			int aux;
			string sAux;
			cin >> aux >> sAux;
			if(sAux == "left") l.push(aux);
			else r.push(aux);
		}

		while(!l.empty() || !r.empty() || !f.empty()){
			while(!f.empty()){
				v.push_back(make_pair(f.front(), t2));
				f.pop();
			}
			if(s == "left"){
				while(!l.empty() && t2 >= l.front() && f.size() < n){
					f.push(l.front());
					l.pop();
				}
				if(!f.empty() || (!r.empty() && t2 >= r.front())){
					s = "right";
					t2 += t;
				}else t2++;
				
			}else{
				while(!r.empty() && t2 >= r.front() && f.size() < n){
					f.push(r.front());
					r.pop();
				}
				if(!f.empty() || (!l.empty() && t2 >= l.front())){
					s = "left";
					t2 += t;
				}else t2++;
			}
		}

		sort(v.begin(), v.end());

		for(int i=0; i<v.size(); i++){
			cout << v[i].second << endl;
		}
		if(c!=0) cout << endl;
	}
	return 0;
}