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

using coord = long long int;

struct point {
	coord x, y, z;
	point() : x(0), y(0), z(0) {} point(coord _x, coord _y, coord _z): x(_x), y(_y), z(_z) {}
	inline point operator+(point& p){ return {x + p.x, y + p.y, z + p.z}; }
	inline point operator-(point& p){ return {x - p.x, y - p.y, z - p.z}; }
	
	inline coord operator*(point p){ return x * p.x + y * p.y + z * p.z; } // |a||b|cos(thta)
	inline point operator^(point p){ 
		return point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x); 
	} 

	inline coord norm(){return (*this) * (*this);}	

	inline void print(){ cout<<x<<' '<<y<<' '<<z<<'\n'; }
};

void solve(){
	int n;
	cin>>n;

	vector<point> v;

	int x, y, z;
	fr(i, n){
		cin>>x>>y>>z;
		v.pb(point(x, y, z));
	}

	bool ok = 0;
	int ans = 3, aux;
	
	fr(i, n)
	fr(j, n)
	fr(k, n){
		if(((v[j] - v[i])^(v[k] - v[i])).norm() != 0){ // checa se formam plano
		ok = 1;
		aux = 0;
		fr(l, n)
			if (((v[l] - v[i])*((v[j] - v[i]) ^ (v[k] - v[i]))) == 0) // projeção no vetor perpendicular ao plano
				aux++;
		ans = max(ans, aux);	
		}
	}

	if (ok)
		cout<<ans<<endl;
	else
		cout<<n<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}