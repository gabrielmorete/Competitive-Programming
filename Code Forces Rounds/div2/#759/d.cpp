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
const int MAXN = 5e5 + 10;


int to[MAXN], frq[MAXN], vis[MAXN];

void solve(){
	int n;
	cin>>n;

	fr(i, n + 10)
		frq[i] = 0;

	vii v;

	fr(i, n){
		int x;
		cin>>x;

		frq[x]++;
		
		v.pb({x, i});
	}

	bool ok = 1;
	fr(i, n - 1)
		if (v[i] > v[i + 1])
			ok = 0;

	frr(i, n)
		if (frq[i] > 1)
			ok = 1;	

	if (ok){
		cout<<"YES"<<endl;
		return;
	}	

	if (n < 3){
		cout<<"NO"<<endl;
		return;
	}


	fr(i, n)
		to[i] = frq[i] = vis[i] = 0;

	sort(all(v));	

	fr(i, n)
		to[v[i].snd] = i;


	int ev = 0, od = 0;	

	fr(i, n)
		if (!vis[i]){
			int cnt = 0;
			int x = i;
			while (!vis[x]){
				cnt++;
				vis[x] = 1;
				x = to[x];
			}

			if (cnt&1)
				od++;
			else
				ev++;
		}	

	if (ev & 1)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}