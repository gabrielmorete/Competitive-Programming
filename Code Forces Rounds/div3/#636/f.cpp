#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
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
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n;
vector< set<int> > cnj, org;
vi ans;

bool test(){
	set< set<int> > sets(all(org));
	set<int> q;

	bool ok;
	frr(i, n - 1){
		q.clear();
		ok = 0;

		q.insert(ans[i]);
		for (int j = i - 1; j >= 0; j--){
			q.insert(ans[j]);
			if (sets.count(q)){
				sets.erase(q);
				ok = 1;
				break;
			}
		}	

		if (!ok)
			return false;
	}

	return true;
}

void solve(){
	org.clear();

	cin>>n;

	int k, a;
	set<int> q;
	fr(i, n - 1){
		q.clear();
		cin>>k;
		fr(j, k){
			cin>>a;
			q.insert(a);
		}
		org.pb(q);
	}

	bool ok;
	frr(st, n){
		ans.clear();
		cnj = org;
		ok = 1;

		ans.pb(st);
		for (auto &x : cnj)
			if (x.count(st))
				x.erase(st);
	
		int nsz, aux;
		while (ok and (ans.size() < n)){
			nsz = 0;
			for (auto &x : cnj)
				nsz += (x.size() == 1? 1 : 0);

			if (nsz != 1)
				ok = 0;
		
			if (ok){
				for (auto &x : cnj)
					if (x.size() == 1){
						aux = *x.begin();
						ans.pb(aux);
					}
				for (auto &x : cnj)
					if (x.count(aux))
						x.erase(aux);	
			}
			
			if (!ok)
				break;
		}

		if (ok and test()){
			for (auto x : ans)
				cout<<x<<' ';
			gnl;
			return;
		}
	}
}

int main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}