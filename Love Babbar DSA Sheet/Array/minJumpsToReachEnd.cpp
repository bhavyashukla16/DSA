//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#

int minJumps(int arr[], int n){
        // Your code here
        if(n == 1)
        return 0;
        if(arr[0] == 0)
        return -1;
        int maxReach = arr[0];
        int jumps = 1;
        int stepsPossible = arr[0];
        
        for(int i=1; i<n; i++)
        {
            if(i == n-1)
            return jumps;
            
            maxReach = max(maxReach, i+arr[i]);
            stepsPossible--;
            
            if(stepsPossible == 0)
            {
                jumps++;
                if(i >= maxReach)
                return -1;
                
                stepsPossible = maxReach - i; //so that we can take as big jumps as possible
            }
        }
        return -1;
    }