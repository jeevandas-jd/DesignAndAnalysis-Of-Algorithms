#include <iostream>

using namespace std;

int fibbnocci(int n){

    if (n==0){
        return n;
    }
    else if (n==1)
    {
        return 1;
    }
    else{
        return fibbnocci(n-1)+fibbnocci(n-2);
    }
    
}

