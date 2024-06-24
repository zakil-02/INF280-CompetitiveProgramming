#include<cstdio>
#include<iostream>
#include<vector>
#include<complex>
#include <cstdlib>


using namespace std;

long int total_area = 0;  // here i will store the areas of the icebergs


int main() {
    int N; // number of ICEBERGS
    cin >> N;
    for (int i = 0; i < N; i++) {
        int P; // number of points
        cin >> P;
        vector<complex<long int>> iceberg;
        for (int j = 0; j < P; j++) {
            long int x, y;
            cin >> x >> y;
            iceberg.push_back(complex<long int>(x, y));
        }
        // calculate the area of the iceberg
        long double area = 0;
        for (int j = 1; j < P-1; j++) {
            complex<long int> p1 = iceberg[j] - iceberg[0];
            complex<long int> p2 = iceberg[j+1] - iceberg[0];

            area += (p1.real()*p2.imag() - p1.imag()*p2.real());
        }

        total_area += abs(area);

    }

    total_area = total_area / 2; 
    cout << total_area << endl;

    return 0;
}



// Attention ! La division doit s effectuer a la fin. 
// Sinon, on aura des erreurs de precision.