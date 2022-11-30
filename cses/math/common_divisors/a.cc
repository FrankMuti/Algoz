/**
 *	author:   stein
 *	created:  2022.11.30 18:48:53
**/
#include <bits/stdc++.h>
 
std::set<int> factors(int n) {
	std::set<int> res;
	for (int x = 2; x * x <= n; x++) {
		while (n % x == 0) {
			res.insert(x);
			n /= x;
		}
	}	
	return res;
}

std::unordered_set<int> div(int n) {
	std::unordered_set<int> res;
	for (int x = 2; x * x <= n; x++) {
		if (n % x == 0) {
			res.insert(x);
			res.insert(n / x);
		}
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a (n);
	std::unordered_map<int, int> mp, mc;
	std::unordered_map<int, std::unordered_set<int>> mg;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		mp[a[i]]++;
	}
	std::sort(a.begin(), a.end());
	int g = 1;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (mp[x] > 1) {
			g = std::max(g, x);
		}
		auto st = div(x);
		int nx = x;
		for (const auto& xi : st) {
			mg[xi].insert(x);
			while (nx % xi == 0) {
				if (mp[nx / xi]) {
					g = std::max({g, nx / xi});
				}
				nx /= xi;
			}
		}
	}
	for (const auto& [x, y] : mg) {
		if (y.size() > 1) {
			g = std::max(g, x);
		}
	}
	std::cout << g << '\n';
	return 0;
}

