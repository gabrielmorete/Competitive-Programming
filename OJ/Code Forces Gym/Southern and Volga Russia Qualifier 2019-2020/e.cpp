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
int n, m, k, seq[212345], ans[212345];
priority_queue<pii> pq;


int main(){
	fastio;
	cin>>n>>m>>k;

	int x;
	frr(i,m){
		cin>>x;
		pq.push({x,i});
	}

	pii aux, aux2;
	frr(i,n){
		aux = pq.top();
		pq.pop();

		if (ans[i - 1] == aux.snd) {
			if (seq[i - 1] < k){
				ans[i] = aux.snd;
				seq[i] = seq[i - 1] + 1;
				aux.fst--;
				if (aux.fst != 0)
					pq.push(aux);
			}
			else {
				if (pq.empty()){
					cout<<-1<<endl;
					return 0;
				}
				aux2 = pq.top();
				pq.pop();
				pq.push(aux);

				ans[i] = aux2.snd;
				seq[i] = 1;
				aux2.fst--;
				if (aux2.fst != 0)
					pq.push(aux2);
			}

		}
		else {
			ans[i] = aux.snd;
			seq[i] = 1;
			aux.fst--;
			if(aux.fst != 0)
				pq.push(aux);	
		}
	}
	frr(i,n)
		cout<<ans[i]<<' ';
	gnl;	
}