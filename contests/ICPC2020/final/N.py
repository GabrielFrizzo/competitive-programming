N = int(input())

total = int(input().split('.')[1])
resp = 0
for _ in range(N):
	_, a = input().split('.')
	a = int(a)

	total += a
	if total % 100:
		resp += 1


print(resp)