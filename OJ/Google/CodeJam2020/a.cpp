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
	int t;
	cin>>t;

	int n, m[110][110];

	for (int cse = 1; cse <= t; cse++){
		cin>>n;
		fr(i,n)
			fr(j,n)
				cin>>m[i][j];
		cout<<"Case #"<<cse<<": ";
		int k = 0;
		fr(i,n)
			k += m[i][i];
		cout<<k<<' ';
		
		int freq[110];
		k = 0;
		fr(i,n){
			ms(freq, 0);
			fr(j,n)
				if (freq[m[i][j]] > 0){
					k++;
					break;
				}
				else
					freq[m[i][j]]++;
		}
		cout<<k<<' ';

		k = 0;
		fr(j,n){
			ms(freq, 0);
			fr(i,n)
				if (freq[m[i][j]] > 0){
					k++;
					break;
				}
				else
					freq[m[i][j]]++;
		}
		cout<<k<<endl; 			
	}
}