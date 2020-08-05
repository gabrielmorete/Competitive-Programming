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
	int a1, a2, k1, k2 , n;
	cin>>a1>>a2>>k1>>k2>>n;

	int p1, p2;
	p1 = a1*k1;
	p2 = a2*k2;

	int mmin, mmax, aux;
	mmin = mmax = 0;

	if (k1 > k2){
		swap(k1, k2);
		swap(a1, a2);
		swap(p1, p2);
	}

	aux = n;

	if (aux/k1 > a1){
		mmax += a1;
		aux -= k1*a1;
	}
	else{
		mmax += (aux/k1);
		aux -= (aux/k1)*k1;
	}

	if (aux/k2 > a2){
		mmax += a2;
		aux -= k2*a2;
	}
	else{
		mmax += (aux/k2);
		aux -= (aux/k2)*k2;
	}

	aux = n;

	fr(i,a1)
		aux -= k1 - 1;
	fr(i,a2)
		aux -= k2 - 1;
	mmin = max(0, aux);		
	
	cout<<mmin<<' '<<mmax<<endl;


}