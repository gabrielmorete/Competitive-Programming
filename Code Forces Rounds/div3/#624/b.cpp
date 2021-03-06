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
const int MAXN = 1e5 + 10;
const ll mod=1e9+7;

int n, m, pos[110];
vii v;

void solve(){
	v.clear();
	ms(pos, 0);

	cin>>n>>m;
	int x;		

	frr(i, n){
		cin>>x;
		v.pb({x, i});
	}

	frr(i, m){
		cin>>x;
		pos[x]++;
	}


	stable_sort(all(v));
	frr(i, n)
		pos[i] += pos[i - 1];

	bool ok = 1;	

	int p;	
	frr(i, n){
		p = v[i - 1].snd;
		if (i > p and pos[i - 1] - pos[p - 1] < i - p){
			ok = 0;
		}
		else if (i < p and pos[p - 1] - pos[i - 1] < p - i)
			ok = 0;

	}	
	
	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}