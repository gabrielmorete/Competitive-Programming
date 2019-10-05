#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define endl "\n" 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;

ll md(ll a){
	if(a < 0)
		return -a;
	return a;	
}

ll votes [1123][2];
ll wasted[11234][2];

int main(){
	fastio;
	ll p, d, t;
	cin>>p>>d;	

	ll a, b, dist;
	t = 0;

	fr(i,p){
		cin>>dist>>a>>b;
		t += a+b;
		votes[dist][0] += a;
		votes[dist][1] += b;
	}

	ll wa = 0, wb = 0;

	frr(i,d){
		//cout<<i<<' '<<votes[i][0]<<' '<<votes[i][1]<<endl;
		ll ad = votes[i][0];
		ll bd = votes[i][1];
		ll tot = ad + bd;

		if( ad > bd){
			wasted[i][1] = bd;
			wb += bd;
			if( ad > ( (tot)/2 + 1) ){
				wasted[i][0] = ad - ( (tot)/2 + 1);
				wa += wasted[i][0];
			}
			cout<<"A"<<' '<<wasted[i][0]<<' '<<wasted[i][1]<<endl;
		}
		else {
			wasted[i][0] = ad;
			wa += ad;
			if( bd > ( (tot)/2 + 1) ){
				wasted[i][1] = bd - ( (tot)/2 + 1);
				wb += wasted[i][1];
			}
			cout<<"B"<<' '<<wasted[i][0]<<' '<<wasted[i][1]<<endl;
		}
	}
	cout << setprecision(9)<<fixed;
	cout<<(double) (md(wa-wb))/t<<endl;
	
 
}