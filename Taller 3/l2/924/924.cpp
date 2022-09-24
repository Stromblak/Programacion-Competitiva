#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia
//	PD: Hecho en curso anterior

typedef vector<int> vi;
typedef vector<vi> vii;

vi dist;
vii adj;
map<int, int> mp;

void bfs(int s){
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v: adj[u]){
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				mp[dist[u]+1]++;
				q.push(v);
			}
		}
	}
}

int main(){
	int e;
	cin >> e;
		
	adj = vii(e);
	dist = vi(e, -1);

	for(int i=0; i<e; i++){
		int n;
		cin >> n;

		while(n--){
			int aux;
			cin >> aux;
			adj[i].push_back(aux);
		}
	}

	int t;
	cin >> t;
	while(t--){
		int n, max = -1, maxd;
		cin >> n;

		if(adj[n].empty()){
			cout << 0 << endl;
			continue;
		}else bfs(n);

		for(pair<int,int> v: mp){
			if(v.second > max){
				max = v.second;
				maxd = v.first;

			}
		}
		
		dist = vi(e, -1);
		mp.clear();

		cout << max << " " << maxd << endl;
	}

	return 0;
}