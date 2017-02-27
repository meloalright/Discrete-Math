#qsort.py

'''
 @ 快速排序
 @ py版本不再需要[重新依赖两个哨兵]
 @ pivot = l[0] 中枢参考点
 @ 列表推导式:[x for x in l[1:] if x < pivot]
 @ 递归调用 return qsort(lesser_list) + [pivot] + qsort(greater_list)
'''
def qsort(l):
    if l == []:
        return []

    pivot = l[0]

    lesser_list = [x for x in l[1:] if x < pivot]
    greater_list = [x for x in l[1:] if x > pivot]

    return qsort(lesser_list) + [pivot] + qsort(greater_list)






#run here
seq = [1, 4, 6, 9, -33, 65, 34, 0, 54, 0, 78, 2, -10]
print(qsort(seq))
'''
>>> [-33, -10, 0, 1, 2, 4, 6, 9, 34, 54, 65, 78]
'''