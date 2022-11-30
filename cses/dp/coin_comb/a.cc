/**
 *	author:   stein
 *	created:  2022.11.29 14:33:10
**/
#include <bits/stdc++.h>

constexpr long long mod = 1e9 + 7;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, x;
	std::cin >> n >> x;
	std::vector<int> c (n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	std::vector<long long> r (x + 1, 0);
	r[0] = 1;
	for (int xi = 1; xi <= x; xi++) {
		for (const auto& ci : c) {
			if (xi - ci >= 0) {
				(r[xi] += r[xi - ci]) %= mod;
			}
		}
	}
	std::cout << r[x] << '\n';
	return 0;
}
