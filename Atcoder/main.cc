#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a (n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::unordered_map<int, int> mp;
	int res = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		curr += a[i];
		if (curr == x) {
			res++;
		}
		res += mp[curr - x];
		mp[curr]++;
	}
	std::cout << res << '\n';
	return 0;
}
