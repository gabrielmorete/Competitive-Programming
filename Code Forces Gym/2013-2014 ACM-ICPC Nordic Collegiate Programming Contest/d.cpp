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

using coord = long long int;

int sign(coord x) { return (x > 0) - (x < 0); }

struct point{
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	
	inline coord operator*(point p){ return x * p.x + y * p.y; }
	inline coord operator^(point p){ return x * p.y - y * p.x; }

	inline coord norm2(){return x * x + y * y; }

	inline bool operator<(point &p){ return sign(x - p.x) != 0 ? sign(x - p.x) < 0 : sign(y - p.y) < 0; }
	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0; }
};

void swap(point &a, point &b){ point aux = a; a = b; b = aux; }

struct comparator{
	point o;
	comparator(point _o) : o(_o){}

	bool operator()(point a, point b){
		if (sign((a - o)^(b - o)) != 0)
			return sign((a - o)^(b - o)) > 0;
		return sign((a - o).norm2() - (b - o).norm2()) < 0;
	}
};

vector<point> convex_hull(vector<point> v, int border_in){
	swap(v[0], *min_element(all(v)));
	sort(v.begin() + 1, v.end(), comparator(v[0]));
	int sz = 2, s, nv = v.size();
	
	if (border_in){
		for (s = nv - 1; s > 1 and sign((v[s] - v[0]) ^ (v[s - 1] - v[0])) == 0; s--);
		reverse(v.begin() + s, v.end());	
	}
	
	vector<point> hull = {v[0], v[1]};
	
	for (int i = 2; i < nv; i++){
		if (sz < 2)
			hull.push_back(v[i]), sz++;
		else if (sign((hull[sz - 1] - hull[sz - 2]) ^ (v[i] - hull[sz - 1])) >= 1 - border_in)
			hull.push_back(v[i]), sz++;
		else
			hull.pop_back(), i--, sz--;
	}

	return hull;	
}

double diameter(vector<point> v){
	if (v.size() == 2){
		return sqrt((v[0] - v[1]).norm2());
	}

	int l, r, p = 2, nv = v.size();
	coord mxdst = 0;

	for (int i = 0; i < nv; i++){
		l = i, r = (i + 1) % nv;
		point lr = v[r] - v[l]; 
		while (sign(abs((v[(p + 1) % nv] - v[l]) ^ lr) - abs((v[p] - v[l]) ^ lr)) >= 0) 
			p = (p + 1) % nv;
		if (sign((v[l] - v[p]).norm2() - mxdst) > 0)
			mxdst = (v[l] - v[p]).norm2();
		if (sign((v[r] - v[p]).norm2() - mxdst) > 0)
			mxdst = (v[r] - v[p]).norm2();
	}

	return sqrt(mxdst);
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	vector<point> v;

	fr(i, n){
		int x, y;
		cin>>x>>y;

		v.pb(point(x, y));
	}

	vector<point> hull = convex_hull(v, 0);

	assert(hull.size() > 1);


	cout<<setprecision(12)<<fixed;
	cout<<diameter(hull)<<endl;
}