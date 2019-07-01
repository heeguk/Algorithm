from collections import deque

people = []
order = []
length, target = map(int, input().split(" "))

printout = "<"

for i in range(1, length + 1):
    people.append(i)

while len(people) != 0:
    for i in range(0, target-1):
        people.append(people.pop(0))
    printout = printout + str(people.pop(0)) + ", "

printout = printout[0:-2]

printout = printout + ">"
print(printout)

