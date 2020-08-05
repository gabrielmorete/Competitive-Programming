#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair


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
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

typedef tuple<ll,ll,ll> tup;

vector<tup> tg;
ll fst[11234];
ll n, r, x;
int main(){
	fastio;
	ms(fst, -1);

	cin>>n;

	frr(i,n){
		cin>>x>>r;
		tg.pb({x, r, i});
	}


	ll ans = 0;
	vll bs;
	sort(all(tg));

	for(auto x : tg)
		bs.pb(get<0>(x));

	ll m, a, b, ind;

	cin>>m;
	frr(i,m){
		cin>>a>>b;
		auto it = lower_bound(all(bs), a);
		
		if (it == bs.begin()){
			x = get<0>(tg[0]);
			r = get<1>(tg[0]);
			ind = get<2>(tg[0]);
			if ((a - x)*(a - x) + b*b <= r*r){
				ans++;
				if (fst[ind] == -1)
					fst[ind] = i;
			}
		}
		else if (it == bs.end()){
			x = get<0>(tg[n - 1]);
			r = get<1>(tg[n - 1]);
			ind = get<2>(tg[n - 1]);
			if ((a - x)*(a - x) + b*b <= r*r){
				ans++;
				if (fst[ind] == -1)
					fst[ind] = i;
			}
		}
		else{
			bool ok = 0;
			int p = (int) (it - bs.begin());
			x = get<0>(tg[p - 1]);
			r = get<1>(tg[p - 1]);
			ind = get<2>(tg[p - 1]);
			if ((a - x)*(a - x) + b*b <= r*r){
				ans++;
				ok = 1;
				if (fst[ind] == -1)
					fst[ind] = i;
			}
			x = get<0>(tg[p]);
			r = get<1>(tg[p]);
			ind = get<2>(tg[p]);
			if ((a - x)*(a - x) + b*b <= r*r){
				ans++;
				if (fst[ind] == -1)
					fst[ind] = i;
			}
		}
	}

	ans = 0;
	frr(i,n)
		if(fst[i] != -1)
			ans++;
	cout<<ans<<endl;
	frr(i,n)
		cout<<fst[i]<<' ';
	gnl;	

}