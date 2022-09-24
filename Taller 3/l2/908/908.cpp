#include <bits/stdc++.h>
using namespace std;

//	Pablo Zapata
//	Solucion Propia
//	UVA 908

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj, adj2;
vi visited;



void prim(int s){
	priority_queue<ii, vii, greater<ii>> pq;
	visited[s] = 1;
	for(auto a: adj[s]) pq.push(a);

	while(true){
		while(!pq.empty() && visited[pq.top().second]) pq.pop();
		if(pq.empty()) break;	

		int vertex = pq.top().second;
		int c = pq.top().first;
		pq.pop();

		visited[vertex] = c;
		for(auto a: adj[vertex]) if(!visited[a.second]) pq.push(a);
	}

}

int main(){
	int n, flag = 0;
	while(cin >> n && n){
		if(flag) cout << endl;
		else flag = 1;

		int costo1 = 0;
		for(int i=0; i<n-1; i++){
			int c1, c2, aux;
			cin >> c1 >> c2 >> aux;
			costo1 += aux;
		}

		int k;
		cin >> k;
		map<pair<int,int>,int> mp;
		for(int i=0; i<k; i++){
			int c1, c2, costo;
			cin >> c1 >> c2 >> costo;
			if(mp[{c1,c2}] == 0) mp[{c1,c2}] = costo;
			else if(costo < mp[{c1,c2}]) mp[{c1,c2}] = costo;
		}

		int m;
		cin >> m;
		for(int i=0; i<m; i++){
			int c1, c2, costo;
			cin >> c1 >> c2 >> costo;
			if(mp[{c1,c2}] == 0) mp[{c1,c2}] = costo;
			else if(costo < mp[{c1,c2}]) mp[{c1,c2}] = costo;
		}

		adj = vector<vii>(n+1);
		visited = vi(n+1, 0);

		for(auto a: mp){
			adj[a.first.first].push_back({a.second, a.first.second});
			adj[a.first.second].push_back({a.second, a.first.first});		
		}


		prim(1);
		int costo2 = 0;
		for(int i=2; i<visited.size(); i++) costo2 += visited[i];


		cout << costo1 << endl << costo2 << endl;
	}
	return 0;
}