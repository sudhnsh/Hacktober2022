#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define ffst                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define m 1000000007
// by sudhnsh
void solve()
{
    ll n;
    cin>>n;
    cout<<n<<' ';
    rep(i,0,n-1)
    {
       cout<<i+1<<' ';
    }
    cout<<endl;
}
int main()
{
    //ffst;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}