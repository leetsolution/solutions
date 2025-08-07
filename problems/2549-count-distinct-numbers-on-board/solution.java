class Solution {
    public int distinctIntegers(int n) {
        Set<Integer> set = new HashSet<>();
        set.add(n);
        Set<Integer> added = new HashSet<>();
        while(true){
            Set<Integer> next = new HashSet<>();
            for(int x : set){
                for(int i = 1; i <= n; ++i){
                    if(x % i == 1){
                        if(!set.contains(i)){
                            next.add(i);
                        }
                    }
                }
            }
            if(next.isEmpty()){
                break;
            }
            set.addAll(next);
        }
        return set.size();
    }
}