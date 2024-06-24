#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>  // Include this to use numeric_limits

using namespace std;

static long pos_inf = numeric_limits<long int>::max();

int main()
{
    int N;
    // Use cin instead of scanf for simplicity
    cin >> N;
    cin.ignore();  // Ignore the newline character after the number input

    vector<vector<long int> > s(N, vector<long int>(N, 0));  // Initialize s with size N x N
    vector<long int> l(N);

    string line;
    getline(cin, line);  // Get the entire line of input

    stringstream ss(line);
    string c;
    int j = 0;

    while (ss >> c) {
        l[j] = stol(c);
        j++;
    }

    for (int j = 1; j < N; j++) {
        for (int i = 0; i < N - j; i++) {
            long c = 0;
            long min = pos_inf;
            for (int k = i; k < i + j; k++) {
                c += l[k];
                if (s[i][k] + s[k + 1][i + j] < min) {
                    min = s[i][k] + s[k + 1][i + j];
                }
            }
            c += l[i + j];
            s[i][i + j] = c + min;
        }
    }

    cout << s[0][N - 1] << endl;
    return 0;
}
