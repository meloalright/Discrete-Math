//qsort.cpp
#include <iostream>
using namespace std;
int a[101],n;
void qsort(int * a, int left, int right){
	int i,j,t,temp;
	if(left>right)
		return;

	temp=a[left];
	i = left;
	j = right;
	while(i!=j){
		//先从右边找
		while(a[j]>=temp && i < j)
			j--;//如果比基准大就没问题继续,比基准小就停下来
		//在找右边的
		while(a[i]<=temp && i < j)
			i++;//如果比基准小就没问题继续,比基准大就停下来
		if(i<j){//都停下来了就交换
			t = a[i];
			a[i]=a[j];
			a[j]= t;
		}
	}
	//最终相遇了就将基准数归位
	a[left] = a[i];//原基准位置得到a[i]
	a[i] = temp;//原a[i]得到基准数

	//递归
	qsort(a, left,i-1);//处理左边
	qsort(a, i+1,right);//处理右边
}
int main(){
	n=9;
	cout << "hello" << endl;
	for(int i;i<10;i++){
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	qsort(a,0,9);
	for(int j;j<10;j++){
		cout<< a[j] << " ";
	}
	return 0;
}