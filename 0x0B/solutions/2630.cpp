#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

int white, blue;
int mat[128][128];

void func(int n, int r, int c)
{
	if (n == 1) {
		if (mat[r][c] == 0)
			white += 1;
		else
			blue += 1;

		return;
	}

	// 전체
	int sum = 0;
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			sum += mat[i][j];
		}
  	}
  
	if (sum == 0) {
		white += 1;
	}
	else if (sum == n * n){
		blue += 1;
	}
	else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int w = 0, b = 0;

				for (int row = (n / 2) * i; row < (n / 2) * (i + 1); row++) {
					for (int col = (n / 2) * j; col < (n / 2) * (j + 1); col++) {
						if (mat[r + row][c + col] == 0) {
							w += 1;
						}
						else {
							b += 1;
						}
					}
				}

				if (b == 0) {
					white += 1;
				}
				else if (w == 0) {
					blue += 1;
				}
				else {
					func(n / 2, r + (n / 2 * i), c + (n / 2 * j));
				}
			}
		}
	}
	
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	// freopen("data.txt", "r", stdin);
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> mat[i][j];
		}
	}

	func(n, 0, 0);
	std::cout << white << "\n" << blue << "\n";

	return 0;
}
