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
	inline point operator+(point& p){ return {x + p.x, y + p.y}; }
	inline point operator-(point& p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point p){ x = p.x, y = p.y; }
	inline bool operator==(point& p){return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(thta)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(thta)

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  -1 left, 0 over, 1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){return {-y, x}; }
	inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct segment {
	point a, b; // a != b
	segment() {} segment(point _a, point _b): a(_a), b(_b) {}

	bool contains(point p){ return sign((p-a)^(b-a)) == 0 and sign((p-a)*(b-a)) >= 0 and sign((p-b)*(a-b)) >= 0; }
	bool intsec(segment q){ segment p = *this;
		if (p.contains(q.a) or p.contains(q.b) or q.contains(p.a) or q.contains(p.b))
			return true;
		return p.ccw(q.a-p.a)*p.ccw(q.b-p.a) == -1 and q.ccw(p.a-q.a)*q.ccw(p.b-q.a) == -1;	
	}

	int ccw(point p){ return((b - a).ccw(p)); } // ccw  -1 left, 0 over, 1 right  of seg a->b

	coord len2(){ return (a - b).norm2(); }
	coord dist(segment q){segment p = *this; 
		return p.intsec(q)? 0 : min({p.dist(q.a), p.dist(q.b), q.dist(p.a), q.dist(p.b)});	}
	coord dist(point p){
		if (sign(((p - a) * (b - a))) >= 0 and sign((p - b) * (a - b)) >= 0)
			return abs((p - a) ^ (b - a)) / (b - a).norm();
		return min((p - a).norm(), (p - b).norm());
	}

};

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout<<setprecision(4)<<fixed;

	int n;
	long double x, y, dist, aux; 
	while (cin>>x>>y){
		point a = point(x, y);
		point ans = a;
		dist = llINF;
		
		cin>>n;

		cin>>x>>y;
		point b = point(x, y);

		while (n--){
			cin>>x>>y;
			point c = point(x, y);
			segment bc = segment(b, c);

			aux = bc.dist(a);

			if (sign(aux - dist) < 0){ // novo minimo
				dist = aux;
				if (sign((a - b).norm() - dist) == 0)
					ans = b;
				else if (sign((a - c).norm() - dist) == 0)
					ans = c;
				else {// ponto no meio, projeta
					point dbc = c - b;
					point dba = a - b;
					ans = dba.project(dbc); // vetor de b até o ponto mais proximo no segmneto
					ans = ans + b; // interseção obtida pela projeção
				}
			}	
			b = c;
		}
		cout<<ans.x<<endl<<ans.y<<endl;
	}
}