def nextSmaller(arr):
    # result array
    res = [-1] * len(arr)
    # stak
    stack = []

    # traversing from end
    for i in range(len(arr)-1, -1, -1):
        # current element
        curr = arr[i]

        # keep popping element from stack untill you're getting a bigger element
        while len(stack) and arr[stack[-1]] >= curr:
            stack.pop()

        # we got the smaller element, store it as answer
        if len(stack):
            res[i] = stack[-1]
        else:
            res[i] = len(arr)
        # add the current number
        stack.append(i)
    # print(res)
    return res


def prevSmaller(arr):
    st = []
    res = [-1] * len(arr)

    for i in range(len(arr)):
        curr = arr[i]

        while len(st) and arr[st[-1]] >= curr:
            st.pop()

        if len(st):
            res[i] = st[-1]
        else:
            res[i] = -1

        st.append(i)

    # print(res)
    return res


def maxAreaHistogram(arr):
    ns = nextSmaller(arr)
    ps = prevSmaller(arr)

    area = 0

    for i in range(len(arr)):
        area = max((ns[i] - ps[i] - 1) * arr[i], area)

    # print(area)
    return area


def maxAreaMatrix(arr):
    tempArr = [0] * len(arr)
    area = 0
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j]:
                tempArr[j] += arr[i][j]
            else:
                tempArr[j] = 0

        print(tempArr)
        area = max(area, maxAreaHistogram(tempArr))

    print(area)


l = [[0, 1, 1, 0], [1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 0, 0]]
maxAreaMatrix(l)
