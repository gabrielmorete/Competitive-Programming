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
		int x,ans; 
		cin>>x; 
		ans=0;
		while(x!=0){
			while((x-7) != 1 && (x-7)>=0){
				x-=7; 
				ans++;
			}
			while((x-6) != 1 && (x-6)>=0){
				x-=6; 
				ans++;
			}
			while((x-5) != 1 && (x-5)>=0){
				x-=5; 
				ans++;
			}
			while((x-4) != 1 && (x-4)>=0){
				x-=4; 
				ans++;
			}

			while((x-3) != 1 && (x-3)>=0){
				x-=3; 
				ans++;
			}
			while((x-2) != 1 && (x-2)>=0){
				x-=2; 
				ans++;
			}

			
		}
		cout<<ans<<endl;


	}
	
}