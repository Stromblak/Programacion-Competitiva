#include <bits/stdc++.h>
using namespace std;

//	Nombre:		Pablo Zapata		
//	ID UVa: 	1210486
//	Problema:	UVa 11838	
//	Solucion:	Propia

typedef vector<int> vi;
typedef vector<vi> vii;

vi visited;
vii adj;
vii adj2;


void dfs(int u){
	visited[u] = 1;
	for(int v: adj[u]) if(visited[v] == 0) dfs(v);
}

void dfs2(int u){
	visited[u] = 1;
	for(int v: adj2[u]) if(visited[v] == 0) dfs2(v);
}

int main(){
	int n, m;
	while(cin >> n >> m && n && m){

		adj = vii(n);
		adj2 = vii(n);
		visited = vi(n);
		while(m--){
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;

			adj[a].push_back(b);
			if(c == 2) adj[b].push_back(a);

			adj2[b].push_back(a);
			if(c == 2) adj2[a].push_back(b);
		}

		dfs(0);

		int flag = 1;
		for(int i: visited) if(i == 0) flag = 0;

		visited = vi(n);
		dfs2(0);
		for(int i: visited) if(i == 0) flag = 0;


		cout << flag << endl;
	}

	return 0;
}