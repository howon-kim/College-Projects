/**
 * Lab 11.4
 * Extra Credit
 * ThreadRunner file
 * @author HWKIM
 */

package teamd_lab114;

import java.util.Random;

public class ThreadRunner extends Thread
{
    private final String name;
    private final int rest;
    private final int speed;
    private int location = 0;
    private static boolean finish = true;


    
    public ThreadRunner(String Name, int Rest, int Speed) throws Exception
    {
        if (Rest > 100 || Rest <0)
            throw new Exception("Rest value should be from 0 to 100.");

        if (Speed < 0)
            throw new Exception("Value of speed should be positive number.");

        name = Name;
        rest = Rest;
        speed = Speed;
    }

    public String getRunnerName()
    {
        return name;
    }
    
    public int getLocation()
    {
        return location;
    }
    
    @Override
    public void run()
    {
        while( location < 1000 && finish )
        {
            int r = new Random().nextInt(100);
            if (r > rest) 
            {
                location += speed;
                System.out.println(getRunnerName() + " : " + getLocation());
            }

            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println("Error during the run method");
                e.printStackTrace();
                System.exit(0);
            }
        }
        finished();
    }   
    
    public void finished()
    {
        finish = false;
        if(getLocation() >= 1000){
            System.out.print(getRunnerName() + ": I finished!\n\n");
            System.out.print("The race is over! The " + getRunnerName() + " is the winner.\n\n");
        }
        else{
            System.out.print(getRunnerName() + ": You beat me fair and square.\n\n");
        }
    }
}