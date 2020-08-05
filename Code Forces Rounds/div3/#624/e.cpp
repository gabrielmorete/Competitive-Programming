#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e4 + 10;
const ll mod=1e9+7;

int h[MAXN], bad[MAXN], chd[MAXN], pai[MAXN];


void solve(){
	int n, d;
	cin>>n>>d;

	int ub, lb, cnt, pwr;

	ub = (n*(n - 1))/2;

	lb = 0, cnt = n - 1, pwr = 1;
	while (cnt > 0){
		lb += pwr * min(1<<pwr, cnt);
		cnt -= 1<<pwr;
		pwr++;
	}

	if (!(lb <= d and d <= ub)){
		cout<<"NO"<<endl;
		return;
	}

	frr(i, n)
		h[i] = i - 1, pai[i] = i - 1, bad[i] = 0, chd[i] = 1;

	pai[1] = 1;	
	chd[n] = 0;

	while (ub > d){
		int v = -1;
		for (int i = 1; i <= n; i++){
			if (!bad[i] and chd[i] == 0 and (v == -1 or h[v] > h[i]))
				v = i;
		}

		int p = -1;
		for (int i = 1; i <= n; i++)
			if (chd[i] < 2 and h[i] < h[v] - 1 and (p == -1 or h[p] < h[i]))
				p = i;

		if (p == -1){
			bad[v] = 1;
			continue;
		}

		chd[pai[v]]--;
		h[v]--;
		pai[v] = p;
		chd[p]++;
		ub--;
	}
	cout<<"YES"<<endl;
	for (int i = 2; i <= n; i++)
		cout<<pai[i]<<' ';
	gnl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}