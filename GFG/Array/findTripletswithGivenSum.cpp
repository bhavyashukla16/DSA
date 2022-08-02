//https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1

//METHOD-1 (NAIVE)
//TC - O(N^3)
//SC - O(1)

//METHOD -2
//Fix 1st element n find the other 2 ele using 2-pointer approach in sorted array
//TC - O(N^2)
//SC - O(1)

//METHOD-3
//TC - O(N^2 log N)
//SC - O(1)
//Loop to fix 2 elements n find the 3rd element using Binary search
bool binarySearch(int l, int r, int arr[], int num1, int num2)
{
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]>num1+num2) r=mid-1;
		else if(arr[mid]<num1+num2) l=mid+1;
		return true;
	}
	return false;
}
int countTriplet(int arr[], int n)
{
	// Your code goes here
	int ans=0;
	sort(arr, arr+n);
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			int l=j+1, r=n-1;
			if(binarySearch(l, r, arr, arr[i], arr[j]))
			ans++;
		}
	}
	return ans;
}