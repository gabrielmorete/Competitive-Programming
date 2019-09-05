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

int main(){
	int n,a,b,c,k;
	cin>>n; 
	k=n%3; 
	if(k){
		a=b=c=n/3;
		if(a%3==0)
			cout<<a-1<<" "<<b+1<<" "<<c+k<<" "<<endl;
		else{
			if(a%3==1){
				cout<<a<<" "<<b+1<<" "<<c+k-1<<" "<<endl;
			}
			else{
				if(k==1){
					cout<<a<<" "<<b-1<<" "<<c+2<<" "<<endl;	
				}
				else{
					cout<<a<<" "<<b<<" "<<c+2<<" "<<endl;
				}
			}
		}
	} 
	else{
		a=b=c=n/3;
		if(a%3==0){
			cout<<a-1<<" "<<b-1<<" "<<c+2<<" "<<endl;
		}
		else
			cout<<a<<" "<<b<<" "<<c<<" "<<endl;
	}

}