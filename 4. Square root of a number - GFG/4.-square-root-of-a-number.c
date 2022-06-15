// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    // long long l = 0;
    // long long h = x;
    // while(l<=h){
    //     int mid = (l+h)>>1;
    //     if(mid*mid==x)
    //         return mid;
    //     else if(mid*mid > x)
    //         h = mid-1;
    //     else
    //         l = mid + 1;
    // }
    // return l-1;
          long long s =0, e = x, ans = 0;
      while(s<=e){
         long long m = s + (e-s)/2;
         if(m*m<=x){
             ans = m;
             s = m+1;
         }
          else
              e = m-1;
      } 
        return ans;
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
  // } Driver Code Ends