#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N; // this is to read the number of days in the input
    cin.ignore(); // Ignore the newline character after N

    int min_temp = 51, max_temp = -51; // Initialize with extreme values
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line); // Read the entire line
        istringstream iss(line);
        string date;
        iss >> date; // Read the date
        int temp;
        while (iss >> temp) { // Read each temperature
            min_temp = min(min_temp, temp);
            max_temp = max(max_temp, temp);
        }
    }
    cout << min_temp << " " << max_temp << endl;

    return 0;
}