#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino
int fibonacci(int n){
    int f0 = 0;
    int f1 = 1;
    int res = 0;
    if(n==1){
        res = f1;
    }
    if(n==0){
        res = f0;
    }
    for(int i = 2; i<=n; i++){
        res = f1 + f0;
        f0 = f1;
        f1 = res;
    }
    return res;
}
int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}