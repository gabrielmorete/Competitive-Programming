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

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

point unity(coord tht){
	return point(cos(tht), sin(tht));
}

int n, sz[1123];
vi adj[1123];

void dfs_sz(int v, int p){
	sz[v] = 1;

	for (auto x : adj[v])
		if (x != p){
			dfs_sz(x, v);
			sz[v] += sz[x];
		}
}

point pos[1123];

void dfs(int v, int p, coord l, coord r){
	int tam = sz[v] - 1;

	coord lb = l, stp = (r - l)/((coord) tam);

	for (auto x : adj[v]){
		if (x != p){
			coord add = stp * sz[x];


			pos[x] = pos[v] + unity((2*lb + add)/2);
			dfs(x, v, lb, lb + add);
			lb += add;
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int a, b;
	fr(i, n - 1){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs_sz(1, 1);
	
	pos[1] = point(0, 0);
	dfs(1, 1, 0, 2 * pi);

	cout<<setprecision(9)<<fixed;
	frr(i, n)
		cout<<pos[i].x<<' '<<pos[i].y<<endl;
}