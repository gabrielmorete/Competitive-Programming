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
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;


int main(){
	fastio;
	int t;
	cin>>t;

	while(t--){
		ll n,x,y,d;
		cin>>n>>x>>y>>d;


		if((abs(y-x)%d) && (abs(y-1)%d) &&  ((abs(n-y)%d)) ){
			cout<<-1<<endl;
			continue;
		}
		ll a1,a2,a3;
		a1=llINF;a2=llINF;a3=llINF;

		if(abs(y-x)%d == 0)
			a1=abs(y-x)/d;

		if((y-1)%d ==0){
			a2=(x-1+d-1)/d;
			a2+=(y-1)/d;
		}

		if((n-y)%d==0){
			a3=(n-x+d-1)/d;
			a3+=(n-y)/d;
		}

		cout<<min(a1,min(a2,a3))<<endl;
		



	}

}