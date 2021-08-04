#include <iostream>
using namespace std;

int books[10000];

int main()
{
    int N, M;
    
    while (cin >> N)
    {
        for (int i = 0; i < N; ++i){
            cin >> books[i];
        }

        for(int i = 0; i < N - 1; i++){
            for (int j = i + 1; j < N; j++){

                if(books[i] > books[j]){
                    int temp = books[i]; 
                    books[i] = books[j]; 
                    books[j] = temp; 
                }
            }
        }

        cin >> M;
        
        int i = 0, j = N - 1;
        int bookI, bookJ;
        while (i < j) {
            if (books[i] + books[j] < M){
                ++i;
            }
            else if (books[i] + books[j] == M) {
                bookI = i;
                bookJ = j;
                ++i; --j;
            }
            else {
                --j;
            }
        }
        
        cout << "Peter should buy books whose prices are " << books[bookI] << " and " << books[bookJ] << ".\n\n";
    }
}