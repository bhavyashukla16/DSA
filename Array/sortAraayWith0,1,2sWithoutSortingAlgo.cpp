#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];

        int c0=0, c1=0, c2=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            c0++;

            else if(a[i]==1)
            c1++;

            else c2++;
        }

        int i=0;

        while(c0>0)
        a[i++]=0;

        while(c1>0)
        a[i++]=1;

        while(c2>0)
        a[i++]=2;

        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    }

    return 0;
}