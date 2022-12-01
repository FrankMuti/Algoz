/**
 *	author:   stein
 *	created:  2022.11.30 21:25:44
**/
#include <bits/stdc++.h>

#define int long long

const long long mod = 1e9 + 7;

// Won't work (wrong)
auto factors(int n) {
	std::unordered_set<int> f;
	for (int x = 1; x * x <= n; x++) {
		if (n % x == 0) {
			f.insert(n / x);
			f.insert(x);
		}
	}
	return f;
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	long long n, res = 0;
	std::cin >> n;
	for (long long i = 1; i <= n; i++) {
		for (const auto& it : factors(i)) {
			(res += it) %= mod;
		}
	}
	std::cout << res << '\n';
	return 0;
}
