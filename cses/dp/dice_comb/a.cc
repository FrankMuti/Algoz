/**
*	author:   stein
*	created:  2022.11.29 14:26:33
**/
#include <bits/stdc++.h>

constexpr long long mod = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m = 6;
	std::cin >> n;
	std::vector<long long> r (n + 1, 0);
	r[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i - j >= 0) {
				(r[i] += r[i - j]) %= mod;
			}
		}
	}
	std::cout << r[n] << '\n';
	return 0;
}
