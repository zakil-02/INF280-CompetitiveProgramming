#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int main()
{   
    vector<int> valeurs(7);
    for (int i = 0; i < 7; i++) {
        cin >> valeurs[i];
    }
    for (int i = 0; i < 7; i++) {
        int above = 0;
        int under = 0;
        for (int j = 0; j < 7; j++) {
            if (j ==i){continue;}
            if (valeurs[i] > valeurs[j]){
                under++;
            }else if(valeurs[i] < valeurs[j]){
                above++;
            }else{
                continue;
            }

        }
        if (above <= 3 && under <= 3){
            cout << valeurs[i] << endl;
            break;
        }
    }

    return 0;
}