from collections import deque

input()
ladys = list( map(int, input().split()) )
input()
luchu = deque( map(int, input().split()) )

while luchu:
	max, min = 0, 0
	for l in ladys:
		if luchu[0] > l:
			min = l
		elif luchu[0] < l:
			max = l
			break

	if min and max:
		print(min, ' ', max)
	if min and max == 0:
		print(min, ' ', 'X')
	if min == 0 and max:
		print('X', ' ', max)
	if min == 0 and max == 0:
		print('X', ' ', 'X')	

	luchu.popleft()

