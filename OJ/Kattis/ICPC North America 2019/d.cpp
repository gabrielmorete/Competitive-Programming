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

int freq[1123];
int n;
int main(){
	fastio;
	cin>>n;
	int x, mx = 0;	

	fr(i,n){
		cin>>x;
		freq[x]++;
		mx = max(mx,x);
	}
	bool ok = 1;
	frr(i,mx){
		if(freq[i]==0){
			cout<<i<<endl;
			ok = 0;
		}
	}
	if( ok){
		cout<<"good job"<<endl;
	}
 
}