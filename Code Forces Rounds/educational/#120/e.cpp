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

ll n, m, esp[15], frq[MAXN];
string s[15];

ll vans, ans[MAXN], vaux, aux[MAXN];

void test(int msk){
	fr(i, m)
		frq[i] = 0;

	vaux = 0;	
	fr(i, n){
		int x = -1;
		if (msk & (1<<i))
			x = 1;

		vaux -= x * esp[i];  // if 1, subtract

		fr(j, m)
			frq[j] += (int)(s[i][j] - '0') * x;
	}

	priority_queue<pii> pq;

	fr(j, m)
		pq.push({frq[j], j});

	ll cnt = m;
	
	while (!pq.empty()){
		ll f, pos;
		tie(f, pos) = pq.top();
		pq.pop();

		aux[pos] = cnt;
		vaux += f * cnt;
		cnt--;
	}	

	if (vaux > vans){
		vans = vaux;
		fr(j, m)
			ans[j] = aux[j];
	}

}

void solve(){
	cin>>n>>m;
	fr(i, n)
		cin>>esp[i];

	fr(i, n)
		cin>>s[i];	

	vans = -llINF;
	for (int msk = 0; msk < (1<<n); msk++)
		test(msk);	

	fr(i, m)
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