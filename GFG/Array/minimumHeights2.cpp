//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int result= arr[n-1]-arr[0];
        int max_ele, min_ele;
        
        for(int i=1;i<n;i++)
        {
                max_ele = max(arr[n-1]-k, arr[i-1]+k);
                min_ele = min(arr[0]+k, arr[i]-k);
                
                if(min_ele<0) continue; //cause then result would increase but we have to minimise it
                
                result = min(result, max_ele - min_ele);
        }
        
        return result;
    }