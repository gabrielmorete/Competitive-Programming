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
	int n;
	vi v;
	int x;
	
	cin>>n;

	fr(i,n){
		cin>>x;
		v.pb(x);
	}

	if(n==1){
		cout<<1<<endl;
		return 0;
	}

	sort(all(v));

	int pa, pb, ans; 

	pa = n-1;
	pb = (n-2)/2;

	ans = 0;
	while (pa > (n-2)/2 and pb >= 0){
		while (pb >= 0 and v[pb]>(v[pa]/2)){
			pb--;
			ans++;
		}

		if(pb>=0)
			ans++;
		else{
			ans++;
		}

		pa--;
		pb--;

	}

	while(pa>(n-2)/2){
		ans++;
		pa--;
	}
	while(pb>=0){
		ans++;
		pb--;
	}

	cout<<ans<<endl;
}