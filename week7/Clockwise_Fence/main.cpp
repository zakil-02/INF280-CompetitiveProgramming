#include<iostream>
#include<vector>
#include<complex>
#include <cstdlib>


using namespace std;

const char directions[4] = {'N','E','S','W'};
const complex<int> vectors[4] = {complex<int>(0,1),complex<int>(1,0),complex<int>(0,-1),complex<int>(-1,0)}; // corresponds to N,E,S,W

int main() {
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        string fence;
        cin >> fence;
        
        int cw_counter = 0;
        int ccw_counter = 0;

        for (int j = 0; j < fence.size() - 1; j++) {
            complex<int> v1;
            complex<int> v2;
            for (int k = 0; k < 4; k++) {
                if (fence[j] == directions[k]) {
                    v1 = vectors[k];
                }
                if (fence[j + 1] == directions[k]) {
                    v2 = vectors[k];
                }
            }
            int cross_product = v1.real() * v2.imag() - v1.imag() * v2.real();
            if (cross_product > 0) {
                ccw_counter++;
            } else if (cross_product < 0) {
                cw_counter++;
            }
        }
        if(cw_counter > ccw_counter){
            cout << "CW" << endl;
        }else{
            cout << "CCW" << endl;
        }
    }
    return 0;
}

