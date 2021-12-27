#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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
const int MAXN = 4e5 + 10;
const ll mod = 1e9 + 7;

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, k, x;
	cin>>n>>k;

	ll sum, acum, lst;
	cin>>lst;
	acum = lst;
	sum = lst;

	if (k == 1){
		cout<<lst<<endl;
		return 0;
	}

	for (int i = 2; i <= n; i++){
		cin>>x;

		lst = min(x, acum);
		sum += lst;
		acum += sum;
	
		if (i == k){
			cout<<lst<<endl;
			return 0;
		}
	}

	for (int i = n + 1; i < k; i++){
		sum += acum;
		acum += sum;
	}

	cout<<acum % mod<<endl;
}