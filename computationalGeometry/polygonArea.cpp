#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#define mp make_pair
#define ull unsigned long long
using namespace std;

struct point {
	long long operator%(point &b) {
		return x * b.y - y * b.x;
	}
	point(long long a, long long b) {
		x = a;
		y = b;
	}
	point() {}
	long long x, y;
};

istream& operator>>(istream& s, point& a) {
	long long  x, y;
	cin >> x >> y;
	a = point(x, y);
	return s;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	long long r = 0;
	vector <point> v(n + 1);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	v[n] = v[0];
	for (int i = 0; i < n; i++)
		r += v[i] % v[i + 1];
	r = (r < 0 ? -r : r);
	cout << r / 2;
	if (r % 2)
		cout << ".5";
	else
		cout << ".0";
	return 0;
}
