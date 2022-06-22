// { Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Map.Entry;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            Solution g = new Solution();
            ArrayList<Integer> ans = g.duplicates(a, n);
            for (Integer val : ans) System.out.print(val + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


class Solution {
   public static ArrayList<Integer> duplicates(int arr[], int n) {
       ArrayList<Integer>al=new ArrayList<>();
       HashMap<Integer,Integer> mp=new HashMap<>();
       
       for(int i=0;i<n;i++){
           int temp=1;
           if(mp.containsKey(arr[i])){
               mp.put(arr[i],++temp);
           }else{
               mp.put(arr[i],temp);
           }
       }
       for(int k:mp.keySet()){
           if(mp.get(k)>1){
               al.add(k);
           }
       }
       Collections.sort(al);
       if(al.isEmpty()){
           al.add(-1);
       }
       return al;
   }
}
