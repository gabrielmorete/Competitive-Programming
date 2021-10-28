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
const int MAXN = 2e5 + 10;

int n, vx[MAXN], vy[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	fr(i, n)
		cin>>vx[i]>>vy[i];

	vii vv;
	fr(i, n)
		vv.pb({vx[i], i});

	sort(all(vv));

	set<pii> q;

	q.insert({min(vv[0].snd, vv[n - 1].snd), max(vv[0].snd, vv[n - 1].snd)});
	q.insert({min(vv[0].snd, vv[n - 2].snd), max(vv[0].snd, vv[n - 2].snd)});
	q.insert({min(vv[1].snd, vv[n - 1].snd), max(vv[1].snd, vv[n - 1].snd)});
	q.insert({min(vv[1].snd, vv[n - 2].snd), max(vv[1].snd, vv[n - 2].snd)});

	vv.clear();
	fr(i, n)
		vv.pb({vy[i], i});

	sort(all(vv));

	q.insert({min(vv[0].snd, vv[n - 1].snd), max(vv[0].snd, vv[n - 1].snd)});
	q.insert({min(vv[0].snd, vv[n - 2].snd), max(vv[0].snd, vv[n - 2].snd)});
	q.insert({min(vv[1].snd, vv[n - 1].snd), max(vv[1].snd, vv[n - 1].snd)});
	q.insert({min(vv[1].snd, vv[n - 2].snd), max(vv[1].snd, vv[n - 2].snd)});

	vi ans;
	while (!q.empty()){
		int a, b;
		tie(a, b) = *q.begin();
		q.erase(q.begin());
		if (a != b)
			ans.pb(max(abs(vx[a] - vx[b]), abs(vy[a] - vy[b])));
	}

	sort(all(ans));
	ans.pop_back();

	cout<<ans.back()<<endl;
}