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

int main(){
	fastio;
	int t;
	cin>>t;

	for (int cse = 1; cse <= t; cse++){
		cout<<"Case #"<<cse<<": ";
		int n, c, j, ok;
		string ans;
		vector<tuple<int,int,int>> v;
		cin>>n;

		v.clear();
		ans.clear();
		ans.resize(n);
		ok = 1;

		int a, b;
		fr(i,n){
			cin>>a>>b;
			v.pb({a, b, i});
		}
		sort(all(v));

		c = j = -1;

		for (auto x : v){
			if (c <= get<0>(x)){
				c = get<1>(x);
				ans[get<2>(x)] = 'C';
			}
			else if (j <= get<0>(x)){
				j = get<1>(x);
				ans[get<2>(x)] = 'J';
			}
			else{
				ok = 0;
			}
		}
		if (ok)
			cout<<ans<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;

	}
}