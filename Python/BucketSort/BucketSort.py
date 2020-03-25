class Bucket:
    def __init__(self):
        self.list = []

    def __add__(self, value):
        self.list.append(value)


def BucketSort(bucket, intList):
    newList = [None] * len(intList)
    for i in range(0, len(intList)):
        value = int(len(bucket) * intList[i])
        bucket[value].__add__(intList[i])

    for i in range(0, len(bucket)):
        InsertionSort(bucket[i].list)

    size = 0
    for i in range(0, len(bucket)):
        for j in range(0, len(bucket[i].list)):
            newList[size] = bucket[i].list[j]
            size += 1

    return newList


def InsertionSort(list):
    for i in range(1, len(list)):
        save = list[i]
        j = i - 1
        while j >= 0 and list[j] > save:
            list[j + 1] = list[j]
            j = j - 1

        list[j + 1] = save


if __name__ == "__main__":
    bucket = [Bucket() for i in range(10)]

    intList = [0.78, 0.17, 0.21, 0.26, 0.39, 0.94, 0.2]
    result = BucketSort(bucket, intList)

    print("Unsorted")
    for i in range(0, len(result)):
        print(intList[i], end=" ")

    print("\nSorted")
    for i in range(0, len(result)):
        print(result[i], end=" ")
