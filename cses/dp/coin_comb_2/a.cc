/**
 *	author:   stein
 *	created:  2022.11.29 14:58:09
**/
#include <bits/stdc++.h>

constexpr int mod = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, x;
	std::cin >> n >> x;
	std::vector<int> c (n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	std::vector<std::vector<int>> r (n + 1, std::vector<int>(x + 1, 0));
	r[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			r[i][j] = r[i - 1][j];
			int left = j - c[i - 1];
			if (j >= c[i - 1]) {
				(r[i][j] += r[i][left]) %= mod;
			}
		}
	}
	std::cout << r[n][x] << '\n';
	return 0;
}
