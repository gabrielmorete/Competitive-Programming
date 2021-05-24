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

using coord = __int128;
const long double pi = acos(-1);

int sign(coord x) { return (x > 0) - (x < 0); }
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

	inline coord norm2(){ return x * x + y * y; }

};

int n;
vector<point> v;

vi id;

int get_quad(point a){
	if (a.y > 0) return 0;
	if (a.y < 0) return 1;
	if (a.x > 0) return 0;
	return 1;
}

bool cmp(int l, int r){ // l < r ?
	point a = v[l];
	point b = v[r];

	if (get_quad(a) == get_quad(b))
		return sign(a^b) > 0; // a < b
	return get_quad(a) < get_quad(b);
}

typedef pair<coord, coord> frac;

bool cmpf(frac a, frac b){
	return a.fst * b.snd < b.fst*a.snd;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	int x, y;
	fr(i, n){
		cin>>x>>y;
		id.pb(i);
		v.pb(point(x, y));
	}

	sort(all(id), cmp);

	frac bst = {-2, 1};
	int ansa = -1, ansb = -1;

	fr(i, n){ // tht <= 90
		frac f = {sq(v[id[i]] * v[id[(i + 1) % n]]), v[id[i]].norm2() * v[id[(i + 1)%n]].norm2()};
		if (sign(v[id[i]] * v[id[(i + 1) % n]]) >= 0 and cmpf(bst, f)){ // careful with sqared value
			bst = f;
			ansa = id[i] + 1;
			ansb = id[(i + 1)%n] + 1;
		}
	}

	if (ansa == -1){ // tht > 90
		frac bst = {2, 1};
		fr(i, n){
			frac f = {sq(v[id[i]] * v[id[(i + 1) % n]]), v[id[i]].norm2() * v[id[(i + 1)%n]].norm2()};
			if (cmpf(f, bst)){
				bst = f;
				ansa = id[i] + 1;
				ansb = id[(i + 1)%n] + 1;
			}
		}
	}

	cout<<ansa<<' '<<ansb<<endl;
}