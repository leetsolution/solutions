class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int l=0,r=arr.length-1;
        int mid=(l+r)/2;

        while(l<r)
        {
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
            return mid;
            else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1])
            {
                mid++;

            }
            else
            mid--;
        }
        return mid;
    }
}