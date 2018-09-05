/*
    Write an application that displays a panel containing the opening 2 sentences 
    from your favorite book. Add the 2 sentences in labels.
 */

package teamd_lab93;
import javax.swing.*;

/**
 * Lab 9.3
 * @author HWKIM
 */

public class TeamD_lab93 {
    
    public static void main(String[] args) {
        JFrame bookQuote = new JFrame("Book Quote");
                
        // Panel
        JPanel pane = new JPanel();
        
        // Label
        JLabel quote1 = new JLabel("He who controls the past controls the future.");
        JLabel quote2 = new JLabel("He who controls the present controls the past.");
        // Label -> Panel
        pane.add(quote1);
        pane.add(quote2);
        
        
        // Panel -> Frame
        bookQuote.add(pane);
        
        // Properities
        bookQuote.setSize(600,100);
        bookQuote.setResizable(false);
        bookQuote.setVisible(true);
        bookQuote.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
}