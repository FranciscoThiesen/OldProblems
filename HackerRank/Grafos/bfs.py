from math import *
n = int(raw_input())
for _ in range(n):
    nodes, edges = map(int, raw_input().split())
    adjList = []
    for _ in range(nodes):
        adjList.append([])
    for _ in range(edges):
        a,b = map(int, raw_input().split())
        adjList[a-1].append(b-1)
        adjList[b-1].append(a-1)
    root = int(raw_input())
    dist = []
    INF = 1000000000
    for _ in range(nodes):
        dist.append(INF)
    dist[root-1] = 0
    queue = [root-1]
    while(queue):
        node = queue.pop(0)
        for x in adjList[node]:
            if dist[x] == INF:
                dist[x] = dist[node] + 6
                queue.append(x)
    i = 0
    while i < len(dist):
        if i != root-1:
            if dist[i] != INF:
                print(dist[i]),
            else:
                print(-1),
        i = i + 1
    print("\n"),


