#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	bool ok = true;
	for (int i = 0, j = 1; ok && i < n; i++, j++) {
		if (j % 2 == 0) {
			if (i + 1 >= n || s[i + 1] != s[i]) {
				ok = false;
			}
			i++;
		}
	}
	std::cout << (ok ? "YES" : "NO") << '\n';
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
