#include <iostream>
using namespace std;

int main () {
    long long int i, j, n, cap, sum = 0, var = 0, can1 = 0, can2 = 0;

    cin >> n;
    for (i = 0; i < n; ++i){
        cin >> var;
        sum += var;
    }

    for(i = 0; i < n; i++){
        cin >> cap;
        if(cap >= can1){
            can2 = can1;
            can1 = cap;
        }
        else if(cap > can2){
            can2 = cap;
        }
    }

    if((can1 + can2) >= sum){
        cout<<"YES\n";
    } 
    else {
        cout<<"NO\n";
    }
}