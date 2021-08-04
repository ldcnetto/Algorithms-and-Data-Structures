#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int Weight;
    scanf("%d", &Weight);
    if(((Weight % 2) == 0) && (Weight > 2)){
        printf("YES");
    }
    else{
        printf("NO");
    }
}