N, M = map(int, input().split())
Board_One = [[0]*M for i in range(N)]
Board_Two = [[0]*M for i in range(N)]
Board_Three = [[0]*M for i in range(N)]
Board_Four = [[0]*M for i in range(N)]
firstNum1 = 0
firstNum4 = 0
secondNum1 = 0
secondNum4 = 0
thirdNum1 = 0
thirdNum4 = 0
fourthNum1 = 0
fourthNum4 = 0
maxValue = 0

for n in range(N):
    BoardValue = list(input())
    for m in range(M):
        if BoardValue[m] == '.':
            Board_One[n][m] = BoardValue[m]
            Board_Two[n][m] = BoardValue[m]
            Board_Three[n][m] = BoardValue[m]
            Board_Four[n][m] = BoardValue[m]
        else:
            Board_One[n][m] = int(BoardValue[m])
            Board_Two[n][m] = int(BoardValue[m])
            Board_Three[n][m] = int(BoardValue[m])
            Board_Four[n][m] = int(BoardValue[m])

for j in range(N):
    for k in range(M):
        if j+1 != N and k+1 != M:
            if Board_One[j][k] == '.' and Board_One[j][k+1] == '.' and Board_One[j+1][k] == '.' and Board_One[j+1][k+1] == '.':
                Board_One[j][k] = 4
                Board_One[j][k+1] = 4
                Board_One[j+1][k] = 4
                Board_One[j+1][k+1] = 4

for j in range(N):
    for k in reversed(range(M)):
        if j+1 != N and k-1 != -1:
            if Board_Two[j][k] == '.' and Board_Two[j][k-1] == '.' and Board_Two[j+1][k] == '.' and Board_Two[j+1][k-1] == '.':
                Board_Two[j][k] = 4
                Board_Two[j][k-1] = 4
                Board_Two[j+1][k] = 4
                Board_Two[j+1][k-1] = 4

for j in reversed(range(N)):
    for k in range(M):
        if j-1 != -1 and k+1 != M:
            if Board_Three[j][k] == '.' and Board_Three[j][k+1] == '.' and Board_Three[j-1][k] == '.' and Board_Three[j-1][k+1] == '.':
                Board_Three[j][k] = 4
                Board_Three[j][k+1] = 4
                Board_Three[j-1][k] = 4
                Board_Three[j-1][k+1] = 4

for j in reversed(range(N)):
    for k in reversed(range(M)):
        if j-1 != -1 and k-1 != -1:
            if Board_Four[j][k] == '.' and Board_Four[j][k-1] == '.' and Board_Four[j-1][k] == '.' and Board_Four[j-1][k-1] == '.':
                Board_Four[j][k] = 4
                Board_Four[j][k-1] = 4
                Board_Four[j-1][k] = 4
                Board_Four[j-1][k-1] = 4

for p in range(N):
    for q in range(M):
        if Board_One[p][q] == '.':
            Board_One[p][q] = 1

for x in range(N):
    for z in range(M):
        if Board_One[x][z] == 4:
            firstNum4 += 4
        elif Board_One[x][z] == 1:
            firstNum1 += 1

for p in range(N):
    for q in range(M):
        if Board_Two[p][q] == '.':
            Board_Two[p][q] = 1

for x in range(N):
    for z in range(M):
        if Board_Two[x][z] == 4:
            secondNum4 += 4
        elif Board_Two[x][z] == 1:
            secondNum1 += 1

for p in range(N):
    for q in range(M):
        if Board_Three[p][q] == '.':
            Board_Three[p][q] = 1

for x in range(N):
    for z in range(M):
        if Board_Three[x][z] == 4:
            thirdNum4 += 4
        elif Board_Three[x][z] == 1:
            thirdNum1 += 1

for p in range(N):
    for q in range(M):
        if Board_Four[p][q] == '.':
            Board_Four[p][q] = 1

for x in range(N):
    for z in range(M):
        if Board_Four[x][z] == 4:
            fourthNum4 += 4
        elif Board_Four[x][z] == 1:
            fourthNum1 += 1

maxValue = firstNum1+firstNum4
if maxValue < (secondNum1+secondNum4):
    maxValue = secondNum1+secondNum4
elif maxValue < (thirdNum1+thirdNum4):
    maxValue = thirdNum1+thirdNum4
elif maxValue < (fourthNum1+fourthNum4):
    maxValue = fourthNum1+fourthNum4

print(maxValue, end="")