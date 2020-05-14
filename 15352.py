import sys


K, N = map(int, input().split())
A = sys.stdin.readline().split()
num_list = []
fan_num = 1
fan_data = 0
result = 0
j = 0
for i in A:
    num_list.append(fan_num)
    fan_num += 1

Q = int(input())
for z in range(Q):
    k = -1
    a, b = [int(x) for x in sys.stdin.readline().split()]
    if a == 1:
            if num_list[j] == b:
                del (num_list[j])
                del (A[j])
                j = 0
                break
            j += 1

    elif a == 2:
        t = -1
        valid = 0
        count = 0
        while True:
            k += 1
            if num_list[k] == b:
                fan_num = num_list[k]
                fan_data = A[k]
                break

        while True:
            t += 1
            if t < len(A):
                if A[t] == fan_data:
                    count += 1
                    if num_list[t] == fan_num:
                        valid = 1

                elif valid == 1:
                    result += count
                    break

                else:
                    count = 0
            else:
                result += count
                break
print(result)
