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
const int MAXN = 5e3 + 10;

// Basic structures and operations for geometry
using namespace std;

using coord = long double;
const long double pi = acos(-1);
const long double EPS = 1e-12;

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

struct circle{
	point c; coord r;
	circle() {} circle(point _c, coord _r): c(_c), r(_r) {}
	
	bool intsec(circle b){ // circunference
		return ((sign((c - b.c).norm() - (r + b.r)) <= 0) and 
		(sign((c - b.c).norm() - fabs(r - b.r)) >= 0)); }
	
	vector<point> get_intsec(circle o){
		if ((*this).intsec(o) == 0) return {};
		long double d2 = (c - o.c).norm2();
		long double tht = acos((r*r + d2 - o.r*o.r) / sqrt(4.0*r*r*d2));
		point vec = ((o.c - c)/(o.c - c).norm()) * r;
		return {c + vec.rot(tht),c + vec.rot(-tht)};
	}

};	

int id[MAXN], sz[MAXN];
void init(){
	fr(i, MAXN){
		id[i] = i;
		sz[i] = 1;
	}
}

int find(int a){
	if (id[a] == a)
		return a;
	return id[a] = find(id[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return;
	if (sz[b] > sz[a])
		swap(a, b);
	id[b] = a;
	sz[a] += sz[b];
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;

	cin>>n;

	vector<point> v;

	double x, y;
	fr(i, n){
		cin>>x>>y;
		v.pb(point(x, y)); // gera vector de pontos
	}

	init(); // dsu

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) // norm() = || v || e norm2() = || v ||^2
			if (sign((v[i] - v[j]).norm2() - 4) <= 0) // distancia <= 2
				merge(i, j);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, sz[find(i)] + 1); // conjunto sozinho

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++){
			
			if (sign((v[i] - v[j]).norm2() - 16) > 0) // não podem ser borda, dist > 4
				continue;// na verdade esse if é desnecessário pois a função retorna 
						 // um vector vazio se não tem intersecção
			vector<point> center;
			if (sign((v[i] - v[j]).norm2() - 4) == 0){ // uma solução, dist == 4
				point p = v[j] + (v[i] - v[j])/(v[i] - v[j]).norm();
				center.pb(p);
			}
			else{
				circle c1 = circle(v[i], 2);
				circle c2 = circle(v[j], 2);

				center = c1.get_intsec(c2); // pega intersecção
			}
			for (auto p : center){
				set<int> q;
				for (int k = 0; k < n; k++)
					if (sign((p - v[k]).norm2() - 4) <= 0) // contido no circulo
						q.insert(find(k));

				int aux = 1;
				while (!q.empty()){
					aux += sz[*q.begin()];
					q.erase(q.begin());
				}	
				ans = max(ans, aux);
			}
		}

	cout<<ans<<endl;	
}