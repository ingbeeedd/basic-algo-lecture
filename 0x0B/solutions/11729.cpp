#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

/*
n-1개의 원판을 기둥 1에서 기둥 2로 옮긴다
n번 원판을 기둥 1에서 기둥 3으로 옮긴다
n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다

원판이 1개일 때는 내가 원하는 곳으로 옮길 수 있다
원판이 k개일 때 옮길 수 있다면 k+1개일 때에도 옮길 수 있다
*/

// 원판 n개를 a 기둥에서 b 기둥으로 옮기는 것
void func(int a, int b, int n)
{
	if (n == 1) {
		std::cout << a << ' ' << b << "\n";
		return;
	}
	func(a, 6 - a - b, n - 1);
	// 옮기는 행위
	std::cout << a << ' ' << b << "\n";
	func(6 - a - b, b, n - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::cout << (1 << n) - 1 << std::endl;
	func(1, 3, n);
	return 0;
}
