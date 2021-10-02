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

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 3e5 + 10;

int xr[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	frr(i, MAXN - 1)
		xr[i] = i ^xr[i - 1];

	int t, a, b;	

	cin>>t;

	while (t--){
		cin>>a>>b;

		if (xr[a - 1] == b)
			cout<<a<<endl;
		else if ((xr[a - 1]^b) != a)
			cout<<a + 1<<endl;
		else
			cout<<a + 2<<endl;
	}
}