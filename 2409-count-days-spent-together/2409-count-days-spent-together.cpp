class Solution {
public:
    int finddayofyear(string date,vector<int>& cummonthdays){
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3));

        return cummonthdays[month-1]+day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthdays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cummonthdays(13,0);
        cummonthdays[1]=31;
        for(int i=2;i<=12;i++){
            cummonthdays[i]=cummonthdays[i-1]+monthdays[i-1];
        }
        int arriveAliceday=finddayofyear(arriveAlice,cummonthdays);
        int leaveAliceday=finddayofyear(leaveAlice,cummonthdays);
        int arriveBobday=finddayofyear(arriveBob,cummonthdays);
        int leaveBobday=finddayofyear(leaveBob,cummonthdays);

        int start = max(arriveAliceday, arriveBobday);
        int end = min(leaveAliceday, leaveBobday);
        return max(0, end - start + 1);
    }
};