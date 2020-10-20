def change(mas,k):
    mesto = [0]*k

    for i in range(len(mas)):
        if mas[i] <= k:

            mesto[k-mas[i]] += 1

    res = [[(k-i)]*mesto[i] for i in range(k)]
    res_2 = []
    res2 = [ res_2.extend(i) for i in res]

    return  res_2

s  = [2,3,1,2,3,3,3,3]
print(change(s,3))