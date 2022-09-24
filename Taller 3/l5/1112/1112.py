import queue

# Pablo Zapata
# Uva 1112
# Solucion Propia

def dikstra(source, adj, n):
	pq = queue.PriorityQueue()
	pq.put( (0, source) )

	dist = [float('inf')] * n
	dist[source] = 0

	while not pq.empty():
		u_dist, u = pq.get()

		if u_dist <= dist[u]: 
			for a in adj[u]:
				v, v_dist = a

				if u_dist + v_dist < dist[v]:
					dist[v] = u_dist + v_dist
					pq.put( (dist[v], v) )
	
	return dist


c = int( input() )
for i in range(c):
	input()
	n, e, t, m = [ int(input()) for j in range(4) ]

	adj = [ [] for j in range(n) ]
	for j in range (m):
		a, b, tAux = map(int, input().split())
		adj[b-1].append( (a-1, tAux) )
	
	print( sum(d <= t for d in dikstra(e-1, adj, n)) )
	if i+1 != c:
		print()