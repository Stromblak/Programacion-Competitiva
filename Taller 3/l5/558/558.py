# Pablo Zapata
# Uva 1112
# Solucion Propia?, busque si habian algortimos que detectaran ciclos, me salio este y lo implemente

def Bellman_Ford(source, edges, n):
	dist = [float('inf')] * n
	dist[source] = 0

	for i in range( n-1 ):
		for u, v, w in edges:
			if dist[u] + w < dist[v]:
				dist[v] = dist[u] + w

	for u, v, w in edges:
		if dist[u] + w < dist[v]:
			return True
			
	return False

c = int( input() )
for i in range(0, c):
	n, m = map(int, input().split())

	edges = []
	for j in range(m):
		x, y, t = map(int, input().split())
		edges.append( (x, y, t) )
		
	if Bellman_Ford(0, edges, n):
		print("possible")
	else:
		print("not possible")
	