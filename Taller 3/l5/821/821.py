import queue

# Pablo Zapata
# Uva 821
# Solucion Propia

def bfs(source, adj):
	dist = {}
	dist[source] = 0
 
	q = queue.Queue()
	q.put(source)
	
	while not q.empty():
		u = q.get()

		for a in adj[u]:
			if a not in dist:
				dist[a] = dist[u] + 1
				q.put(a)

	return dist


caso = 0
while True:
	caso += 1
	pares = list( map(int, input().split()) )

	pares.pop()
	pares.pop()
	if not len(pares):
		break

	vertices = set(pares)
	adj = {}
	for v in vertices:
		adj[v] = []

	for i in range(0, len(pares), 2):
		adj[ pares[i] ].append( pares[i+1] )

	suma = 0
	for v in vertices:
		dist = bfs(v, adj)
		suma += sum(dist[d] for d in dist)

	n = len(vertices)
	clicks = "{:.3f}".format( suma / (n*(n-1)) )
	print(f"Case {caso}: average length between pages = {clicks} clicks")