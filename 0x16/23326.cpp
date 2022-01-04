#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // freopen("data.txt", "r", stdin);

    std::vector<int> locate(500'005, 0);
    std::set<int> a;
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> locate[i];
        if (locate[i] == 1) {
            a.insert(i);
        }
    }

    int s, e;
    // location
    int x = 0;

    while (m--) {
        std::cin >> s;

        if (s == 1) {
            std::cin >> e;
            e -= 1;
            if (locate[e] == 0) {
                locate[e] = 1;
                a.insert(e);
            }
            else {
                locate[e] = 0;
                a.erase(e);
            }
        }
        else if (s == 2) {
            std::cin >> e;
            x = (x + e) % n;
        }
        else {
            // s = 3;
            if (a.empty()) {
                std::cout << -1 << "\n";
            }
            else {
                auto it = a.lower_bound(x);

                if (it != a.end()) {
                    std::cout << (*it - x + n) % n << "\n";
                }
                else {
                    std::cout << (*a.begin() - x + n) % n << "\n";
                }
            }
        }
    }

    return 0;
}
