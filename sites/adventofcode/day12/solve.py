from collections import defaultdict

d = defaultdict(lambda: [])
visited = set()

N = int(input())
for _ in range(N):
	line = input()
	a, b = line.split('-')
	d[a].append(b)
	d[b].append(a)

def dfs(node):
	if node == 'end':
		return 1
	if node.islower() and node in visited:
		return 0
	visited.add(node)

	total = 0
	for subnode in d[node]:
		total += dfs(subnode)

	if node in visited:
		visited.remove(node)
	return total

print(dfs('start'))