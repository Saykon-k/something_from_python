import random


def sort_train(nubmer_of_wagon, k):
    mesto = [0] * k
    for i in range(len(nubmer_of_wagon)):
        if nubmer_of_wagon[i] <= k:
            mesto[k - nubmer_of_wagon[i]] += 1\

    res = []
    for i in range(k):
        res.extend([(k - i)] * mesto[i])

    return res


nubmer_of_wagon = [random.randrange(1, 50, 1) for i in range(10)]

print(sort_train(nubmer_of_wagon, max(nubmer_of_wagon)))
