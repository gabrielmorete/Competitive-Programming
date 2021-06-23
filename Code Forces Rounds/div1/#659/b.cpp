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
	int n, a, frq[40];
	memset(frq, 0, sizeof frq);

	cin>>n;

	fr(i, n){
		cin>>a;
		fr(i, 30)
			frq[i] += (a&(1<<i)) != 0;// freq dos bits
	}

	int pwr = -1;

	fr(i, 31){
		if (frq[i] % 2)
			pwr = i;
	}

	if (pwr == -1){
		cout<<"DRAW"<<endl;
		return;
	}

	if (((frq[pwr] - 1)/2)%2 == 0){
		cout<<"WIN"<<endl;
		return;
	}

	if (n % 2)
		cout<<"LOSE"<<endl;
	else
		cout<<"WIN"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}