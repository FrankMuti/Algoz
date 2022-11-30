/**
 *	author:   stein
 *	created:  2022.11.29 15:16:26
**/
#include <bits/stdc++.h>

int res = INT_MAX;

int pow(int b, int e) {
	int res = 1;
	for (; e; b *= b, e >>= 1) {
		if (e & 1) res *= b;
	}
	return res;
}

int dig(int x, int n) {
	return (x / pow(10, n)) % 10;
}

void remove(int n, int st) {
	if (n == 0) {
		res = std::min(res, st);
		return;
	}
	int sz = (int) std::floor(std::log10(n) + 1);
	int mx = 0;
	for (int i = 0; i < sz; i++) {
		mx = std::max(dig(n, i), mx);
	}
	if (mx) {
		remove(n - mx, st + 1);
	}
}

// DP
int solve(int n) {
	std::vector<int> dp (n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i <= n; i++) {
		for (const char& d : std::to_string(i)) {
			dp[i] = std::min(dp[i], dp[i - (d - '0')] + 1);
		}
	}
	return dp[n];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::cout << solve(n) << '\n';	
	return 0;
}
