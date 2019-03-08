# 이 문제는 직접 그려보면 점화식이 쉽게 유추된다
# 파도반 수열 9461번
tc = int(input())
triangle = [0, 1, 1, 1, 2, 2] + [0] * 95
for i in range(6, 101):
    triangle[i] = triangle[i-1] + triangle[i-5]
for i in range(0, tc):
    num = int(input())
    print(triangle[num])
