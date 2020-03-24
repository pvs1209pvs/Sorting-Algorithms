class Bucket:
    def __init__(self):
        self.list = []

    def __add__(self, value):
        self.list.append(value)


def BucketSort(bucket, intList):
    for i in range(0, len(intList)):
        value = int(len(bucket) * intList[i])
        bucket[value].__add__(intList[i])


def InsertionSort(bucket):


if __name__ == "__main__":
    bucket = [Bucket() for i in range(10)]

    intList = [0.78, 0.17, 0.21, 0.26, 0.39, 0.94, 0.21]
    BucketSort(bucket, intList)

    for i in range(0, len(bucket)):
        print(bucket[i].list)
