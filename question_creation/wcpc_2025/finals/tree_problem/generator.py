import random

N_min = 1
N_max = 10 ** 5

A_min = 1
A_max = 10 ** 9

N = random.randint(N_min, N_max)
A = [random.randint(A_min, A_max) for i in range(N)]

M = N
A = []
while M > 0:
    k = random.randint(1, M)
    M -= k
    A += [random.randint(A_min, A_max)] * k

print(N)
print(' '.join([str(elem) for elem in A]))
