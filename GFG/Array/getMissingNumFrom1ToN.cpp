//https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1#

//METHOD-1
//Sum of 1 to n - Sum of array elements
//TC - O(N)
//SC - O(1)
int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        int sum=1;
        for(int i=2; i<=n; i++)
        {
            sum+=i; //simultaneous addition n subtraction to prevent integer overflow
            sum-=arr[i-2];
        }
        return sum;
    }

//METHOD-2
//TC - O(N)
//SC - O(1)
// XOR has certain properties 

// Assume a1 ^ a2 ^ a3 ^ ...^ an = a and a1 ^ a2 ^ a3 ^ ...^ an-1 = b
// Then a ^ b = an

int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        int a=1, b=arr[0];
        for(int i=2;i<=n;i++)
        a^=i;
        for(int i=3;i<=n;i++)
        b^=arr[i-2];
        return a^b;
    }

//METHOD-3
//Sort, then all ele at index=val-1