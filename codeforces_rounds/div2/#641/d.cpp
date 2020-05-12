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

void solve(){
	int n, k, v[MAXN];
	cin>>n>>k;

	bool tem = 0;
	fr(i, n){
		cin>>v[i];
		if (v[i] == k)
			tem = 1;
		
		if (v[i] > k)
			v[i] = 2;
		else if (v[i] == k)
			v[i] = 1;
		else
			v[i] = 0;
	}

	if (!tem){
		cout<<"no"<<endl;
		return;
	}
	else if (n == 1){
		cout<<"yes"<<endl;
		return;
	}
	else if (n == 2){
		if ((v[0] > 0) + (v[1] > 0) == 2)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		return;
	}

	tem = 0;
	for (int i = 2; i < n; i++){
		if ((v[i - 2] > 0) + (v[i - 1] > 0) + (v[i] > 0) >= 2)
			tem = 1;
	}

	if (tem)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}