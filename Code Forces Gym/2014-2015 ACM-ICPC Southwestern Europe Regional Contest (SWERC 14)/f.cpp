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


int n, id[MAXN], sz[MAXN], area[MAXN];

int find(int a){
	return id[a] = (id[a] == a? a : find(id[a]));
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b)
		return;

	if (sz[a] < sz[b])
		swap(a, b);

	id[b] = a;
	sz[a] += sz[b];
	area[a] += area[b];
}

map<int, vector<array<int, 3>>> xbeg, xend, ybeg, yend;	

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	fr(i, n){
		int x, y, w, h;
		cin>>x>>y>>w>>h;

		xbeg[x].pb({y, y + h, i});
		xend[x + w].pb({y, y + h, i});

		ybeg[y].pb({x, x + w, i});
		yend[y + h].pb({x, x + w, i});

		id[i] = i;
		sz[i] = 1;
		area[i] = h * w;
	}

	for (auto e : xbeg)
		if (xend.count(e.fst)){

			vector<array<int, 3>> lft = e.snd;
			vector<array<int, 3>> rgt = xend[e.fst];

			sort(all(lft)); reverse(all(lft));
			sort(all(rgt)); reverse(all(rgt));

			while (!lft.empty() and !rgt.empty()){
				int lx = lft.back()[0], ly = lft.back()[1];
				int rx = rgt.back()[0], ry = rgt.back()[1];

				if (lx <= rx and rx <= ly)
					merge(lft.back()[2], rgt.back()[2]);
				
				if (rx <= lx and lx <= ry)
					merge(lft.back()[2], rgt.back()[2]);

				if (ly >= ry)
					rgt.pop_back();
				else
					lft.pop_back();
			}
		}

	for (auto e : ybeg)
		if (yend.count(e.fst)){

			vector<array<int, 3>> lft = e.snd;
			vector<array<int, 3>> rgt = yend[e.fst];

			sort(all(lft)); reverse(all(lft));
			sort(all(rgt)); reverse(all(rgt));

			while (!lft.empty() and !rgt.empty()){
				int lx = lft.back()[0], ly = lft.back()[1];
				int rx = rgt.back()[0], ry = rgt.back()[1];

				if (lx <= rx and rx <= ly)
					merge(lft.back()[2], rgt.back()[2]);
				
				if (rx <= lx and lx <= ry)
					merge(lft.back()[2], rgt.back()[2]);

				if (ly >= ry)
					rgt.pop_back();
				else
					lft.pop_back();
			}
		}	

	int ans = 0;
	fr(i, n)
		ans = max(ans, area[find(i)]);	

	cout<<ans<<endl;
}