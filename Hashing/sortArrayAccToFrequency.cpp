//https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0#

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>a, pair<int,int>b) {
    if(a.second==b.second)
    return a.first<b.first;
    
    return a.second>b.second;
}

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n];
	    map<int,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        mp[a[i]]++;
	    }
	    
	    vector<pair<int,int>> v;
	    for(auto it=mp.begin(); it!=mp.end(); it++)
	    {
	        v.push_back(make_pair(it->first, it->second));
	    }
	    
	    sort(v.begin(), v.end(), cmp);
	    
	    for(int i=0;i<v.size();i++)
	    {
	        while(v[i].second--)
	        cout<<v[i].first<<" ";
	    }
	
	     cout<<"\n";
	}
	return 0;
}