#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  all(a)         a.begin(),a.end()

ll n,a[32],x,vis[20];
vector<ll>ans;
void fun(ll pre)
{
    if(ans.size()==n && a[ans.back()+1])
    {
        for(ll i = 0 ; i < n-1; i++) cout<<ans[i]<<" ";
        cout<<ans.back()<<endl;
        return ;
    }
    for(ll i = 2 ; i <= n ; i++)
    {
        if(!vis[i] && a[pre+i])
        {
            vis[i]=1;
            ans.push_back(i);
            fun(i);
            vis[i]=0;
            ans.pop_back();
        }
    }
}

int main()
{
    CIN;
    a[2]=a[3]=a[5]=a[7]=a[11]=a[13]=a[17]=a[19]=a[23]=a[29]=a[31]=1;
    ans.push_back(1);
    while(cin>>n)
    {
        x++;
        if(x!=1) cout<<endl;
        cout<<"Case "<<x<<":"<<endl;
        fun(1);
    }
    return 0 ;
}
