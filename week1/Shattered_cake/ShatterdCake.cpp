#include <cstdio>
int main()
{
    while (1)
    {
        long long W, N;
        int ret = scanf("%lld %lld", &W, &N);
        if (ret != 2) {
            break;
        }
        long long area = 0;
        for (int i = 0; i < N; i++) {
            long long w, l;
            scanf("%lld %lld", &w, &l);
            area += w*l;
        }
        printf("%lld\n", area/W);

    }
    return 0;
}