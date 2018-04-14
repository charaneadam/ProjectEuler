#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl '\n'
#define what_is(x) cerr << #x << " is " << x << endl
#define MOD 1000000007
#define F first
#define S second
#define U unsigned
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define CLR(x, y) memset(x, y, sizeof(x))
#define SZ(x) int(x.size())
#define REP(x, y) for(int x=0; x<SZ(y); x++)
#define FOR(x, y, z) for(int x=y; x<z; x++)
#define ALL(t) t.begin(), t.end()
#define ll long long
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<U int> vui;
typedef vector<ll> vll;
typedef vector<U ll> vull;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vi> vvi;

vi primes;
const int N = 10000010;
bitset<N> bs;
void  sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=2; i<N; i++)
        if(bs[i]){
            for(ll j=i*i; j<N; j+=i)
                bs[j] = 0;
            primes.PB((int)i);
        }

}

int main() {
    IOS;
    sieve();
    vector<string> s;
    for(auto c : primes)
        if(c>=1000 && c<9999)
            s.PB(to_string(c));

    vector<set<string>> v;
    for(int i=0; i<s.size(); i++){
        set<string> ss;
        for(int j=i+1; j<s.size(); j++)
            if(is_permutation(s[i].begin(), s[i].end(), s[j].begin()))
                ss.insert(s[i]), ss.insert(s[j]);
        if(ss.size() == 3) v.PB(ss);
    }

    for(auto c : v){
        vll vv;
        ll diff = 0;
        for(auto cc : c) vv.PB(stoll(cc));
        sort(vv.begin(), vv.end());
        diff = vv[1] - vv[0];
        if(vv[2] - vv[1] == diff) cout << vv[0] << vv[1] << vv[2] << endl;
    }

    return 0;
}
