class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int [] ans = new int[arr1.length];
        TreeMap<Integer,Integer> map = new TreeMap<Integer,Integer>();
        for(int i = 0; i<arr1.length; i++){
          map.put(arr1[i],map.getOrDefault(arr1[i],0)+1);
        }
      int j = 0;
      for(int i = 0;i<arr2.length;i++){
          for(int k = 0;k<map.get(arr2[i]);k++){
            ans[j] = arr2[i];
            j++;
          }
          map.remove(arr2[i]);
      }
      ArrayList<Integer> a = new ArrayList<>(map.keySet());
   
      for(int key:a){
        for(int k = 0;k<map.get(key);k++){
          ans[j] = key;
          j++;
        }
        map.remove(key);
      }
      return ans;
    }
}