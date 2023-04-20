/*Kadane Algorithm - O(N) time complexity, where N is the size of the array*/

using System;
using System.Collections.Generic;

class Program{
    public static int kadane(List<int> arr){
        int currsum = arr[0];
        int maxsum = arr[0];
        for(int i = 1; i < arr.Count; ++i){
            currsum = Math.Max(arr[i],currsum+arr[i]);
            maxsum = Math.Max(currsum,maxsum);
        }
        return maxsum;
    }
    public static int Main(){
        List<int> arr = new List<int>{-1,2,4,-3,5,2,-5,2};
        Console.Write(kadane(arr));
        return 0;
    }
}
