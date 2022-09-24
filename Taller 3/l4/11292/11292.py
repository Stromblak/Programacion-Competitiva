#	Pablo Zapata
#	Solucion Propia
#	UVA 11292

while True:
	n, m = input().split()
	n, m = int(n), int(m)
	if n == 0 and m == 0: 
		break

	dragon = []
	knight = []
	for i in range(n): 
		dragon.append( int(input()) )
	for i in range(m): 
		knight.append( int(input()) )

	dragon.sort()
	knight.sort()

	pago = 0
	while dragon and knight:
		if knight[0] >= dragon[0]:
			pago += knight[0]
			dragon.pop(0)
		knight.pop(0)

	if dragon:
		print("Loowater is doomed!")
	else:
		print(pago)