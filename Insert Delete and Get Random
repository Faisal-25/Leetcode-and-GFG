class RandomizedSet {
  unordered_set<int> s;
public:
    RandomizedSet() {
        unordered_set<int> s;
    }
    
    bool insert(int val) {
        if(s.find(val) !=s.end())return false;
      s.insert(val);
      return true;
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end())return false;
      s.erase(val);
      return true;
    }
    
    int getRandom() {
       
    
      
      int sz = s.size();
      int i = rand()%(sz);
      auto it = next(s.begin(),i);
      return *it;
     
      
    }
};
