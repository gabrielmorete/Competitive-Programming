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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 5e3 + 10;

using coord = long double;
const long double pi = acos(-1);
const long double EPS = 1e-8;

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

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){return {-y, x}; }
	inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }

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

vector<point> intsec;
ll mske[MAXN], mskd[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	cin>>n>>m;

	vector<point> lft, rgt;

	int y;
	fr(i, n){
		cin>>y;
		lft.pb(point(-100, y));
	}

	fr(i, m){
		cin>>y;
		rgt.pb(point(100, y));
	}

	line vert = line(point(0, 0), point(0, 1)); // reta vertical

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			line aux = line(lft[i], rgt[j]);
			point mid = vert.get_intsec(line(aux));

			bool ok = 0;
			for (int k = 0; k < intsec.size(); k++) // já existe
				if (intsec[k] == mid){
					ok = 1;
					mske[k] |= (1ll<<i);
					mskd[k] |= (1ll<<j);
				}	
			if (!ok){ // novo
				intsec.pb(mid);
				mske[intsec.size() - 1] |= (1ll<<i);
				mskd[intsec.size() - 1] |= (1ll<<j);
			}	
		}

	int k = intsec.size();	
	int ans = 0;
	for (int i = 0; i < k; i++)
		for (int j = i; j < k; j++){ 
			ll e = mske[i] | mske[j]; // junta conjuntos
			ll d = mskd[i] | mskd[j];
			ans = max(ans, __builtin_popcountll(e) + __builtin_popcountll(d));
		}	


	cout<<ans<<endl;	

}