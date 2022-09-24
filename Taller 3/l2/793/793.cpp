#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 793


vector<vector<int>> adj;
vector<int> visited;

int c, flag;

void dfs(int u){
	if(u == c) flag = 1;
	visited[u] = 1;
	for(int v: adj[u]) if(!visited[v]) dfs(v);
}


int main(){
	int n, m;
	cin >> n >> m;
	getchar();
	while(n--){	

		adj = vector<vector<int>>(m+1);
		int si = 0, no = 0, flag2 = 0;

		while(true){
			string s;
			getline(cin, s);
			if(s.empty()) break;

			stringstream ss(s);
			vector<string> vs;
			string aux;
			while(ss >> aux) vs.push_back(aux);

			if(vs.size() == 1){
				m = stoi(vs[0]);
				flag2 = 1;
				n++;
				break;
			}
			int c1 = stoi(vs[1]), c2 = stoi(vs[2]);

			if(vs[0] == "c"){
				adj[c1].push_back(c2);
				adj[c2].push_back(c1);
			}else{
				visited = vector<int>(m+1);
				flag = 0;
				c = c1;

				dfs(c2);
				if(flag) si++;
				else no++;
			}
		}
		if(flag2) flag2 = 0;
		else{
			cout << si << "," << no << endl;
			if(n) cout << endl;
		}
	}
	return 0;
}