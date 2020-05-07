dic = {}
N = int(input())

for i in range(N):
    a, b = input().split()
    a = int(a)
    b = int(b)
    dic[a] = b;

R = int(input())

for j in range(R):
    valid = True
    symptoms = input().split()
    del symptoms[0]
    symptom_list = map(int, symptoms)
    result = []

    for k in symptom_list:

        if k in dic:
            result.append(dic[k])
        else:
            valid = False

    if valid:
        for l in result:
            print(l, end=" ")
    else:
        print("YOU DIED")