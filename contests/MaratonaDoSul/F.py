N, K = [int(i) for i in input().split()]

a = []
b = []

for _ in range(N):
	ai, bi = [int(i) for i in input().split()]
	a.append(ai)
	b.append(bi)

inf = 1
sup = int(2e18+1e9)

while sup >= inf:
	m = (inf+sup)//2

	total = 0
	for i in range(N):
		if a[i] <= m:
			total += (m-a[i])//b[i] + 1

	if total < K:
		inf = m+1
	else:
		found = m
		sup = m-1

print(found)