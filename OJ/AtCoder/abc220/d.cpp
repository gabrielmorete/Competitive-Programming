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
const int MAXN = 1e5 + 10;
const ll mod = 998244353;


int n, v[MAXN];
ll now[11], lst[11];


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	fr(i, n)
		cin>>v[i];

	lst[v[0]]++;

	for (int i = 1; i < n; i++){
		fr(j, 10){
			now[(j * v[i])%10] = (lst[j] + now[(j * v[i])%10])%mod;
			now[(j + v[i])%10] = (lst[j] + now[(j + v[i])%10])%mod;
		}

		fr(j, 10){
			lst[j] = now[j];
			now[j] = 0;
		}
	}


	fr(i, 10)
		cout<<lst[i]<<endl;
}