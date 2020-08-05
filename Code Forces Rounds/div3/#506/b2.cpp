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
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

#define MAX 312345


int main(){
	ll n,mx,p1,p2,v[MAX],last,size; 
	fastio; 
	cin>>n; 
	fr(i,n) 
		cin>>v[i]; 
	if(n==1){
		cout << 1 << endl;
		return 0;
	}	
	mx=1;
	p1=0;
	p2=1; 
	while(p1<n){
		last=v[p1];
		size=1;
		while(p2<n && last*2>=v[p2]){
			size++;
			mx=max(mx,size);
			last=v[p2];
			p2++; 
		}
		
		if(p2==n){
			mx=max(mx,size);
			break;
		} 
		p1=p2;
		p2++;
	}

	cout<<mx<<endl;
	return 0;
}