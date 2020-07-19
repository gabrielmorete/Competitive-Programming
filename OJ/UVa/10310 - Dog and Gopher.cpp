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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

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

int signal(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point& o){ return {x + o.x, y + o.y}; }
	inline point operator-(point& o){ return {x - o.x, y - o.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(const point& o){ x = o.x, y = o.y; }
	inline bool operator==(point& o){return signal(x - o.x) == 0 and signal(y - o.y) == 0; }
	inline coord norm(){ return sqrt(x * x + y * y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){return {-y, x}; }
	inline point rot(long double ang){ return {cos(ang) * x - sin(ang) * y, sin(ang) * x + cos(ang) * y}; }

	void print(){ cout<<x<<' '<<y<<'\n'; }
};

int32_t main(){
	fastio;

	int n;
	coord a, b, c, d;
	while (cin>>n>>a>>b>>c>>d){
		point gf = point(a, b);
		point dg = point(c, d);
		point ans = point(1, 1), aux = point(1, 1);
		bool ok = 0;
		coord x, y;

		while (n--){
			cin>>x>>y;
			aux = point(x, y);
			if (4 * (gf - aux).norm2() <= (dg - aux).norm2() and !ok){
				ans = aux;
				ok = 1;
			}
		}

		cout<<setprecision(3)<<fixed;

		if (!ok)
			cout<<"The gopher cannot escape."<<endl;
		else
			cout<<"The gopher can escape through the hole at ("<<ans.x<<","<<ans.y<<")."<<endl;
	}
}