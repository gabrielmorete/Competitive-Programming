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
	int n, pos[112345], vic[112345];
	cin>>n;

	int x;
	frr(i,n){
		cin>>x;
		pos[x] = i;
	}

	vic[pos[n]] = -1;

	for (int i = n - 1; i >= 1; i--){
		int aux = pos[i];
		bool ok = 0;
		while (aux <= n){
			if (vic[aux] == -1)
				ok = 1;
			aux += i;
		}
		aux = pos[i];
		while (aux >= 1){
			if (vic[aux] == -1)
				ok = 1;
			aux -= i;
		}

		if (ok)
			vic[pos[i]] = 1;
		else
			vic[pos[i]] = -1;
	}
	frr(i,n)
		if (vic[i] == 1)
			cout<<"A";
		else
			cout<<"B";		
	gnl;

}