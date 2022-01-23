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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 4e5 + 10;

using coord = long long;
const long double pi = acos(-1);
const long long EPS = 0;

int sign(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point p){ x = p.x, y = p.y; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(tht)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){ *this = point(-y, x); return {x, y}; }
	inline point rot(long double ang){ *this = point(cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y); return {x, y}; }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }
	
	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct comparator{
	point o;
	comparator(point _o): o(_o){}
	bool operator()(point a, point b){
		a = a - o; // If o is not in que lower left corner
		b = b - o;
		if (a.x < 0 and b.x >= 0)
			return false;
		if (a.x >= 0 and b.x < 0)
			return true;
		if (a.x >= 0 and sign(a.y) != sign(b.y))
			return a.y < b.y;

		if (sign((a - o) ^ (b - o)) != 0)
			return sign((a - o) ^ (b - o)) > 0;
		return sign((a - o).norm2() - (b - o).norm2()) < 0;
	}
};


long double ang(point p){
	long double ans = atan(abs(((double)p.x)/p.y))*180.0/pi;
			
	if (p.x >= 0){
		if (p.y > 0)
			ans = 180 - ans;
	}
	else{
		if (p.y > 0)
			ans += 180;
		else
			ans = 360 - ans;
	}

	return ans;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	vector<point> pnt;

	fr(i, n){
		int x, y;
		cin>>x>>y;

		pnt.pb(point(x, y));
	}

	sort(pnt.begin(), pnt.end(), comparator(point(0, 0)));

	long double ans = 360;

	fr(i, n - 1)
		ans = min(ans, 360 - (ang(pnt[i + 1]) - ang(pnt[i])));

	ans = min(ans, ang(pnt[n - 1]) - ang(pnt[0]));

	cout<<setprecision(9)<<fixed;
	cout<<ans<<endl;
}