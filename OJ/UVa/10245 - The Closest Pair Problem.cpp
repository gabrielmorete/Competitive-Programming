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
	inline bool operator==(point p){return sign(x - p.x) == 0 and sign(y - p.y) == 0; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(tht)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){return {-y, x}; }
	inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }
	inline point project(point p){return p * (((*this) * p)/p.norm2()); }

	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; } // lex_sort

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};


struct comp_y{
	bool operator()(point a, point b){ return a.y < b.y; }
};

// Return the minimun squared distance between two points
coord closest_pair(vector<point> &v, vector<point> &t, int l, int r, int srt = 0){
	if (l + 1 >= r) return 1e18; // [l, r)
	if (!srt) sort(v.begin(), v.end()); //lex_compare	
	int meio = (l + r)/2;
	coord x = v[meio].x;

	coord h = min(closest_pair(v, t, l, meio, 1), closest_pair(v, t, meio, r, 1));
	
	merge(v.begin() + l, v.begin() + meio, v.begin() + meio, v.begin() + r, t.begin(), comp_y());
	copy(t.begin(), t.begin() + r - l, v.begin() + l);

	int tsz = 0;
	for (int i = l; i < r; i++)
		if (sign(sq(v[i].x - x) - h) <= 0){
			for (int j = tsz - 1; j >= 0 and sign(sq(v[i].y - t[j].y) - h) <= 0; j--)
				h = min(h, (v[i] - t[j]).norm2());
			t[tsz++] = v[i];
		}
	return h;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	coord x, y;

	vector<point> p;

	cout<<setprecision(4)<<fixed;
	

	cin>>n;
	while (n != 0){
		p.clear();
		fr(i, n){
			cin>>x>>y;
			p.pb(point(x, y));
		}

		vector<point> aux(n);

		coord ans = sqrt(closest_pair(p, aux, 0, n));	

		if (ans < 10000)
			cout<<ans<<endl;
		else
			cout<<"INFINITY"<<endl;	
		cin>>n;
	}
}	