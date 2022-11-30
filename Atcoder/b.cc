#include <bits/stdc++.h>

void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;
	int res = std::min({(n + a - 1) / a, });
	std::cout << res << '\n';
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
