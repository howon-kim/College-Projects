/*
    Create a JFrame that uses BorderLayout. 
    Place a JButton in the center region. 
    Each time the user clicks the JButton, change the background color in one of the other regions.
 */

package teamd_lab104;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * Lab 10.4
 * @author HWKIM
 */

public class TeamD_lab104 extends JFrame implements ActionListener{
   
    JButton change = new JButton("Change");
    JPanel nPanel = new JPanel();
    JPanel wPanel = new JPanel();
    JPanel cPanel = new JPanel();
    JPanel ePanel = new JPanel();
    JPanel sPanel = new JPanel();
    int number = 0;
    
    public TeamD_lab104(){
        super("Background Color");
        setSize(400,350);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        BorderLayout layout = new BorderLayout();
        setLayout(layout);
        
        add(nPanel, BorderLayout.NORTH);
        add(wPanel, BorderLayout.WEST);
        add(cPanel, BorderLayout.CENTER);
        add(ePanel, BorderLayout.EAST);
        add(sPanel, BorderLayout.SOUTH);

              
        cPanel.add(change, BorderLayout.CENTER);
        change.addActionListener(this);
    }
    
    public static void main(String[] args) {
        TeamD_lab104 window = new TeamD_lab104();
        window.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        switch (number) {
            case 0:
                nPanel.setBackground(Color.GREEN);
                break;
            case 1:
                ePanel.setBackground(Color.MAGENTA);
                break;
            case 2:
                wPanel.setBackground(Color.ORANGE);
                break;
            case 3:
                sPanel.setBackground(Color.RED);
                break;
            default:
                nPanel.setBackground(Color.WHITE);
                ePanel.setBackground(Color.WHITE);
                wPanel.setBackground(Color.WHITE);
                sPanel.setBackground(Color.WHITE);
                break;
        }
        number++;
    }
}
