N, L, Q = input().split()
N = int(N)
L = int(float(L)*10)
Q = int(float(Q)*10)

names = input().split()
index = L//Q % N
if L%Q == 0:
	index -= 1

rest = (L%Q)/10
if rest == 0:
	rest = Q / 10
print(names[index], '{:.1f}'.format(rest))