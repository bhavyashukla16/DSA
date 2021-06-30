// arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int max_sum=arr[0], curr_sum=arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(curr_sum+arr[i]>=arr[i])
            curr_sum+=arr[i];
            
            else
            curr_sum=arr[i];
            
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }