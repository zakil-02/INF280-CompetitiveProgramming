#include <cstdio>
#include <string>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    set<string> monuments; // using set to store unique monuments.
    string line;

    // Read input line by line
    while (getline(cin, line)) {
        istringstream iss(line);
        string date, monument;

        // Read the date part
        if (!(iss >> date)) {
            cerr << "Error reading date from line: " << line << endl;
            continue;
        }

        // Read the rest of the line as the monument name
        getline(iss >> ws, monument); // Skip any leading whitespace

        // Insert the monument into the set
        monuments.insert(monument);
    }

    // Output the number of unique monuments
    printf("%d\n", static_cast<int>(monuments.size())); // cast to int to avoid warning

    return 0;
}
