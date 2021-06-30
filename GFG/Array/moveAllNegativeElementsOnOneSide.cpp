#include <bits/stdc++.h>

int main() {
	//code
	int n; 
	std::cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	
	int l=0, r=n-1;
	while(l<r)
	{
	    if(a[l]>0 && a[r]<0)
	    std::swap(a[l++],a[r--]);
	    
	    else if(a[l]<0 && a[r]<0)
	    l++;
	    
	    else if(a[l]>0 && a[r]>0)
	    r--;
	    
	    else
	    {
	        l++; r--;
	    }
	}
	for(int i=0;i<n;i++)
	std::cout<<a[i]<<" ";
	
	return 0;
}