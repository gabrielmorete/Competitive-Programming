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
ll memo[3][312345];
ll a[312345], b[312345];

ll pd(int add, int pos) {
	if(pos==n) return 0;
	
	ll &ans = memo[add][pos];
	if (ans!=-1)
		return ans;
	
	ans = llINF;

	fr(i,3)
		if(pos == 0 or (a[pos]+i)!=(a[pos-1]+add))
			ans=min(ans, pd(i,pos+1) + i*b[pos]);

	return ans;	
}

int main(){
	fastio;
	int q;
	cin>>q;
	while(q--){
		cin>>n;

		fr(i,n){
			cin>>a[i]>>b[i];
			memo[0][i]=memo[1][i]=memo[2][i]=-1;
		}
		
		cout<<pd(0,0)<<endl;
	}

}