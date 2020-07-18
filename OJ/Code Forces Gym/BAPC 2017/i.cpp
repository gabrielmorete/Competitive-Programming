#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int32_t main(){
	fastio;
	int p, q;
	cin>>p>>q;

	if (q == 1){
		cout<< p % 2 <<endl;
		return 0;
	}
	if (p == 1){
		cout<<2 - (q & 1)<<endl;
		return 0;
	}

	if (!(p & 1))
		cout<<0<<endl;
	else if (p * q & 1)
		cout<<1<<endl;
	else if (q < p)
		cout<<0<<endl;
	else
		cout<<2<<endl;
}