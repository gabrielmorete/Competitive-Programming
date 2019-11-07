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
	int n, k, a[212];
	cin>>n>>k;
	fr(i,n)
		cin>>a[i];
	vi in, out;
	int best = -10000, sum;
	int aux;
	
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			in.clear();
			out.clear();

			sum = 0;
			for (int l = i; l <= j; l++){
				in.pb(a[l]);
				sum += a[l];
			}
			
			for (int l = 0; l < i; l++)
				out.pb(a[l]);
			for (int l = j + 1; l < n; l++)
				out.pb(a[l]);
			sort( all(in));
			sort( all(out), greater<int>());

			for (int cnt = 0; cnt < k; cnt++){
				if (cnt < in.size() and cnt < out.size() and in[cnt] < out[cnt])
					sum += out[cnt] - in[cnt];
			}
			best = max( best, sum);
		}
	}

	cout<<best<<endl;	

}