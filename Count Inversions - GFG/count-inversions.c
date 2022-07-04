// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int count=0;
    
    void merge(long long arr[],long long l,long long mid,long long r){
       long long int i=l;
       long long int j=mid+1;
       long long int k=l;
       long long int B[r+1];
        
        while(i<=mid && j<=r){
            if(arr[i]>arr[j]){
                count+=mid-i+1; //extra line added in merge sort
                B[k++]=arr[j++];
                
            }
            else B[k++]=arr[i++];
        }
        
        while(i<=mid){
            B[k++]=arr[i++];
        }
        while(j<=r){
            B[k++]=arr[j++];
        }
        
        for(int k=l;k<=r;k++){
            arr[k]=B[k];
        }
        
    }
    
    
    void mergeSort(long long arr[],long long l,long long r){
        
        if(l>=r) return;
        
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
        return;
        
    }
    
    
     long long int inversionCount(long long arr[], long long N)
    {
        count=0; //reini
        mergeSort(arr,0,N-1);
        return count;
    }



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends