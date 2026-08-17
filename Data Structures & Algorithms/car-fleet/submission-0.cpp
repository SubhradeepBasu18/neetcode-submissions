class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet = 0;
        double fleetTime = 0;
        int n = position.size();

        vector<pair<int,double>>carPos;
        for(int i=0;i<n;i++){
            double t = (double)(target - position[i])/speed[i];
            carPos.push_back({position[i], t});
        }

        sort(carPos.begin(), carPos.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        for(auto &[pos, time]: carPos){
            if(time > fleetTime){
                fleet++;
                fleetTime = time;
            }
        }
        return fleet;
    }
};
 