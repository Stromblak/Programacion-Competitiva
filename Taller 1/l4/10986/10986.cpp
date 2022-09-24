#include <bits/stdc++.h>
using namespace std;

//Pablo Zapata
//Solucion Propia

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
vi dist;

void dijkstra(int s){
	priority_queue<ii, vii, greater<ii>> pq;
	dist[s] = 0;
	pq.push({0, s});

	while(!pq.empty()){
		int u_dist = pq.top().first;
		int u_vertex = pq.top().second;
		pq.pop();

		if(u_dist > dist[u_vertex]) continue;
		
		for(ii it: adj[u_vertex]){
			int v_vertex = it.first;
			int v_dist = it.second;

			if(u_dist + v_dist >= dist[v_vertex]) continue;
			dist[v_vertex] = u_dist + v_dist;
			pq.push({dist[v_vertex], v_vertex});
		}
	}
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int n, m, S, T;
		cin >> n >> m >> S >> T;

		dist = vi(n, INT_MAX);
		adj = vector<vii>(n);
		while(m--){
			int s1, s2, lat;
			cin >> s1 >> s2 >> lat;
			adj[s1].push_back({s2, lat});
			adj[s2].push_back({s1, lat});
		}
		dijkstra(S);
		if(dist[T] == INT_MAX) printf("Case #%d: unreachable\n", i+1);
		else printf("Case #%d: %d\n", i+1, dist[T]);
	}
	return 0;
}