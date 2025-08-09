class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int oddCount = 0;
        int evenCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        if (Math.abs(oddCount - evenCount) > 1) {
            return -1;
        }

        long ans1 = 0;
        long ans2 = 0;

        if (evenCount >= oddCount) {
            ans1 = calculateSwaps(nums, 0);
        } else {
            ans1 = Long.MAX_VALUE;
        }

        if (oddCount >= evenCount) {
            ans2 = calculateSwaps(nums, 1);
        } else {
            ans2 = Long.MAX_VALUE;
        }

        return (int)Math.min(ans1, ans2);
    }

    private long calculateSwaps(int[] nums, int startParity) {
        long swaps = 0;
        int n = nums.length;
        int[] arr = nums.clone();
        int evenIndex = 0;
        int oddIndex = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (startParity == 0) {
                    while (evenIndex < n && arr[evenIndex] % 2 != 0) {
                        evenIndex++;
                    }
                    if(evenIndex == n) return Long.MAX_VALUE;
                    swaps += evenIndex - i;
                    for (int j = evenIndex; j > i; j--) {
                        int temp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = temp;
                    }
                    evenIndex = i+1;
                    startParity = 1;

                } else {
                     while (oddIndex < n && arr[oddIndex] % 2 == 0) {
                        oddIndex++;
                    }
                     if(oddIndex == n) return Long.MAX_VALUE;
                    swaps += oddIndex - i;
                    for (int j = oddIndex; j > i; j--) {
                        int temp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = temp;
                    }
                    oddIndex = i+1;
                    startParity = 0;
                }

            }else{
                if (startParity == 0) {
                    while (oddIndex < n && arr[oddIndex] % 2 == 0) {
                        oddIndex++;
                    }
                    if(oddIndex == n) return Long.MAX_VALUE;
                    swaps += oddIndex - i;
                    for (int j = oddIndex; j > i; j--) {
                        int temp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = temp;
                    }
                    oddIndex = i+1;
                    startParity = 1;
                } else {
                    while (evenIndex < n && arr[evenIndex] % 2 != 0) {
                        evenIndex++;
                    }
                    if(evenIndex == n) return Long.MAX_VALUE;
                    swaps += evenIndex - i;
                    for (int j = evenIndex; j > i; j--) {
                        int temp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = temp;
                    }
                    evenIndex = i+1;
                    startParity = 0;
                }
            }
        }
        return swaps;
    }
}