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

using coord = long long;
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
	//inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }

	inline bool operator==(point &p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }
//	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort
	inline bool operator<(point &p){ return sign(y - p.y) != 0 ? sign(y - p.y) < 0 : sign(x - p.x) < 0; } // lex_sort

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct comparator{
	point o;
	comparator(point _o): o(_o){}
	bool operator()(point a, point b){
		if (sign((a - o) ^ (b - o)) != 0)
			return sign((a - o) ^ (b - o)) > 0;
		return sign((a - o).norm2() - (b - o).norm2()) <= 0;
	}
};

// build convex hull in nlog(n), n > 1
vector<point> convex_hull(vector<point> v, int border_in){ // should border be in convex?
	swap(v[0], *min_element(all(v))); // lex_sort
	sort(v.begin() + 1, v.end(), comparator(v[0]));
	int sz = 2, s, nv = v.size();
	vector<point> hull = {v[0], v[1]};
	if (border_in){
		for (s = nv - 1; s > 1 and sign((v[s] - v[0]) ^ (v[s - 1] - v[0])) == 0; s--);
		reverse(v.begin() + s, v.end());	
	}

	for (int i = 2; i < nv; i++)
		if (sign((hull[sz - 1] - hull[sz - 2]) ^ (v[i] - hull[sz - 1])) >= 1 - border_in)
			hull.push_back(v[i]), sz++;
		else
			hull.pop_back(), i--, sz--;
	return hull;	
}

map<pii, int> m;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout<<setprecision(2)<<fixed;

	int n, t;
	int x, y, crd;

	vector<point> p;
	
	cin>>t;

	while (t--){
		p.clear();
		m.clear();
		crd = 1;


		cin>>n;

		fr(i, n){
			cin>>x>>y;
			p.pb(point(x, y));
			if (!m.count(make_pair(x, y)))
				m[make_pair(x, y)] = i + 1;

		}

		if (n == 1){
			cout<<0.00<<endl;
			cout<<1<<endl;
			if (t != 0)
				cout<<endl;
			continue;
		}

		vector<point> ans =	convex_hull(p, 0);	

		long double circ = 0;
		ans.pb(ans[0]);

		for (int i = 0; i < ans.size() - 1; i++)
			circ += (ans[i + 1] - ans[i]).norm();

		cout<<circ<<endl;

		for (int i = 0; i < ans.size() - 1; i++)
			cout<<m[{ans[i].x, ans[i].y}]<<' ';
		gnl;

		if (t != 0)
			cout<<endl;
	}	
}