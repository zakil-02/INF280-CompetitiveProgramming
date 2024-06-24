#include <iostream>
#include <cstdio>

using namespace std;
char grid[1000+1][80+1]; //MAX VALUE
int W, H;

const int NOT_VISITED = 0, IN_VISIT = 1, VISITED = 2;
int state[1000+1][80+1]; 
int diri[4] = {0, 1, 0, -1}, dirk[4] = {-1, 0, 1, 0};

void dfs(int i, int k, int &increm);

int main() {
    cin >> W >> H; 
    for (int i = 0; i < H; i++) {
        for (int k = 0; k < W; k++) {
            cin >> grid[i][k];
            state[i][k] = NOT_VISITED; 
        }
    }

    int largest_pasture = 0;
    for (int i = 0; i < H; i++) {
        for (int k = 0; k < W; k++) {
            // if the cell has been already visited (through another one or stating from it) there is no need to revisit it !!!!
            if (grid[i][k] == '*' && state[i][k] == NOT_VISITED) { 
                int length_pasture = 1; 
                dfs(i, k, length_pasture);
                if (length_pasture > largest_pasture) {
                    largest_pasture = length_pasture;
                }
            }
        }
    }

    cout << largest_pasture << endl;

    return 0;
}

void dfs(int i, int k, int &increm) {
    state[i][k] = IN_VISIT;

    for (int m = 0; m < 4; m++) {
        int x = i + diri[m];
        int y = k + dirk[m];

        if (x >= 0 && x < H && y >= 0 && y < W && grid[x][y] == '*' && state[x][y] == NOT_VISITED) {
            increm++;
            dfs(x, y, increm);
        }
    }

    state[i][k] = VISITED;
}
