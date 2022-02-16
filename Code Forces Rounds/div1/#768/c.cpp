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
const int MAXN = 4e5 + 10;

int n, a[MAXN], lst[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	frr(i, n)
		cin>>a[i];

	frr(i, n)
		lst[a[i]] = i;

	int ans = 0, r = 0, nxtr = 0;	
	for (int i = 1; i <= n; i++){
		if (lst[a[i]] > nxtr)
			nxtr = lst[a[i]];
		if (r > i)
			ans++;

		if (i >= r)
			r = nxtr;
	}	

	cout<<ans<<endl;
}