//https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1#

//METHOD 1
//TC=O(N) SC=O(N)
void rearrange(long long *arr, int n) 
    { 
    	// Your code here
    	vector <long long> v;
    	if(n!=1)
    	{
        	long long l=0, r=n-1;
        	while(l<r)
        	{
        	    v.push_back(arr[r--]);
        	    v.push_back(arr[l++]);
        	}
        	if(n&1)
        	v.push_back(arr[l]);
        	for(long long j=0;j<n;j++)
        	arr[j] = v[j];
    	}
    }

//METHOD 2: without using extra space
//TC=O(N) SC=O(1)
// The purpose of this expression is to store two elements at index arr[i]. 
// arr[max_index] is stored as multiplier and "arr[i]" is stored as remainder. 
// For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. With 91, 
// we can get original element as 91%10 and new element as 91/10.

void rearrange(long long *arr, int n) 
    { 
    	// Your code here
    	long long max_index=n-1, min_index=0;
        long long max_ele=arr[n-1]+1; //can use any num > max value in array
    	for(long long i=0;i<n;i++) //using odd n even elements
    	{
    	    if(i&1)
    	    {
    	        arr[i]+=(arr[min_index] % max_ele) * max_ele;
    	        min_index++; //traversing elements from start as the array is sorted
    	    }
    	    else
    	    {
    	        arr[i]+=(arr[max_index] % max_ele) * max_ele;
    	        max_index--;  //traversing last elements
    	    }
    	}
    	for(long long i=0;i<n;i++)
    	arr[i]/=max_ele;
    }