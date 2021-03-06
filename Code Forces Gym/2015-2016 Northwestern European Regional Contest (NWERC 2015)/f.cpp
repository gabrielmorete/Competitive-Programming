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
 
int sign(coord x) {return (x > EPS) - (x < -EPS);}
 
struct point {
	coord x, y, z;
	point(): x(0), y(0), z(0) {} 
	point(coord _x, coord _y, coord _z): x(_x), y(_y), z(_z) {}
 
	inline point operator+(point p){ return {x + p.x, y + p.y, z + p.z}; }
	inline point operator-(point p){ return {x - p.x, y - p.y, z - p.z}; }
	inline point operator*(coord o){ return {x * o, y * o, z * o}; }
	inline point operator/(coord o){ return {x / o, y / o, z / o}; }
 
	inline coord operator*(point p){ return x * p.x + y * p.y + z * p.z;}
	inline point operator^(point p){ return {y * p.z - z * p.y, z * p.x - x * p.z ,x * p.y - p.x * y };}
 
	inline coord norm(){ return sqrt(x * x + y * y + z * z);}
 	inline coord norm2(){ return x * x + y * y + z * z; }

	inline bool operator==(point p){ return sign(x - p.x) == 0 and sign(y - p.y) == 0 and sign(z - p.z) == 0;}
	inline void operator=(point p){x = p.x; y = p.y; z = p.z;}
};

// transform polar (degree) coordnates to cartesian in a sphere of radius r
point deg_to_cart(coord r, coord tht, coord phi){
	tht *= 2.0 * pi / 360.0;
	phi *= 2.0 * pi / 360.0;
	return point(cos(tht) * cos(phi), cos(tht) * sin(phi), sin(tht)) * r;
}

// shortest distance in a sphere of radius r
coord dist_sph(coord r, point a, point b){
	return r * acos((a * b) / (a.norm() * b.norm())); // arc/raio = rad
}

// return true if p ins contained in the arc ab
bool contains(point p, point a, point b){
	return (sign((a ^ p) * (a ^ b)) > 0) and (sign((a ^ p) * (p ^ b)) > 0);
}

// get intersecon of arcs ab and cd in a sphere of radius r
point get_arc_intsec(coord r, point a, point b, point c, point d){
	point nrm1 = a ^ b;
	point nrm2 = c ^ d;
	point p = nrm1 ^ nrm2; // intersection of planes 

	if (sign(p.norm()) == 0)
		return {0, 0, 0};

	p = p * (r / p.norm());
	point pp = p * (-1.0);

	if (contains(p, a, b) and contains(p, c, d)) return p;
	if (contains(pp, a, b) and contains(pp, c, d)) return pp;
	return {0, 0, 0};
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int c, m, n;
	vector<point> cont[33], flgt;

	cin>>c;
	fr(i, c){
		coord tht, phi;
		cin>>n;
		fr(j, n){
			cin>>tht>>phi;
			cont[i].pb(deg_to_cart(6370, tht, phi));
		}
	}

	cin>>m;
	fr(i, m){
		coord tht, phi;
		cin>>tht>>phi;
		flgt.pb(deg_to_cart(6370, tht, phi));
	}

	coord tot_dist = 0;

	fr(i, m - 1)
		tot_dist += dist_sph(6370, flgt[i], flgt[i + 1]);

	coord water = 0;
	bool land = 1;	

	for (int i = 0; i < m - 1; i++){
		point a = flgt[i];
		point b = flgt[i + 1];

		vector<point> intsec;

		fr(j, c){
			int sz = cont[j].size();
			fr(k, sz - 1){
				point p = get_arc_intsec(6370, a, b, cont[j][k], cont[j][k + 1]);
				if (sign(p.norm()) > 0)
					intsec.pb(p);
			}
			point p = get_arc_intsec(6370, a, b, cont[j][sz - 1], cont[j][0]);
			if (sign(p.norm()) > 0)
				intsec.pb(p);
		}
		
		sort(all(intsec), [&](point pa, point pb){ // sort based on distance
			return(dist_sph(6370, a, pa) < dist_sph(6370, a, pb));});

		intsec.pb(b);

		coord dst;
		point now = a;
		for (point x : intsec){
			dst = dist_sph(6370, now, x);
			if (!land) water += dst;
			land = 1 - land;
			now = x;
		}
		land = 1 - land; // last flif did not cross


    }

	cout<<setprecision(10)<<fixed;
	cout<<tot_dist<<' '<<100.0 * water / tot_dist <<endl;
}