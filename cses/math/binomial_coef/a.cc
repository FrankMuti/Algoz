/**
 *	author:   stein
 *	created:  2022.12.01 00:37:17
**/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int maxN = 1000000;
constexpr int mod = (int) 1E9 + 7;
constexpr int P = 1000000007;

int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Z;

/**
 * // https://codeforces.com/contest/1761/submission/181811738
**/
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

constexpr int N = 4E6;

std::vector<Z> fac(N + 1), inv(N + 1);

Z binom(int n, int m) {
	if (n < m || m < 0) {
		return 0;
	}
	return fac[n] * inv[m] * inv[n - m];
}

void build_fac() {
	fac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i;
	}
	inv[N] = fac[N].inv();
	for (int i = N; i; i--) {
		inv[i - 1] = inv[i] * i;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	build_fac();
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		i64 a, b;
		std::cin >> a >> b;	
		std::cout << binom(a, b) << '\n';
	}
	return 0;
}
