#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

using coord = long long int;
const long long int EPS = 0;

int sign(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point& p){ return {x + p.x, y + p.y}; }
	inline point operator-(point& p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point& p){ x = p.x, y = p.y; }
	inline bool operator==(point& p){return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(thta)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(thta)

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  -1 left, 0 over, 1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){return {-y, x}; }
	// inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }
	inline point proj(point p){return p * (((*this) * p)/p.norm()); }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct line {
	point p; coord c; //p * <x,y> = c
	line() {} line(point _p, coord _c): p(_p), c(_c) {}
	line(point a, point b) : p((b - a).rot90()), c(p * a) {}
	line parll(point v){ return line(p, p * v); }// parallel line at point v
	line perp(){ return line(p.rot90(), c); }// perpendicular line

	bool contains(point v){ return sign(p * v - c) == 0; }
	bool intsec(line l){ return sign(p ^ l.p) != 0; } // can be the same line

	coord dist(point v){ return abs(p * v - c) / p.norm2(); }

	point get_intsec(line l){ coord d = p^l.p; return point((c*l.p.y - l.c*p.y)/d, (p.x*l.c - c*l.p.x)/d); }
};

int n;
vector<point> pnts, v;

bool test(line l, line q){
	for (auto x : pnts)
		if (!l.contains(x) and !q.contains(x))
			return false;
	return true;	
}

bool check(line q){
	v.clear();
	fr(i, n)
		if (!q.contains(pnts[i]))
			v.pb(pnts[i]);	

	if (v.size() <= 2)
		return true;	
	return test(line(v[0], v[1]), q);	
}

int32_t main(){
	fastio;

	cin>>n;

	if (n <= 4){
		cout<<"YES"<<endl;
		return 0;
	}

	ll x, y;
	fr(i, n){
		cin>>x>>y;
		pnts.pb(point(x, y));
	}

	line l = line(pnts[0], pnts[1]);
	fr(i, n)
		if (!l.contains(pnts[i]))
			v.pb(pnts[i]);

	if (v.size() <= 2){
		cout<<"YES"<<endl;
		return 0;
	}	

	point a, b, c, d;
	bool ans = 0;

	a = pnts[0], b = pnts[1], c = v[0], d = v[1];

	ans |= check(line(a, b));
	ans |= check(line(a, c));
	ans |= check(line(a, d));
	ans |= check(line(b, c));
	ans |= check(line(b, d));
	ans |= check(line(c, d));
	
	if (ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
