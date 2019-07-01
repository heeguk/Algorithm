line = int(input())

for i in range(0, line):
    op = input()
    length = int(input())
    temp = input()
    if length != 0:
        number = list(map(int, temp[1:-1].split(",")))
    else:
        number = []

    size = len(op)
    start = 0
    end = length - 1
    error = 0
    for j in range(0, size):
        if op[j] == 'R':
            start, end = end, start
        elif op[j] == 'D':
            if length == 0:
                error = 1
                break
            else:
                length = length - 1
                if start > end:
                    start = start - 1
                else:
                    start = start + 1
    if error == 1:
        print("error")
    else:
        out = ""
        if length == 0:
            print("[]")
        else:
            if start > end:
                count = start - end + 1
                out = "["
                for k in range(0, count):
                    if k == count - 1:
                        out = out + str(number[start - k]) + "]"
                    else:
                        out = out + str(number[start - k]) + ","
            else:
                count = end - start + 1
                out = "["
                for k in range(0, count):
                    if k == count - 1:
                        out = out + str(number[start + k]) + "]"
                    else:
                        out = out + str(number[start + k]) + ","
            print(out)