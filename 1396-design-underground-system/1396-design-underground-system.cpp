class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkI;
    unordered_map<string, pair<int, int>> path;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkI[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkI[id];
        checkI.erase(id);
        
        string pathName = checkIn.first + '-' + stationName;
        path[pathName].first += t-checkIn.second;
        path[pathName].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + '-' + endStation;
        auto &route = path[routeName];
        return (double) route.first/route.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */