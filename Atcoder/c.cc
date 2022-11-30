#include <bits/stdc++.h>

std::vector<int> divs(int n) {
	std::vector<int> ds {1};
	for (int x = 2; x * x <= n; x++) {
		if (n % x == 0) {
			if (n / x == x) {
				ds.push_back(n / x);
			} else {
				ds.push_back(n / x);
			       	ds.push_back(x);
			}
		}
	}
	return ds;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> f (divs(n));
	std::sort(f.begin(), f.end(), std::greater<int>());
	int r1 = 1, r2 = n - 1;
	if (f.size() != 1) {
		r1 = f[0], r2 = n - r1;
	}
	std::cout << r1 << ' ' << r2 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int tt;
	std::cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
