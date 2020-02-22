mem_128 = [74,
106,
91,
96,
160,
100,
146,
125,
207,
66,
235,
70,
0,
23,
253,
80,
49,
103,
31,
39,
118,
119,
78,
49,
148,
14,
103,
3,
218,
25,
188,
81]

mem_256 = []

for local0 in range(len(mem_128)):
    local1 = 0
    local2 = 2
    while local0 != local1:
        local2 *= mem_256[local1]
        local1 += 1 
    mem_256.append(local2 + 1)
    # print(mem_256)
    x = mem_128[local0] ^ (mem_256[local0]%256)
    print(chr(x))