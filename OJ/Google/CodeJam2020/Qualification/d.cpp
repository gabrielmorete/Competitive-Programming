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

int b, v[110];
char ddds;

void flip(){
	frr(i, b)
		v[i] = 1 - v[i];
}
void reverse(){
	frr(i,b/2)
		swap(v[i], v[b - i + 1]);
}

void solve(){
	int i, j, cnt;
	i = 1;
	j = b;
	cnt = 0;
	goto start;

	int aux;
	while (true){
		while ((cnt + 1)%10 != 1 and j > i){
			start:
			cout<<i<<endl;
			cin>>aux;
			v[i] = aux;
			i++;

			cout<<j<<endl;
			cin>>aux;
			v[j] = aux;
			j--;
			cnt += 2;
		}

		if (j <= i){
			for (int k = 1; k <= b; k++)
				cout<<v[k];
			cout<<endl;
			cin>>ddds;
			assert(ddds == 'Y');
			return;
		}
		
		int eq, peq, pdf;
		eq = 0;
		peq = pdf = -1;
		for (int k = 1; k < i; k++){
			if (v[k] == v[b - k + 1]){
				eq++;
				peq = k;
			}
			else{
				pdf = k;
			}
		}
			
		int vp1, vp2;	
		if (eq == (i - 1)){
			cout<<peq<<endl;
			cin>>vp1;
			cout<<peq<<endl;
			cin>>vp2;

			if (vp1 != v[peq])
				flip();

		}else if (eq == 0){
			cout<<pdf<<endl;
			cin>>vp1;
			cout<<pdf<<endl;
			cin>>vp2;

			if (vp1 != v[pdf])
				flip();

		}else{
			cout<<peq<<endl;
			cin>>vp1;
			cout<<pdf<<endl;
			cin>>vp2;

			if ((vp1 == v[peq]) and (vp2 != v[pdf])){
				reverse();
			}
			else if((vp1 != v[peq]) and (vp2 != v[pdf])){
				flip();
			}
			else if((vp1 != v[peq]) and (vp2 == v[pdf])){
				flip();
				reverse();
			}
		}	
		cnt += 2;
	}
}

int main(){
	int t;
	cin>>t>>b;

	while(t--)
		solve();
}