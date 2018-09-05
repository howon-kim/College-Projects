/**
 * Lab 11.4
 * Extra Credit
 * Main file
 * @author HWKIM
 */

package teamd_lab114;

import java.util.ArrayList;

public class TeamD_lab114
{
    private static final ArrayList<ThreadRunner> player = new ArrayList<>();

    public static void main(String[] args) throws Exception{
    
        player.add(new ThreadRunner("Tortoise",0,10));
        player.add(new ThreadRunner("Hare",90,100));
        
        if(player != null) {
            for (ThreadRunner s : player) {
                s.start();
            }
        }
    }
}