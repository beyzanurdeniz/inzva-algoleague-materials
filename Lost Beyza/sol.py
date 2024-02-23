import heapq

n, m = map(int, input().split())

N = 2 * 10 ** 5 + 3
a = []
came_from = [-1 for _ in range(N)]

for i in range(N):
    tmp = []
    if i - 1 >= 0:
        tmp.append(i - 1)
    else:
        tmp.append(-1)
    if 3 * i < N:
        tmp.append(3 * i)
    else:
        tmp.append(-1)
    if i + 4 < N:
        tmp.append(i + 4)
    else:
        tmp.append(-1)
    if i % 2 == 0:
        tmp.append(i // 2)
    else:
        tmp.append(-1)
    a.append(tmp)

heapq_ = []
dist = [10**18 for _ in range(N)]
dist[n] = 0
heapq.heappush(heapq_, (0, n))

while len(heapq_) > 0:
    d, u = heapq.heappop(heapq_)
    x1 = a[u][0]
    x2 = a[u][1]
    x3 = a[u][2]
    x4 = a[u][3]

    if 0 <= x1 < N and dist[x1] > d + 1:
        dist[x1] = d + 1
        heapq.heappush(heapq_, (d + 1, x1))
        came_from[x1] = u
    if 0 <= x2 < N and dist[x2] > d + 1:
        dist[x2] = d + 1
        heapq.heappush(heapq_, (d + 1, x2))
        came_from[x2] = u

    if 0 <= x3 < N and dist[x3] > d + 1:
        dist[x3] = d + 1
        heapq.heappush(heapq_, (d + 1, x3))
        came_from[x3] = u

    if 0 <= x4 < N and dist[x4] > d:
        dist[x4] = d
        heapq.heappush(heapq_, (d, x4))
        came_from[x4] = u

print(dist[m])

path = []
while m != n:
    path.append(m)
    m = came_from[m]
path.append(n)
path.reverse()

print(' '.join(map(str, path)))