#	Pablo Zapata
#	Solucion Propia
#	UVA 11264

t = int(input())

for i in range(t):
	input()

	coins = list( map(int, input().split()) )

	sum = 1
	total = 1

	for j in range(1, len(coins)-1):
		if sum + coins[j] < coins[j+1]:
			sum += coins[j]
			total += 1

	print(total+1)
