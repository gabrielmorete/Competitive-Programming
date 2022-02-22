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

int n, p[MAXN], ans[MAXN];
string s;

void solve(){
	cin>>n;

	fr(i, n)
		cin>>p[i];

	cin>>s;
	
	vii v;

	int cnt = 1;
	fr(i, n)
		if (s[i] == '0')
			v.pb({p[i], i});

	sort(all(v));
	
	for (auto x : v)
		ans[x.snd] = cnt++;

	v.clear();		
	
	fr(i, n)
		if (s[i] == '1')
			v.pb({p[i], i});

	sort(all(v));
	
	for (auto x : v)
		ans[x.snd] = cnt++;

	fr(i, n)
		cout<<ans[i]<<' ';

	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}