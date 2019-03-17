num, length = map(int, input().split(" "))
start = 0
ok = 1
while True:
    if length % 2 == 0:
        if (num + int(length/2)) % length == 0:
            start = (num + int(length/2))/length - int(length/2)
            break
        elif (num - int(length/2)) % length == 0:
            start = (num - int(length / 2))/length - int(length / 2) + 1
            break
    else:
        if num % length == 0:
            start = int(num/length) - int(length/2)
            break
    length = length + 1
    if length > 100:
        ok = 0
        break
if ok == 0:
    print(-1)
else:
    for i in range(0, length):
        if start < 0:
            print(-1)
            break
        print(int(start+i), end=" ")