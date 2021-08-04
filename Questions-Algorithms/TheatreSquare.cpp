#include <iostream>

int main(){
    long long int n, m, a, square;

    std::cin>>n>>m>>a;
    square = (((n + a - 1)/a)) * ((m + a - 1)/a);
    std::cout<<square;
}