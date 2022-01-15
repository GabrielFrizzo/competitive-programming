from collections import defaultdict

d = defaultdict(lambda: [])
visited = set()
twice = None
start = True

N = int(input())
for _ in range(N):
	line = input()
	a, b = line.split('-')
	d[a].append(b)
	d[b].append(a)

def dfs(node):
	global start, twice
	if node == 'end':
		return 1
	if node == 'start':
		if not start:
			return 0
		start = False
	if node.islower() and node in visited:
		if twice:
			return 0
		else:
			twice = node
	visited.add(node)

	total = 0
	for subnode in d[node]:
		total += dfs(subnode)

	if twice == node:
		twice = None
	elif node in visited:
		visited.remove(node)
	return total

print(dfs('start'))