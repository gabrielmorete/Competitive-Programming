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

int n,v[1123456];
ll sum;
vi pos[1123456];
set<int> good;

int main(){
	fastio; 
	cin>>n;
	int mx=0; 
	sum=0;
	frr(i,n){
		cin>>v[i];
		mx=max(v[i],mx); 
		sum+=v[i]; 
		pos[v[i]].pb(i);

	}	

	frr(i,n){
			if(sum - 2*v[i] > 0){
				ll aux = sum-2*v[i];
				if(aux>mx)
					continue;

				for(int j=0;j<pos[aux].size();j++){
					if( pos[aux][j] != i){
						good.insert(pos[aux][j]);
					}
				}
			}

	}

	cout<<good.size()<<endl; 
	if(good.size()!=0){
		for(auto it=good.begin();it!=good.end();it++)
			cout<< (*it) <<' ';
		gnl;		
	}	
}