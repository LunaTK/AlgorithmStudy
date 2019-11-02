parent = {}
rank = {}

def make_set(v):
    parent[v] = v
    rank[v] = 0

def find(v):
    if parent[v] != v:
        parent[v] = find(parent[v])

    return parent[v]

def union(v,u):
    root1 = find(v)
    root2 = find(u)

    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root1] = root2

            if rank[root1] == rank[root2]:
                rank[root2] += 1

def kruskal(graph):
    for v in graph['vertices']:
        make_set(v)

    mst = []
    edges = graph['edges']
    edges = sorted(edges, key = lambda e:e[2])

    for edge in edges:
        v,u,weight = edge

        if find(v) != find(u):
            union(v,u)
            mst.append(edge)

    return mst

N = int(input())
M = int(input())
edge = list()

for i in range(M):
    temp = []
    temp = ((list(map(int,input().split()))))
    edge.append(temp)

vertic = []
for i in range(N):
    vertic.append(i)

graph = {}

graph['vertices'] = vertic
graph['edges'] = edge

sum = 0

for result in kruskal(graph):
    sum += result[2]

print(sum)
