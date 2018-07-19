#binarySearch.py

'''
 @ 二分查找
 @ l首先是一个排好序的列表 --类似书页
 @ target 要查找的目标
'''
def binary_search(l, target):
    low = 0
    high = len(l) - 1

    while (low < high):
        mid = (low + high) // 2
        if l[mid] > target:
            high = mid
        elif l[mid] < target:
            low = mid + 1
        else:
            return mid

    '''
     实际上此时low == high
     [无所谓]返回 low 还是 high
    '''
    return low if l[low] == target else False

#run here
li = [0, 1, 2, 3, 6, 7, 8, 19, 23, 77, 89, 100]
print('index = %s'%binary_search(li, 77))
print('index = %s'%binary_search(li, 89))
print('index = %s'%binary_search(li, 100))
print('index = %s'%binary_search(li, -100))
