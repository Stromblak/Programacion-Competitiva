#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

typedef vector<int> vi;
typedef vector<vi> vii;

vi visited;
vii adj;
vii dom;
int actual;

void dfs(int u){
	visited[u] = 1;
	dom[u][u] = 1;

	for(int v: adj[u])
		if(!visited[v]){	
			dom[actual][v] = 1;
			dfs(v);
		}
}

int main(){
	int n;
	cin >> n;
	for(int I=0; I<n; I++){
		int m;
		cin >> m;

		adj = vii(m);
		dom = vii(m);
		visited = vi(m);

		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++){
				int aux;
				cin >> aux;
				if(aux) adj[i].push_back(j);
				dom[i].push_back(0);
			}
		}

		for(int i=0; i<m; i++){
			actual = i;
			visited[i] = 1;
			dfs(0);
			visited[i] = 0;

			for(int j=0; j<dom[i].size(); j++){
				if(dom[i][j]) visited[j] = 0;
				if(i && i!=j){
					if(dom[0][j] == dom[i][j]) dom[i][j] = 0;
					else if(j != 0) dom[i][j] = 1;
				}
			}
		}

		//--------------------------------------
		cout << "Case " << I+1 << ":" << endl;
		for(int i=0; i<m; i++){ 
			cout << "+";
			for(int i=0; i<2*m-1; i++) cout << "-";
			cout << "+" << endl;

			for(int j=0; j<m; j++){
				if(dom[i][j]) cout << "|Y";
				else cout << "|N";
			}
			cout << "|" << endl;
		}
		cout << "+";
		for(int i=0; i<2*m-1; i++) cout << "-";
		cout << "+" << endl;
	}

	return 0;
}