/*
You are given an array of integers arr and an integer k. Your task is to find the maximum sum of a non-empty
subarray of length at most k. The subarray should contain at least one element.
Write a function max_sum_subarray that takes the array arr and the integer k as input and returns
the maximum sum of a subarray of length at most k.

Time complexity: O(N), where N is the size of the array
*/

using System;

class Program{
    public static int maxSubarraySum_k(int[] arr, int k){
        int window_sum = 0; // sum of window of length k
        int max_sum = 0;
        
        for(int i = 0; i < k ;++i){
            window_sum += arr[i];
        }
        for(int i = k; i < arr.Length; ++i){
            window_sum += arr[i] - arr[i-k];
            max_sum = Math.Max(window_sum,max_sum);
        }
        return max_sum;
    }
    public static int Main(){
        int[] arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
        int k = 4;
        Console.WriteLine(maxSubarraySum_k(arr,k));
        return 0;
    }
}
