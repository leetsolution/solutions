import java.util.*;
class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int currentPos = 0;
        for(String command : commands){
            if(command.equals("RIGHT")){
                currentPos++;
            } else if(command.equals("LEFT")){
                currentPos--;
            } else if(command.equals("UP")){
                currentPos -= n;
            } else {
                currentPos += n;
            }
        }
        return currentPos;
    }
}