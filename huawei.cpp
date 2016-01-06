#include <iostream>
using namespace std;
double qr(int n,double base){
	if(n>1){
		base = base /3.0;
		return qr(n-1,base);
	}
	else
		return base;
}
int main(){
    double n=1.0/3;
    double count = 0;
    for(int i=1;i<100;i++){
    	count+=qr(i,n);
    	cout << "THAT "<< i <<" ="<< count << endl;
    }
    cout<<"FINAL = 1/3 + 1/9 + 1/27 ... + 1/n = "<< count << endl;
    return 0;
}