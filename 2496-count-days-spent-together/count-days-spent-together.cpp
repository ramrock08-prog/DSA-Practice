class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto converttodays = [](string date){
            vector<int> dayinmonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int month = stoi(date.substr(0,2));
            int day = stoi(date.substr(3,2));
            int totaldays = day;
            for(int i=0; i< month -1; i++){
                totaldays += dayinmonth[i];
            }
        return totaldays;
        };
        int astart = converttodays(arriveAlice);
        int aend = converttodays(leaveAlice);
        int bstart = converttodays(arriveBob);
        int bend = converttodays(leaveBob);
        int overlapstart = max(astart,bstart);
        int overlapend = min(aend,bend);
        if(overlapstart <= overlapend){
            return overlapend - overlapstart + 1;
        }return 0;
    
    }
};