class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt_fives = 0, cnt_tens = 0, cnt_twenties = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5) cnt_fives++;
            else if(bills[i] == 10){
                if(cnt_fives > 0){
                    cnt_fives--;
                    cnt_tens++;
                }
                else return false;
            } else{
                if(cnt_tens > 0){
                    cnt_tens--;
                    if(cnt_fives > 0){
                        cnt_fives--;
                        cnt_twenties++;
                    }
                    else return false;
                } else{
                    if(cnt_fives >= 3){
                        cnt_fives -= 3;
                        cnt_twenties++;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};