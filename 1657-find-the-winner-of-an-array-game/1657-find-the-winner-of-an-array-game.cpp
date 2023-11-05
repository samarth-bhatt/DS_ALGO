class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int winner = arr[0];
        int i=1, j=0;
        int winnerCnt = 0;
        while(i<n && winnerCnt != k){
            if(arr[i] > winner){
                winner = arr[i];
                winnerCnt = 1;
            } else winnerCnt++;
            i++;
        }
        return winner;
    }
};


/*
    <--Try-->
    // if(arr[i%n] > arr[j%n]){
            //     winner = arr[i];
            //     winnerCnt++;
            //     j++;
            // } else{
            //     winner = arr[j];
            //     swap(i, j);
            //     winnerCnt = 1;
            //     i++;
            // }
*/