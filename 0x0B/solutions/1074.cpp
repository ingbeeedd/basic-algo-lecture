#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

int func(int n, int r, int c)
{
	if (n == 0) {
		return 0;
	}
	int width = (1 << n) - 1;
	int height = (1 << n) - 1;
	int area = (1 << n) * (1 << n);

	if (r >= 0 && r <= height / 2) {
		if (c >= 0 && c <= width / 2) {
			return func(n - 1, r, c);
		}
		else {
			return int(0.25 * area) + func(n - 1, r, c - ((1 << n) / 2));
		}
	}
	else {
		if (c >= 0 && c <= width / 2) {
			return int(0.5 * area) + func(n - 1, r - ((1 << n) / 2), c);
		}
		else {
			return int(0.75 * area) + func(n - 1, r - ((1 << n) / 2), c - ((1 << n) / 2));
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	//freopen("data.txt", "r", stdin);
	int n, r, c;
	std::cin >> n >> r >> c;
	std::cout << func(n, r, c) << std::endl;

	return 0;
}
