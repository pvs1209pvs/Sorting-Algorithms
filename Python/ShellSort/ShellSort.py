def ShellSort(array):
    gap = int(len(array) / 2)

    # Keep looping while the size of gap reduces to zero
    while gap > 0:
        # Start from i = gap
        for i in range(gap, len(array)):
            temp = array[i]  # Save the i th element
            j = i
            # While j is greater than or equal to gap and the element at index j-gap is greater than element at index j
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]  # Swap the elements
                j = j - gap  # reduce the gap

            # Place the temp at the original position
            array[j] = temp
        # reduce the gap with each iteration
        gap = int(gap / 2)


# Print the sorted array
def printList(array):
    for i in range(0, len(array)):
        print(array[i])


if __name__ == "__main__":
    # Example
    array = [170, 45, 75, 90, 802, 24, 2, 66]
    ShellSort(array)
    printList(array)
