def trans(a):
	resp = "B"
	while a:
		if a%2:
			resp = "B" + resp
		else:
			resp = "A" + resp
		a//=2

	return resp

def calc(a):
	if not a:
		return 1
	if a in memo:
		return memo

	if a[0] == "B":
		return calc(a[1:])

	return calc(a[1:]) + calc(a[2:])

memo = {}

d = {}

N = 10000
for i in range(N):
	curr = trans(i)
	a = calc(curr)
	if not a in d:
		d[a] = curr


for i in range(100):
	if i in d:
		print(i, d[i][1:])
	else:
		print("IMPOSSIBLE")