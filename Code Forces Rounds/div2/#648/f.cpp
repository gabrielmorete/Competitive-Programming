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

void solve(){
	int n, a[555], b[555];

	cin>>n;

	fr(i, n)
		cin>>a[i];
	fr(i, n)
		cin>>b[i];

	if(n % 2 and a[n / 2] != b[n / 2]){
		cout<<"no"<<endl;
		return;
	}		

	map<pii, int> freq;

	fr(i, n / 2){
		if (a[i] > a[n - i - 1])
			swap(a[i], a[n - i - 1]);
		freq[{a[i], a[n - i - 1]}]++;
	}

	bool ok = 1;

	fr(i, n / 2){
		if (b[i] > b[n - i - 1])
			swap(b[i], b[n - i - 1]);
		freq[{b[i], b[n - i - 1]}]--;
		if (freq[{b[i], b[n - i - 1]}] < 0)
			ok = 0;
	}

	if (ok)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

}

int32_t main(){
	fastio;
	int T;
	cin>>T;
	while (T--)
		solve();
}