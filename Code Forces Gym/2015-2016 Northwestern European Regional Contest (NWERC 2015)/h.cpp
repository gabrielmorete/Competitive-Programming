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

struct line {
	point p; coord c; //p * <x,y> = c
	line() {} line(point _p, coord _c): p(_p), c(_c) {}
	line(point a, point b) : p((b - a).rot90()), c(p * a) {}
	line get_parall(point v){ return line(p, p * v); }// parallel line at point v
	line get_perp(){ return line(p.rot90(), c); }// perpendicular line

	bool contains(point v){ return sign(p * v - c) == 0; }
	bool intsec(line l){ return sign(p ^ l.p) != 0; } // false if is the same line

	coord dist(point v){ return abs(p * v - c) / p.norm(); }

	point get_intsec(line l){ coord d = p^l.p; return point((c*l.p.y - l.c*p.y)/d, (p.x*l.c - c*l.p.x)/d); }
};

struct segment {
	point a, b; // a != b
	segment() {} segment(point _a, point _b): a(_a), b(_b) {}

	bool contains(point p){ return sign((p-a)^(b-a)) == 0 and sign((p-a)*(b-a)) >= 0 and sign((p-b)*(a-b)) >= 0; }
	
	int ccw(point p){ return((b - a).ccw(p)); } // ccw  -1 left, 0 over, 1 right  of seg a->b

	bool intsec(segment q){ segment p = *this;
		if (p.contains(q.a) or p.contains(q.b) or q.contains(p.a) or q.contains(p.b))
			return true;
		return p.ccw(q.a-p.a)*p.ccw(q.b-p.a) == -1 and q.ccw(p.a-q.a)*q.ccw(p.b-q.a) == -1;	
	}
	
	coord len2(){ return (a - b).norm2(); }

	coord dist(segment q){segment p = *this; 
		return p.intsec(q)? 0 : min({p.dist(q.a), p.dist(q.b), q.dist(p.a), q.dist(p.b)});	}

	coord dist(point p){
		if (sign(((p - a) * (b - a))) >= 0 and sign((p - b) * (a - b)) >= 0)
			return abs((p - a) ^ (b - a)) / (b - a).norm();
		return min((p - a).norm(), (p - b).norm());
	}

	line getline(){return line(a, b); }
};

int n;
point hole;
vector<segment> bar;

point reflect(segment s, point p){
	point a = s.a;
	point b = s.b;

	if (a.x == b.x){
		coord dlt = p.x - a.x;
		return point(p.x - 2 * dlt, p.y);
	}
	coord dlt = p.y - a.y;
	return point(p.x, p.y - 2 * dlt);
}

bool check(vi pi){
	int m = pi.size();

	vector<point> t(m + 1);
	t[m] = hole;

	for (int i = m - 1; i >= 0; i--)
		t[i] = reflect(bar[pi[i]], t[i + 1]);
	
	point now = {0, 0};
	vector<bool> rem(n, 1);

	for (int i = 0; i < m; i++){
		if (sign((t[i]-now).norm()) == 0)
			return false;
		
		int idx = -1;
		coord min_dist = llINF;

		for (int j = 0; j < n; j++)
			if (rem[j]){
				if (bar[j].intsec(segment(now, t[i]))){
					if (min_dist > bar[j].dist(now)){
						min_dist = bar[j].dist(now);
						idx = j;
					}
				}
			}

		if (idx != pi[i])		
			return false;

		rem[pi[i]] = false;

		line l1 = bar[pi[i]].getline();
		line l2 = line(now, t[i]);

		now = l1.get_intsec(l2);
	}
	
	for (int j = 0; j < n; j++)
		if (rem[j])
			if (bar[j].intsec(segment(now, hole)))
				return false;
	return true;
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c, d;

	cin>>n;
	cin>>a>>b;
	hole = {a, b};

	fr(i, n){
		cin>>a>>b>>c>>d;
		bar.pb(segment(point(a, b), point(c, d)));
	}

	vector<int> perm;
	fr(i, n)
		perm.pb(i);

	int ans = -1;
	if (check(vector<int>({})))
		ans = 0;	

	do{
		vector<int> idx;
		fr(i, n){
			idx.pb(perm[i]);
			if (ans < i + 1 and check(idx))
				ans = i + 1;	
		}
	} while (next_permutation(all(perm)));

	if (ans == -1)
		cout<<"impossible"<<endl;
	else
		cout<<ans<<endl;
}