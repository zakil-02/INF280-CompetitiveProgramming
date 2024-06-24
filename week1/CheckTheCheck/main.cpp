#include <cstdio>
#include <string>

int main() {
    long total_to_pay = 0;
    long total = 0;

    while (1){
        std::string dk;
        int ret = scanf("%[^\n]", dk);
        if (ret == 0) {
            break;
        }
        if (dk == "TOTAL") {
            scanf("%ld", &total_to_pay);
            break;
        }else{

            long price;
            scanf("%d", &price);
            total += price;
            printf("%s %d\n", dk , price);
        }

    }
    if (total_to_pay <= total) {
        printf("PAY\n");
    } else {
        printf("PROTEST\n");
    }

    return 0;
}