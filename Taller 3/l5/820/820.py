import queue

# Pablo Zapata
# Uva 820
# Solucion propia

class Dinic:
	def __init__(self, n):
		self.adj = [ [] for i in range(n) ]
		self.lvl = [0] * n
		self.visited = [0] * n
		
	def insert_edge(self, a, b, c):
		self.adj[a].append([b, 0, c, len(self.adj[b])])
		self.adj[b].append([a, 0, 0, len(self.adj[a])-1])

	def bfs(self, source, sink):
		q = queue.Queue()
		q.put(source)
		self.lvl[source] = 1

		while not q.empty() and not self.lvl[sink]:
			v = q.get()

			for e in self.adj[v]:
				if not self.lvl[e[0]] and (e[2] - e[1]):
					self.lvl[e[0]] = self.lvl[v] + 1
					q.put(e[0])

		return self.lvl[sink]

	def dfs(self, vertex, sink, flow):
		if vertex == sink or not flow:
			return flow
			
		for e in self.adj[ vertex ][ self.visited[vertex]: ]:
			if self.lvl[e[0]] == self.lvl[vertex] + 1:
				f = self.dfs(e[0], sink, min(flow, e[2] - e[1]))
				if f:
					e[1] += f
					self.adj[e[0]][e[3]][3] -= f
					return f
			self.visited[vertex] += 1

		return 0

	def max_flow(self, source, sink):
		flow = 0

		while self.bfs(source, sink):	
			while True:
				f = self.dfs(source, sink, float("inf"))
				if f: flow += f
				else: break

			self.lvl = [0] * len(self.adj)	
			self.visited = [0] * len(self.adj)

		return flow

caso = 1
while True:
	n = int(input())
	if not n:
		break
	s, t, c = map(int, input().split())

	dinic = Dinic(c+1)
	for i in range(c):
		n1, n2, b = map(int, input().split())
		dinic.insert_edge(n1, n2, b)
		dinic.insert_edge(n2, n1, b)

	print("Network", caso)
	print(f"The bandwidth is {dinic.max_flow(s, t)}.")
	print()
	caso += 1