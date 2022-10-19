class SORTracker {
public:
    set<pair<int,string>> s;
    set<pair<int,string>>::iterator it=s.end();
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        auto it1 = s.insert({-score,name}).first;
        if(it==s.end() || (*it1) < *it) --it;
    }
    
    string get() {
        return (*(it++)).second;
    }
};
