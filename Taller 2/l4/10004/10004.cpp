#include <bits/stdc++.h>
using namespace std;

//	Nombre:		Pablo Zapata		
//	ID UVa: 	1210486
//	Problema:	UVa 10004	
//	Solucion:	Propia

typedef vector<int> vi;
typedef vector<vi> vii;

vi visited;
vii adj;
int flag;


void dfs(int u, int c){
	visited[u] = c;

	for(int v: adj[u]){
		if(visited[v] == c) flag = 1;
		else if(visited[v] == 0){
			if(c == 1) dfs(v, 2);
			if(c == 2) dfs(v, 1);
		}
	}
}

int main(){
	int n;
	while(cin >> n && n){
		int m;
		cin >> m;

		adj = vii(n);
		visited = vi(n);
		while(m--){
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		dfs(0, 1);

		if(flag) cout << "NOT BICOLORABLE." << endl;
		else cout << "BICOLORABLE." << endl;
		flag = 0;
	}

	return 0;
}