def countSmallerElement(arr, item):
    l = 0
    h = len(arr) - 1
    while l <= h:
        mid = (l+h) // 2

        if arr[mid] <= item:
            l = mid + 1
        else:
            h = mid - 1
    return l


def median(arr):
    r = len(arr)
    c = len(arr[0])
    minElement = 10000
    maxElement = -1000

    for i in range(len(arr)):
        if arr[i][0] < minElement:
            minElement = arr[i][0]

        if arr[i][len(arr)-1] > maxElement:
            maxElement = arr[i][len(arr)-1]

    l = minElement
    h = maxElement

    desired = (r*c + 1) // 2
    while l < h:
        mid = (l + h)//2
        cnt = 0
        # check how many smaller elements are there for each row
        for i in range(r):
            cnt += countSmallerElement(arr[i], mid)

        if cnt < desired:
            l = mid+1
        else:
            h = mid

    return l


# print(countSmallerElement([1, 2, 3, 4, 6, 7, 8], 0))
m = [[1, 3, 5],
     [2, 6, 9],
     [3, 6, 9]]

print(median(m))
