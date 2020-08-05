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

ll n, m[2123][2123], s[2123][2123], aux[2123][2123];
int main(){
	fastio;
	
	cin>>n;
	fr(i,n)
		fr(j,n) {
			cin>>m[i][j];
			s[i][j] -= m[i][j];
		}

	ll sum;
	for (int d = 1; d < n; d++) {
		sum = 0;
		for (int j = 0; j < n - d; j++){
			int i = j + d;
			sum += m[i][j];
		}
		for (int j = 0; j < n - d; j++){
			int i = j + d;
			s[i][j] += sum;
		}
	}		

	for (int d = 0; d < n; d++){
		sum = 0;
		for (int i = 0; i < n - d; i++){
			int j = i + d;
			//cout<<i<<' '<<j<<'|';
			sum += m[i][j];
		}
		for (int i = 0; i < n - d; i++){
			int j = i + d;
			s[i][j] += sum;
		}
	}	

	for (int d = 1; d < n; d++) {
		sum = 0;
		for (int j = 0; j < n - d; j++){
			int i = n - j - 1 - d;
			sum += m[i][j];
		}
		for (int j = 0; j < n - d; j++){
			int i = n - j - 1 - d;
			s[i][j] += sum;
		}
	}	

	for (int d = 0; d < n; d++){
		sum = 0;
		for (int i = n - 1; i >= d; i--){
			int j = n - i - 1 + d;
			//cout<<i<<' '<<j<<'|';
			sum += m[i][j];
		}
		for (int i = n - 1; i >= d; i--){
			int j = n - i - 1 + d;
			s[i][j] += sum;
		}
	}	

	ll x1,x2,y1,y2,b1,b2;
	b1 = b2 = -1;

	fr(i,n){
		fr(j,n){
			//cout<<s[i][j]<<' ';
			if ((i+j)%2){
				if (s[i][j] > b1){
					b1 = s[i][j];
					x1 = i + 1;
					y1 = j + 1;
				}
			}
			else{
				if (s[i][j] > b2){
					b2 = s[i][j];
					x2 = i + 1;
					y2 = j + 1;
				}
			}
		}
	//	gnl;
	}	
	cout<<b1+b2<<endl;
	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;



}