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

using coord = ll;
const long double pi = acos(-1);
const ll EPS = 0;

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

	inline point rot90(){return point(-y, x); }
	inline void rot(long double ang){ *this = point(cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y); }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }
	
	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

void swap(point &a, point &b){ point aux = a; a = b; b = aux; }

struct line {
	point p; coord c; //p * <x,y> = c
	line() {} line(point _p, coord _c): p(_p), c(_c) {}
	line(point a, point b) : p((b - a).rot90()), c(p * a) {}
	line get_parall(point v){ return line(p, p * v); }// parallel line at point v
	line get_perp(){ return line(p.rot90(), c); }// perpendicular line

	bool contains(point v){ return sign(p * v - c) == 0; }
	bool intsec(line l){ return sign(p ^ l.p) != 0; } // false if is the same line

	long double dist(point v){ return abs(p * v - c) / p.norm(); }

	point get_intsec(line l){ coord d = p^l.p; return point((c*l.p.y - l.c*p.y)/d, (p.x*l.c - c*l.p.x)/d); }
};

struct comparator{
	point o;
	comparator(point _o): o(_o){}
	bool operator()(point a, point b){
		if (sign((a - o) ^ (b - o)) != 0)
			return sign((a - o) ^ (b - o)) > 0;
		return sign((a - o).norm2() - (b - o).norm2()) < 0;
	}
};

// build convex hull in nlog(n), n > 1, hull is in reverse clockwise order
vector<point> convex_hull(vector<point> v, int border_in){ // should border be in convex?
	swap(v[0], *min_element(all(v))); // lex_sort
	sort(v.begin() + 1, v.end(), comparator(v[0]));
	int sz = 2, s, nv = v.size();
	if (border_in){
		for (s = nv - 1; s > 1 and sign((v[s] - v[0]) ^ (v[s - 1] - v[0])) == 0; s--);
		reverse(v.begin() + s, v.end());	
	}
	vector<point> hull = {v[0], v[1]};
	for (int i = 2; i < nv; i++)
		if (sz < 2)
			hull.push_back(v[i]), sz++;
		else if (sign((hull[sz - 1] - hull[sz - 2]) ^ (v[i] - hull[sz - 1])) >= 1 - border_in)
			hull.push_back(v[i]), sz++;
		else
			hull.pop_back(), i--, sz--;
	return hull;	
}

long double ans;

void diameter_polygon(vector<point> v){
	int l, r, p = 2, nv = v.size();

	for (int i = 0; i < nv; i++){
		l = i, r = (i + 1) % nv;
		point lr = v[r] - v[l]; 
		while (sign(abs((v[(p + 1) % nv] - v[l]) ^ lr) - abs((v[p] - v[l]) ^ lr)) >= 0) 
			p = (p + 1) % nv;
		
		line c = line(v[l], v[r]);

		ans = min(ans, c.dist(v[p]));
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout<<setprecision(2)<<fixed;

	int n, cnt = 1;
	while (cin>>n and n > 0){	
		vector<point> pnt;

		int x, y;
		fr(i, n){
			cin>>x>>y;
			pnt.pb({x, y});
		}

		pnt = convex_hull(pnt, 0);

		ans = llINF;
		diameter_polygon(pnt);

		cout<<"Case "<<cnt++<<": "<<ans<<endl;
	}
}