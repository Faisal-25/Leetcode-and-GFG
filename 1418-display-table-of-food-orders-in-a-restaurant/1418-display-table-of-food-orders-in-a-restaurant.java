class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        List<List<String>> ans = new LinkedList<>();
        
        TreeMap<Integer, TreeMap<String, Integer>> map = new TreeMap<>();
        SortedSet<String> set = new TreeSet<>();
        for(int i = 0;i<orders.size();i++){
            int t = Integer.parseInt(orders.get(i).get(1));
            if(map.containsKey(t) == false){
                map.put(t,new TreeMap<>());
            }
            String food = orders.get(i).get(2);
            map.get(t).put(food,map.get(t).getOrDefault(food, 0)+1);
            set.add(food);
        }
        List<String> header = new LinkedList<>();
        header.add("Table");
        for(String food:set){
            header.add(food);
        }
        ans.add(header);
        for(int t:map.keySet()){
            List<String> tL = new LinkedList<>();
            System.out.println(t);
            tL.add(t+"");
            for(String f:set){
                if(map.get(t).containsKey(f) == false){
                    tL.add(0+"");
                }else{
                    tL.add(map.get(t).get(f)+"");
                }
            }
            ans.add(tL);
        }
        return ans;
    }
}