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
const int MAXN = 1e5 + 10;


ll tme[MAXN], pos[MAXN];

void solve(){
	int n;

	cin>>n;

	fr(i, n)
		cin>>tme[i]>>pos[i];
	
	tme[n] = llINF;		

	ll t, p, nxtp, a, b;	

	t = p = 0;

	bool free = 1;
	int ans = 0;

	for (int i = 0; i < n; i++){
		a = tme[i];
		b = pos[i];

		if (!free){
			ll dlt = tme[i] - t;
			if (abs(nxtp - p) <= dlt){
				p = nxtp;
				free = 1;
			}
			else{
				if (nxtp < p)
					p -= dlt;
				else
					p += dlt;
			}

			t = tme[i];
		}

		if (free){
			free = 0;
			t = tme[i];
			nxtp = pos[i];
		}
		
		ll dlt = tme[i + 1] - tme[i];
		if (nxtp <= pos[i] and pos[i] <= p and p - dlt <= pos[i])
			ans++;
		else if (nxtp >= pos[i] and pos[i] >= p and p + dlt >= pos[i])
			ans++;
			
	}

	cout<<ans<<endl;	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;

	cin>>T;
	while (T--)
		solve();
}