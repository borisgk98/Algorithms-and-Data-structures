#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <random>
#include <time.h>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#define mp make_pair
#define ull unsigned long long
#define ll long long
using namespace std;

struct point {
	int x, y;
	int operator*(point &a) {
		return x*a.x + y*a.y;
	}
	int operator%(point &a) {
		return x*a.y - y*a.x;
	}
	point() {}
	point(int a, int b) {
		x = a;
		y = b;
	}
	int len() {
		return (*this)*(*this);
	}
	bool operator<(point &a) {
		return ((*this)%a ? (*this) % a > 0 : this->len() < a.len());
	}
	point operator-(point &a) {
		return point(x - a.x, y - a.y);
	}
};

istream& operator>>(istream &s, point &a) {
	cin >> a.x >> a.y;
	return s;
}

vector <point> conv_hull(vector <point> v) {

	int n = v.size();
	int xm = v[0].x, ym = v[0].y, im = 0;
	for (int i = 1; i < n; i++) {
		if (v[i].x < xm || (v[i].x == xm && v[i].y <= ym)) {
			xm = v[i].x;
			ym = v[i].y;
			im = i;
		}
	}
	swap(v[0], v[im]);
	for (int i = n - 1; i >= 0; i--)
		v[i].x -= v[0].x;
	for (int i = n - 1; i >= 0; i--)
		v[i].y -= v[0].y;
	sort(v.begin() + 1, v.end());
	v.push_back(v[0]);
	vector <point> s(n + 2);
	int len = 0;
	s[len] = v[0];
	for (int i = 1; i <= n; i++) {
		while (len > 0 && ((s[len] - s[len - 1]) % (v[i] - s[len]) <= 0))
			len--;
		s[++len] = v[i];
	}

	return vector <point>(s.begin(), s.begin() + len);
}

double len(point &a, point &b) {
	return sqrt(double((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

int main() {
	ios::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector <point> v(n);
	int xm = 0, ym = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		xm = min(xm, v[i].x);
		ym = min(ym, v[i].y);
	}
	for (int i = 0; i < n; i++) {
		v[i].x -= xm;
		v[i].y -= ym;
	}
	vector <point> hull = conv_hull(v);
	double p = len(hull[0], hull[hull.size() - 1]);
	for (int i = 0; i < hull.size() - 1; i++)
		p += len(hull[i], hull[i + 1]);
	cout << p;
	return 0;
}