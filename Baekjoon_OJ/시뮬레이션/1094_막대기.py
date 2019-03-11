# 문제를 정확히 이해하면 쉽게 풀 수 있음.
start = [64]
length = int(input())
while True:
    if sum(start) > length:
        out = int((start.pop(-1)) / 2)
        start.append(out)
        if sum(start) < length:
            start.append(out)
    if sum(start) == length:
        print(len(start))
        break
