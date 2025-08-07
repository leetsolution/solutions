class Solution {
public:
    int countPoints(string rings) {
        int count = 0;
        bool rods[10][3];
        for(int i = 0; i < 10; i++){
            rods[i][0] = false;
            rods[i][1] = false;
            rods[i][2] = false;
        }

        for(int i = 0; i < rings.length(); i += 2){
            char color = rings[i];
            int rod = rings[i+1] - '0';

            if(color == 'R'){
                rods[rod][0] = true;
            } else if(color == 'G'){
                rods[rod][1] = true;
            } else {
                rods[rod][2] = true;
            }
        }

        for(int i = 0; i < 10; i++){
            if(rods[i][0] && rods[i][1] && rods[i][2]){
                count++;
            }
        }

        return count;
    }
};