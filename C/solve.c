#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3f3f3f3f;
#define NOP ;
#define MAXV 100000

int n;

int main() {
    long long n, sum = 0, s = 1;
    scanf("%lld", &n);
    while(n)
    {
        if(n & 1)
        {
            sum += s;
        }
        s *= 3;
        n >>= 1;
    }
    printf("%lld\n", sum);
   
    return 0;
}