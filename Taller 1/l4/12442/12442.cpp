#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

typedef vector<int> vi;
typedef vector<vi> vii;


vi visited;
vii adj;

int rec = 0;
vi tamRec;

int dfs(int u){
	visited[u] = 1;
	for(int v: adj[u]) if(!visited[v]) rec = 1 + dfs(v);
	tamRec[u] = rec;
	visited[u] = 0;
	return rec;
}

int main(){
	int n;
	cin >> n;
	int k = n;
	while(n--){
		int m;
		cin >> m;

		adj = vii(m+1);
		visited = vi(m+1);
		tamRec = vi(m+1);
		for(int i=0; i<m; i++){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		
		int max=0, mar;
		for(int i=1; i<=m; i++){
			rec = 0;
			if(!tamRec[i]) dfs(i);
			if(max < tamRec[i]){
				max = tamRec[i];
				mar = i;
			}
		}
		cout << "Case "<< k-n << ": " << mar << endl;
	}

	return 0;
}