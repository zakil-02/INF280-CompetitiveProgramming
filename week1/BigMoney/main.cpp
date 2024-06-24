#include <cstdio>
#include <string>

using namespace std;

int main() {
    long double total_expenses = 0.0;

    while (1) {
        long double expense;
        int ret = scanf("%Lf", &expense);
        if (ret != 1) {
            break;
        }
        total_expenses += expense;
    }
    printf("%.2Lf\n", total_expenses);
    return 0;
}