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
	int n, v[112345];

	cin>>n;
	
	fr(i,n)	
		cin>>v[i];

	int j = n - 1;
	while (j > 0)
		if (v[j] >= v[j - 1])
			j--;
		else
			break;
	
	if (j == 0){
		cout<<0<<endl;
		return 0;
	}

	int i = j - 1;

	if (i == 0 and v[0] < v[n - 1]){
		cout<<-1<<endl;
		return 0;
	}

	while (i > 0) {
		if (v[i] < v[i - 1] or v[i] < v[n-1] or v[i-1] < v[n-1]) {
			cout<<-1<<endl;
			return 0;
		}
		i--;			
	}


	cout<<n - j<<endl;

}