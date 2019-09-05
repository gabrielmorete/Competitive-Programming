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
	cout.precision(15);
	int t;
	cin>>t;

	while(t--){
		ll aux;
		cin>>aux;
		if(aux*aux<4*aux){
			cout<<"N"<<endl;
			continue;
		}

		if(aux==0){
			cout<<"Y 0.00000000 0.00000000"<<endl;
			continue;
		}

		double d,b1,b2,delta;

		d=(double) aux;

		delta=sqrt(d*d-4*d);


		b1=(d+delta)/2;
		b2=(d-delta)/2;
	
		if(b1>0 && (d-b1)>0){
			cout<<"Y "<<b1<<' '<<d-b1<<endl;
			continue;
		}

		if(b2>0 && (d-b2)>0){
			cout<<"Y "<<b2<<' '<<d-b2<<endl;
			continue;
		}

		cout<<"N"<<endl;

	}
	
}