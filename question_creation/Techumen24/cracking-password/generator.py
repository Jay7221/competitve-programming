import random

n = random.randint(1, 10 ** 3)
max_conditions = (n * (n - 1)) // 2
m = random.randint(0, min(10 ** 3, max_conditions))

print(f"{n} {m}")

nodes = [i + 1 for i in range(n)]
random.shuffle(nodes)

conditions = set()

if 2 * m > max_conditions:
    conditions = []
    for i in range(n):
        for j in range(i + 1, n):
            conditions.append((nodes[i], nodes[j]))
    random.shuffle(conditions)
    conditions = conditions[:m]
else:
    while len(conditions) < m:
        l = random.randint(0, n - 2)
        r = random.randint(l + 1, n - 1)
        conditions.add((nodes[l], nodes[r]))

print("\n".join([f"{l} {r}" for (l, r) in conditions]))

