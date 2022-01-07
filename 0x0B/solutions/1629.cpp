// Authored by : yeongjae8066
// Co-authored by : -
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

long long func(long long a, long long b, long long c)
{
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a % c;
	}

	long long l, r;
	if (b % 2) { // odd
		l = func(a, b / 2, c);
		r = func(a, 1, c);
		
	}
	else { // even
		l = func(a, b / 2, c);
		r = func(a, 0, c);
	}
	
	return (((l * l) % c) * r) % c;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	freopen("data.txt", "r", stdin);
	long long a, b, c;
	
	std::cin >> a >> b >> c;
	long long answer = func(a, b, c);
	std::cout << answer << std::endl;

	return 0;
}
