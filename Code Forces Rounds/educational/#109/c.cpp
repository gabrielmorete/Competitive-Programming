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
const int MAXN = 3e5 + 10;

int n, m, dir[MAXN], a[MAXN], id[MAXN], ans[MAXN];

vi v;

void execute(){
	stack<pii> stk;
	for (int i = 0; i < v.size(); i++){
		if (dir[v[i]] == 1)
			stk.push({a[v[i]], v[i]});
		else{
			if (stk.empty())
				stk.push({-a[v[i]], v[i]});
			else{
				int d, u;
				tie(d, u) = stk.top();
				stk.pop();

				int t = (a[v[i]] - d)/2;
				ans[v[i]] = ans[u] = t;
			}
		}
	}

	while (stk.size() > 1){
		int d1, u1;
		tie(d1, u1) = stk.top();
		stk.pop();

		int d2, u2;
		tie(d2, u2) = stk.top();
		stk.pop();


		d2 = m + (m - d2);

		int t = (d2 - d1)/2;
		ans[u1] = ans[u2] = t;
	}
}


void solve(){
	cin>>n>>m;
	fr(i, n)
		cin>>a[i];

	string s;
	fr(i, n){
		cin>>s;
		if (s == "L")
			dir[i] = -1;
		else
			dir[i] = 1;
	}	

	fr(i, n)
		id[i] = i;

	sort(id, id + n, [](int x, int y){return a[x] < a[y];}); // ordena os indices

	fr(i, n)
		ans[i] = -1;

	v.clear();
	fr(i, n)
		if (a[id[i]] % 2)
			v.pb(id[i]);
	execute();
	
	v.clear();
	fr(i, n)
		if (a[id[i]] % 2 == 0)
			v.pb(id[i]);
	execute();

	fr(i, n)
		cout<<ans[i]<<' ';
	gnl;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}