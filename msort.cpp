//msort.cpp
#include <iostream>
using namespace std;
//wiki
/*
template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
template<typename T> */
//整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
/*void merge_sort(T arr[], const int len) {
    T reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}*/

//melo
int a[8] = {1, 9, 7, 2, 5, 6, 3, 0};
int reg[8];//中转数组

void msort (int left, int right) {
    if(left >= right) {
        return;
    }
    int len = right - left;
    int mid = ( len >> 1 ) + left;//右移运算 len >> 1 等价于 len / 2
    int start1 = left, end1 = mid;
    int start2 = mid + 1, end2 = right;
    msort(start1, end1);//分治法
    msort(start2, end2);//分治法
    int k = left;
    //按顺序
    //分别从两数组收集
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
    while (start1 <= end1)
        reg[k++] = a[start1++];
    while (start2 <= end2)
        reg[k++] = a[start2++];

    //分治排序一次
    for (k = left; k <= right; k++) {
        a[k] = reg[k];
        //打印正在推到中转数组的变量
        cout << " " << reg[k];
    }
    //发生一次分治排序就打印trun
    cout << "\nturn"<< endl;
}
int main(){

    for(int j = 0;j<8;j++)
        cout<< a[j] << " ";
    cout<< endl <<  "==merge sort==" <<endl;
    
    //msort
    msort(0,7);

    return 0;
}