fac = [1, 1]
cat = [1, 1]

for i in range(2, 301):
	fac.append(fac[-1]*i)

for i in range(2, 301):
	cat.append(0)
	for j in range(0, i):
		cat[i] += cat[j]*cat[i-j-1]

res = [f"{str(cat[i]*fac[i])}" for i in range(1, 300)]

print()