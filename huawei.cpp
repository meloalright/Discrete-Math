#include <iostream>
using namespace std;
int qr(int base){
    if(base < 3)
        return 0;
    else
    {
        return ((base/3)+qr(base%3+base/3));
    }
}
int main(){
    int n;
    cout << "cin n =";
    cin >> n;
    cout << qr(n) << endl;
}