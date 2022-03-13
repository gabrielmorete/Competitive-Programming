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

using coord = long double;
const long double pi = acos(-1);
const coord EPS = 1e-8;

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

	inline point rot90(){ return point(-y, x);}
	// inline point rot(long double ang){ return point(cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y); 		}
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }
	
	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

void swap(point &a, point &b){ point aux = a; a = b; b = aux; }

struct halfplane{
	point p, d; // point and direction, valid points to the left of the plane
	long double ang;
	halfplane() {} halfplane(point _a, point _b) : p(_a), d(_b - _a){
		ang = atan2l(d.x, d.y);
	}

	// Check if a point is outside the halfplane (notice that inline is out)
	bool out(point o){ return sign(d^(o - p)) < 0; }

	inline bool operator<(halfplane &e){ 
        if (sign(ang - e.ang) == 0) 
        	return  (d ^ (e.p - p)) < 0;
        return ang < e.ang;
    } 

    inline bool operator==(const halfplane& e) const { return sign(ang - e.ang) == 0; }

    friend point inter(halfplane& s, halfplane& t){ // Intersection point of two non-parallel halfplanes
        long double alpha = ((t.p - s.p) ^ t.d) / (s.d ^ t.d);
        return s.p + (s.d * alpha);
    }
};

// Retuns the polygon of the intersection of all halfplanes in nlog(n)
// BE CAREFUL with the INF value for unbounded cases
bool halfp_intersect(vector<halfplane>& H) { 
	point box[4] = {point(INF, INF), point(-INF, INF), point(-INF, -INF), point(INF, -INF)};
	// Build bounding box to deal with unbound cases
	for (int i = 0; i < 4; i++)
		H.push_back(halfplane (box[i], box[(i+1) % 4]));

	// Sort and remove duplicates
	sort(H.begin(), H.end());
	H.erase(unique(H.begin(), H.end()), H.end());

	deque<halfplane> dq;
	int len = 0;
	for (int i = 0; i < int(H.size()); i++){
		while (len > 1 and H[i].out(inter(dq[len-1], dq[len-2])))
			dq.pop_back(), len--;

		while (len > 1 and H[i].out(inter(dq[0], dq[1])))
			dq.pop_front(), len--;

		dq.push_back(H[i]);
		++len;
	}

	while (len > 2 and dq[0].out(inter(dq[len-1], dq[len-2])))
		dq.pop_back(), len--;

	while (len > 2 and dq[len-1].out(inter(dq[0], dq[1])))
		dq.pop_front(), len--;

	if (len < 3) 
		return 0; // empty intersection

	return 1;

	// // Reconstruct the convex polygon from the remaining half-planes.
	// vector<point> ret(len);
	// for(int i = 0; i+1 < len; i++)
	// 	ret[i] = inter(dq[i], dq[i+1]);
	// ret.back() = inter(dq[len-1], dq[0]);

	// return ret;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;

	while (cin>>n and n > 0){
		vector<point> pol;

		fr(i, n){
			int x, y;
			cin>>x>>y;
			pol.pb({x, y});
		}

		pol.pb(pol[0]);

		vector<halfplane> h;
		fr(i, n)
			h.pb(halfplane(pol[i], pol[i + 1]));

		cout<<halfp_intersect(h)<<endl;
	}
}