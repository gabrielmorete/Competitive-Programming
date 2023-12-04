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

int n, q;
string s;

map<pii, int> early, late, hsh;

pii getmove(char c){
	if (c == 'U')
		return make_pair(0, 1);
	
	if (c == 'D')
		return make_pair(0, -1);

	if (c == 'L')
		return make_pair(-1, 0);

	return make_pair(1, 0);
}

int sumx[MAXN], sumy[MAXN];
int px[MAXN], py[MAXN];
vi pos[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n>>q;
	cin>>s;


	int cnt = 0;
	early[{0, 0}] = 0;
	for (auto x : s){
		auto d = getmove(x);
		cnt++;

		px[cnt] = px[cnt - 1] + d.first;
		py[cnt] = py[cnt - 1] + d.second;

		if (early.count({px[cnt], py[cnt]}))
			late[{px[cnt], py[cnt]}] = cnt;
		else
			early[{px[cnt], py[cnt]}] = cnt;
	}

	sumx[n + 1] = sumy[n + 1] = 0;

	int id = 0;
	for (int i = n; i > 0; i--){
		auto d = getmove(s[i - 1]);

		sumx[i] = sumx[i + 1] + d.first;
		sumy[i] = sumy[i + 1] + d.second;
		if (!hsh.count({sumx[i], sumy[i]}))
			hsh[{sumx[i], sumy[i]}] = id++;

		pos[hsh[{sumx[i], sumy[i]}]].pb(i);
	}

	// fr(i, n + 1)
	// 	cout << px[i] << ' ' << py[i] << endl;

	// chapa;	

	// fr(i, n + 1)
	// 	cout << sumx[i] << ' ' << sumy[i] << endl;

	fr(i, id)
		sort(all(pos[i]));


	while (q--){
		int x, y, l, r;
		int dx, dy, qx, qy;

		cin>>x>>y>>l>>r;
		bool ok = 0;
		// try outside l, r
		if (early.count({x, y})){
			if (early[{x, y}] < l or early[{x, y}] > r){
				ok = 1;
			}
		}

		if (late.count({x, y})){
			if (late[{x, y}] < l or late[{x, y}] > r){
				ok = 1;
			}
		}

		// ned to see inside l r
		dx = x - px[l - 1]; 
		dy = y - py[l - 1];

		qx = dx + sumx[r + 1];
		qy = dy + sumy[r + 1];

		// dbg(x);
		// dbg(y);
		// dbg(qx);
		// dbg(qy);

		if (hsh.count({qx, qy})){
			id = hsh[{qx, qy}];
			// chapa;

			int h = (int)(lower_bound(all(pos[id]), l) - pos[id].begin());
			if (h < (int)pos[id].size() and pos[id][h] <= r){
				ok = 1;
			}
		}

		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}