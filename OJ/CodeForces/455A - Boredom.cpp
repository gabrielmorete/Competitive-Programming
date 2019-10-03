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
ll memo[212345];
int n, in[112345], freq[112345];
vector<pll> v;

ll pd(){

    int tam = v.size();

    for(int i = tam-1; i >= 0; i--){
        memo[i] = v[i].fst*v[i].snd;

        int j = i + 1;
        if (j < tam and v[j].fst == (v[i].fst+1)){
            memo[i] = v[i].fst*v[i].snd + (j+1 < tam? memo[j+1] : 0);
            memo[i] = max(memo[i], memo[j]);
        }    
        else if (j < tam){
            memo[i] = v[i].fst*v[i].snd + memo[j] ;
        }    
    }

    ll bst = 0;
    fr(i,tam)
        bst = max(bst,memo[i]);
    
    return bst;    
}


int main(){
	fastio;
   
    cin>>n;
    fr(i,n)
        cin>>in[i];

    sort(in,in+n);    
   
    fr(i,n)
        freq[in[i]]++;
    fr(i,112345)
        if(freq[i])
            v.pb({i,freq[i]});

    cout<<pd()<<endl;
}