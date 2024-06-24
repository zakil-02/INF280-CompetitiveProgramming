#include<iostream>
#include<string>

using namespace std;
const string front = "))";
const string hind = "((";

int main(){
    string grass;
    cin >> grass;
    int N = grass.size();

    // naive searching O(2N). (SEE KMP:Knuth-morris-pratt hashing)
    int possibilities = 0;
    int j, k;
    for (int i=0; i < N - 2 + 1;i++) {
        j = 0;
        while(j < 2 && grass[i+j] == hind[j]){j++;}
        if (j == 2){
            for (int m=i+2; m < N - 2 + 1;m++) {
                k=0;
                while(k < 2 && grass[m+k] == front[k]){k++;}
                if (k==2){
                    possibilities++;
                }
            }
        }
    }

    cout<< possibilities <<endl;

}
