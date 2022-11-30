/**
 *	author:   stein
 *	created:  2022.11.30 18:25:58
**/
#include <bits/stdc++.h>

constexpr int mod = 1e9 + 7;

int res = 0;

// Inefficient
void solve(const std::vector<std::string>& a, int n, int i, int j) {
	if (i >= n || j >= n || a[i][j] == '*') {
		return;
	}
	if (i == n - 1 && j == n - 1) {
		res++;
		return;
	}
	solve(a, n, i + 1, j);
	solve(a, n, i, j + 1);
}

void solve2(const std::vector<std::string>& a) {
	int n = (int) a.size();
	std::vector<std::vector<int>> dp (n, std::vector<int> (n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '.') {
				if (i > 0)
					(dp[i][j] += dp[i - 1][j]) %= mod;
				if (j > 0)
					(dp[i][j] += dp[i][j - 1]) %= mod;
			} else {
				dp[i][j] = 0;
			}
		}
	}
	res = dp[n - 1][n - 1];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<std::string> a (n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	solve2(a);
	std::cout << res << '\n';
	return 0;
}
