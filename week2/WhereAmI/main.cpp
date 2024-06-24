#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string sequence;
    scanf("%d", &N);
    cin >> sequence; //cin reads until whitespace --> use getline to read until newline
    for (int k=1; k<=N; k++) {
        vector<string> substrings;
        for (int i=0; i<=N-k; i++) {
            //take a substring of length k starting from i
            string sub = sequence.substr(i, k);
            substrings.push_back(sub);
        }
        //check if there are any duplicates
        bool unique = true;
        for (int i=0; i<substrings.size(); i++) {
            for (int j=i+1; j<substrings.size(); j++) {
                if (substrings[i] == substrings[j]) {
                    unique = false;
                    break;
                }
            }
            if (!unique) {
                break;
            }
        }
        if (unique) {
            printf("%d\n", k);
            break;
        }
    }
    return 0;
}
//remarks: 
//---------
// Here we know that N < 1000 so we allow ourselves to use such a solution that is O(N^2) in the worst case.
// We can also use a hash table to store the substrings and check if they are unique in O(1) time. 
// This will reduce the time complexity to O(N) in the worst case.
// we can also procede with a binary search to find the smallest k that satisfies the condition.