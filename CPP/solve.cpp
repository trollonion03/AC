/**************************************************************
* CURRENT	: 	7662
* NEXT 		: 	7569
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 101

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
    cin >> t;

    int n;
    while (t--)
    {
        cin >> n;
        char order;
        int num;
        multiset<int> ms;
        while (n--)
        {
            cin >> order >> num;
            if (order == 'I')
            {
                ms.insert(num);
            }
            else
            {
                if (!ms.empty() && num == -1)
                {
                    ms.erase(ms.begin());
                }
                else if (!ms.empty() && num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
            }
        }
        if (ms.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            auto end_iter = ms.end();
            end_iter--;
            cout << *end_iter << ' ' << *ms.begin() << '\n';
        }
    }
	
	return 0;
}