# 정말 쉬운 문제
people = 0
result = 0
for i in range(4):
    out_, in_ = map(int, input().split(" "))
    people = people - out_ + in_
    result = max(result, people)
print(result)
