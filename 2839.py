N = int(input())
num = 0

while True:
    if N % 5 == 0:
        print(N//5+num)
        break
    elif N <= 0:
        print(-1)
        break

    N -= 3
    num += 1