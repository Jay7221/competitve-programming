n = int(input())
arr = []

for i in range(n):
    arr.append(input().replace(" ", "").lower())

print(len(set(arr)))
