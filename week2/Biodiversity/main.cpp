#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    map<string, int> species;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name; // or getline(cin, name);
        species[name]++;
        sum++;
    }
    bool found = false;
    // iterate through the values of the map
    for (auto it = species.begin(); it != species.end(); it++) {
        if (it->second > sum - (it->second)) {
            printf("%s\n", it->first.c_str()); // or cout << it->first << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        printf("NONE\n");
    }
    return 0;
}
