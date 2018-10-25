def phase(a):
    mod26 = (a-1) % 26
    if mod26 < 2:
        return 0
    elif mod26 < 10:
        return 1
    else:
        return 2


T = int(input())
a = [int(input()) for i in range(T)]
population = list(map(lambda x: pow(2, (x-1)//26), a))
current_phase = list(map(phase, a))
print("\n".join([" ".join(map(str, [population[i] if j == current_phase[i]
                                    else 0 for j in range(3)])) for i in range(T)]))
