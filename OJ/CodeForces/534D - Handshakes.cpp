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

int n, freq[212345];
vi v, pos[212345], ans;

int main(){
	fastio;
	cin>>n;

	int x;
	fr(i, n){
		cin>>x;
		freq[x]++;
		v.pb(x);
		pos[x].pb(i + 1);
	}
	sort(all(v));

	int done, at;
	done = at = 0;


	while (done < n){
		if (at < 0)
			break;
		if (freq[at]){
			freq[at]--;
			ans.pb( pos[at][freq[at]]);
			at++;
			done++;
		}
		else
			at -= 3;
	}

	if (done == n){
		cout<<"Possible"<<endl;
		for (int x : ans)
			cout<<x<<' ';
		gnl;
	}
	else
		cout<<"Impossible"<<endl;
}