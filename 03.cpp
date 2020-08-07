#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
#define  pb             push_back
vector<string>v1;
string s2, s1[11],s;
ll sz ,cnt=1;
void fun(ll indx)
{
    if(indx==sz)
    {
        cout<<s;
        if(cnt>1) cout<<",";
        cnt--;
        return ;
    }
    for(ll i = 0 ; i < v1[indx].size(); i++)
    {
        s+=v1[indx][i];
        fun(indx+1);
        s.pop_back();
    }
}
int main()
{
    CIN;
    ll  i;
    s1[2]="abc";
    s1[3]="def";
    s1[4]="ghi";
    s1[5]="jkl";
    s1[6]="mno";
    s1[7]="pqrs";
    s1[8]="tuv";
    s1[9]="wxyz";
    cin >> s2 ;
    sz=s2.size();
    for( i = 0 ; i<sz ; i++)
    {
        v1.pb(s1[s2[i]-'0']);
        cnt*=v1.back().size();
    }
    cout<<cnt<<endl;
    fun(0);
    return 0 ;
}
