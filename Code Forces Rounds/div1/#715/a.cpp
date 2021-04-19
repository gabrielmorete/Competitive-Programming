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

void solve(){
	int n;
	string a, b, c, ans;

	cin>>n>>a>>b>>c;

	int i, j, k;
	i = j = k = 0;

	int zr;
	while (i < 2*n and j < 2*n and k < 2*n){
		zr = a[i] == '0';
		zr += b[j] == '0';
		zr += c[k] == '0';
		if (zr >= 2){
			ans.pb('0');
			if (a[i] == '0') i++;
			if (b[j] == '0') j++;
			if (c[k] == '0') k++;
		}
		else{
			ans.pb('1');
			if (a[i] == '1') i++;
			if (b[j] == '1') j++;
			if (c[k] == '1') k++;
		}
	}

	if (i == 2*n){
		if (j > k)
			while (j < 2*n)
				ans.pb(b[j++]);
		else
			while (k < 2*n)
				ans.pb(c[k++]);	
	}
	else if (j == 2*n){
		if (i > k)
			while (i < 2*n)
				ans.pb(a[i++]);
		else
			while (k < 2*n)
				ans.pb(c[k++]);
	}
	else{
		if (i > j)
			while (i < 2*n)
				ans.pb(a[i++]);
		else
			while (j < 2*n)
				ans.pb(b[j++]);
	}

	cout<<ans<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}