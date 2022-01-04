#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <map>
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
    
    int n;
    int x, y;
    std::string s;
    
    std::cin >> n;
    std::set<std::pair<int, int>> btree;
    // std::map<int, int> mm;
    std::vector<int> mm(100'001);

    for (int i = 0; i < n; i++) {
        // P, L
        std::cin >> x >> y;
        mm[x] = y;
        btree.insert(std::make_pair(y, x));
    }

    std::cin >> n;
    while (n--) {
        std::cin >> s;
        if (s == "add") {
            std::cin >> x >> y;
            mm[x] = y;
            btree.insert(std::make_pair(y, x));
        }
        else if (s == "recommend") {
            std::cin >> x;
            if (x == 1) {
                auto it = std::prev(btree.end());
                std::cout << it->second << "\n";
            }
            else {
                auto it = btree.begin();
                std::cout << it->second << "\n";
            }
        }
        else if (s == "solved") {
            std::cin >> x;
            int score = mm[x];
            auto it = btree.find(std::make_pair(score, x));
            btree.erase(it);
        }
    }
    return 0;
}
