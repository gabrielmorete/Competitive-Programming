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
const int MAXN = 2e5 + 10;

string s;
int n, k, v[MAXN], f[MAXN];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>s>>k;

	n = s.size();

	fr(i, n){
		v[i] = 0;
		if (s[i] == 'X')
			v[i] = 1;
	}

	int r = -1, use = 0, ans = 0;

	for (int l = 0; l < n; l++){
		if (r < l - 1){
			use = 0;
			r = l - 1;
		}

		while (r + 1 < n){
			if (v[r + 1] == 1)
				r++;
			else if (use < k){
				use++;
				r++;
				f[r] = 1;
			}
			else{
				break;
			}
		}

		ans = max(ans, r - l + 1);	

		if (f[l] == 1)
			use--;
	}

	cout<<ans<<endl;
}