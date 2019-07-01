def find(q, val):
    for index in range(0, len(q)):
        if val == q[index]:
            print(1234)
            return index


length, target_num = map(int, input().split(" "))
target = list(map(int, input().split(" ")))

queue = []
for i in range(1, length+1):
    queue.append(i)

move = 0

for i in target:
    index2 = 0
    for index in range(0, len(queue)):
        if i == queue[index]:
            index2 = index
            break
    left = index2  # left move

    right = int(len(queue)) - index2  # right move
    # choose direction, and move
    if left <= right:
        for j in range(0, left):
            queue.append(queue.pop(0))
        move = move + left
    else:
        for j in range(0, right):
            queue.insert(0, queue.pop(-1))
        move = move + right
    queue.pop(0)

print(move)
