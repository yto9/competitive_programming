import bisect


class SquareRoot(object):
    def __init__(self, n):
        self.n = n

    def __getitem__(self, index):
        return index * index

    def __len__(self):
        return self.n


def try_square_root(n2):
    n = bisect.bisect_left(SquareRoot(n2), n2)
    return n if n*n == n2 else None


N, Q = list(map(int, input().split()))
a = [list(map(int, input().split())) for i in range(N)]
cxs = []
cys = []
rs = []
for i in range(N):
    cxs.append(a[i][0])
    cys.append(a[i][1])
    rs.append(a[i][2])
G = []
for i in range(Q):
    G.append(int(input()))

print(cxs)
print(cys)
print(rs)
ds = []
r1s = []
r2s = []
for i, (c1x, c1y, r1) in enumerate(zip(cxs, cys, rs)):
    if (i == N - 1):
        continue
    for j, (c2x, c2y, r2) in enumerate(zip(cxs, cys, rs)):
        if (j <= i):
            continue
        d = (c2x - c1x)**2 + (c2y - c1y)**2
        ds.append(d)
        r1s.append(r1**2)
        r2s.append(r2**2)
print(ds)
print(r1s)
print(r2s)
k = [0]*1000001
for i, (d, r1, r2) in enumerate(zip(ds, r1s, r2s)):
    k2c = 2*(d*r1+r1*r2+r2*d) - (d**2+r1**2+r2**2)
    k2m = 4*d
    if k2c < 0 or k2c % k2m != 0:
        continue
    k2 = k2c // k2m
    if k2 < 0:
        continue
    elif k2 == 0:
        k[0] += 1
    else:
        K = try_square_root(k2)
        if K is None:  # 0は？
            continue
        else:
            k[K] += 1
            k[0] += 1


for g in G:
    print(k[g])
