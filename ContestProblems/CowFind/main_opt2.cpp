#include<iostream>
#include<string>

using namespace std;
const string front = "))";
const string hind = "((";

int main(){
    string grass;
    cin >> grass;
    int N = grass.size();

    // naive pattern searching it gives O(2N) (SEE KMP:Knuth-morris-pratt hashing)
    int possibilities = 0;
    int coeff = 0;
    int j, k;
    for (int i=0; i < N - 2 + 1;i++) {
        j = 0;
        k=0;
        while(j < 2 && grass[i+j] == hind[j]){j++;}
        while(k < 2 && grass[i+k] == front[k]){k++;}
        if (j == 2){
            coeff++;
        }
        if (k==2){
            possibilities += coeff;
        }
    }
    cout<< possibilities <<endl;

}

// Good solution zack !!