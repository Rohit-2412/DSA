# Moore's voting algorithm
# a = [3, 1, 2, 2, 1, 2, 3, 3]
a = [4, 5, 6, 7, 8, 4, 4]
k = 3
n = len(a)
temp = [[0 for _ in range(2)]
        for _ in range(k)]

for i in range(k-1):
    temp[i][0] = 0

# temp [i][0] : count
# temp [i][1] : element
# process all elements of array
for i in range(n):
    j = 0
    # check if element is already present in temp array
    while j < k-1:
        if temp[j][1] == a[i]:
            temp[j][0] += 1
            break
        j += 1

    # not found
    if j == k-1:
        # check for available slot in temp
        l = 0
        while l < k-1:
            # empty slot
            if temp[l][0] == 0:
                temp[l][1] = a[i]
                temp[l][0] = 1  # occurrence as 1
                break
            l += 1

        # no empty slot found
        if l == k-1:
            # decrease the count of all the occurences by 1
            l = 0
            while l < k-1:
                temp[l][0] -= 1
                l += 1

for i in range(k-1):
    count = 0
    for j in range(n):
        if temp[i][1] == a[j]:
            count += 1
    if count > n//k:
        print(f'{temp[i][1]} occured {temp[i][0]} times')
