#include<iostream>
#include<string>
#include<vector>

using namespace std;
const string front = "))";
const string hind = "((";

int main(){
    string grass;
    cin >> grass;
    int N = grass.size();
    vector<int> front_pos;
    vector<int> hind_pos;

    // naive searching O(2N). (SEE KMP:Knuth-morris-pratt hashing)
    int j, k;
    for (int i=0; i < N - 2 + 1;i++) {
        j = 0;
        k=0;
        while(j < 2 && grass[i+j] == hind[j]){j++;}
        while(k < 2 && grass[i+k] == front[k]){k++;}
        if (j == 2){
            hind_pos.push_back(i);
        }
        if (k==2){
            front_pos.push_back(i);
        }
    }

    int possibilities =0;
    for (auto pos_f : front_pos){
        for (auto pos_h : hind_pos){
            if (pos_h < pos_f){possibilities++;}
            else{break;}
        }
    }

    cout<< possibilities <<endl;

}
