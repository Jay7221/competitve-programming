import random

T = random.randint(1, 10)

print(T)
for t in range(T):
    N = random.randint(1, 10 ** 3)
    X = [random.randint(1, 10 ** 9) for i in range(N)]
    A = [random.randint(1, 10 ** 9) for i in range(N)]

    print(N)
    print(" ".join([str(x) for x in X]))
    print(" ".join([str(a) for a in A]))
