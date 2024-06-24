#include <cstdio>
#include<iostream>
using namespace std ;

int piles[10000+1];
int main()
{
    int N;
    cin >> N;
    int average = 0;
    for (int i=0; i<N; i++){
        cin >> piles[i];
        average += piles[i];
    }
    average = average / N; // always an integer.
    int moves = 0;

    for (int i=0; i<N; i++){
        int diff =  piles[i] - average ;
        if (diff < 0){
            moves -= diff  ;
        }else{
            continue;
        }
    }

    cout << moves << endl;


    return 0;
}