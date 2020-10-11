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
const int MAXN = 1e5 + 10;

using coord = long double;
const long double pi = acos(-1);
const long double EPS = 1e-8;

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

	inline point rot90(){return {-y, x}; }
	inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }

	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

void swap(point &a, point &b){ point aux = a; a = b; b = aux; }


struct segment {
	point a, b; // a != b
	segment() {} segment(point _a, point _b): a(_a), b(_b) {}

	bool contains(point p){ return sign((p-a)^(b-a)) == 0 and sign((p-a)*(b-a)) >= 0 and sign((p-b)*(a-b)) >= 0; }
	bool intsec(segment q){ segment p = *this;
		if (p.contains(q.a) or p.contains(q.b) or q.contains(p.a) or q.contains(p.b)) return true;
		return p.ccw(q.a-p.a)*p.ccw(q.b-p.a) == -1 and q.ccw(p.a-q.a)*q.ccw(p.b-q.a) == -1;	
	}

	int ccw(point p){ return((b - a).ccw(p - a)); } // ccw  1 left, 0 over, -1 right  of seg a->b

	coord len2(){ return (a - b).norm2(); }
	coord dist(segment q){segment p = *this; 
		return p.intsec(q)? 0 : min({p.dist(q.a), p.dist(q.b), q.dist(p.a), q.dist(p.b)});	}
	coord dist(point p){
		if (sign(((p - a) * (b - a))) >= 0 and sign((p - b) * (a - b)) >= 0)
			return abs((p - a) ^ (b - a)) / (b - a).norm();
		return min((p - a).norm(), (p - b).norm());
	}

};

// check if a is conteined in polygon in O(log(n))
bool pol_contain(vector<point> &pol, point a){ // pol must be in clockwise order
	int r = pol.size() - 1, l = 1, meio;
	while (r - l > 1){
		meio = (r + l) / 2;
		if (segment(pol[0], pol[meio]).ccw(a) >= 0) r = meio;
		else l = meio;
	}
	if (r == l) return segment(pol[0], pol[r]).contains(a);
	else{
		coord a1 =	abs((pol[r] - pol[0]) ^ (pol[l] - pol[0]));
		coord a2 =	abs((pol[r] - a) ^ (pol[l] - a)) +
					abs((pol[l] - a) ^ (pol[0] - a)) +
					abs((pol[0] - a) ^ (pol[r] - a));
		return sign(a1 - a2) == 0;			
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, k;
	cin>>n>>m>>k;

	int x, y;
	vector<point> p;
	fr(i, n){
		cin>>x>>y;
		p.pb(point(x, y));
	}
	reverse(all(p));

	int ans = 0;

	fr(i, m){
		cin>>x>>y;
		ans += pol_contain(p, point(x, y));
	}

	if (ans >= k)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


}