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

int n, m, v[MAXN], sft[MAXN], to[MAXN];
bool vis[MAXN];


void solve(){
	cin>>n>>m;

	frr(i, n)
		cin>>v[i];

	fr(i, n)
		sft[i] = 0;

	frr(i, n){
		if (v[i] <= i)
			sft[i - v[i]]++;
		else	
			sft[i + (n - v[i])]++;
	}

	vi ans;

	for (int k = 0; k < n; k++){
		if ((n - sft[k]) > m * 2)
			continue;

		for (int j = 1; j <= n; j++){
			vis[j] = 0;
			to[j] = (v[j] + k);
			if (to[j] > n)
				to[j] -= n;
		}

		int cnt = 0;

		frr(i, n)
			if (!vis[i]){
				cnt++;
				int v = i;
				while (vis[v] == 0){
					vis[v] = 1;
					v = to[v];
				}
			}

		if (n - cnt <= m)
			ans.pb(k);	
	}	

	cout<<ans.size()<<' ';
	for (auto x : ans)
		cout<<x<<' ';
	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}