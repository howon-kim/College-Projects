/*
    Write a program to write 100 integers created randomly into a file using binary I/O.
    Create the file if it doesn't exist. If it exists append the data to it.

    Write a program to read the data from the file above and calculate their sum. 
    Display the numbers, count and sum.
 */


package teamd_lab113;
import java.io.*;

/**
 * Lab 11.3
 * @author HWKIM
 */

public class TeamD_lab113 {

    public static void main(String[] args) throws IOException {
        
        File filename = new File("Random.dat");
        boolean append = filename.exists();
        
        try(
                FileOutputStream file = new FileOutputStream(filename,append);
                BufferedOutputStream buff = new BufferedOutputStream(file);
                DataOutputStream data = new DataOutputStream(buff);
                )
        {
            for (int i = 0; i < 100 ; i++)
            {
                data.writeInt((int)(Math.random() * 100000));
            }
            data.close();
        }
        
        try(
                FileInputStream file = new FileInputStream(filename);
                BufferedInputStream buff = new BufferedInputStream(file);
                DataInputStream data = new DataInputStream(buff);
                )
        {
            int sum = 0;
            int count = data.available() /4; // 4bytes per data
            for(int i = 0 ; i < count ; i++)
            {
                int value = data.readInt();
                System.out.print(value + " ");
                sum += value;
            }
                        
            System.out.print("\nCount is " + count + "\n\n");
            System.out.print("Total is " + sum + "\n");
            data.close();
        }
    }
    
}
