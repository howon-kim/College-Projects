/*
    Create a JFrame and set the layout to BorderLayout. 
    In each region, place a JButton that displays the name of a classic movie that has the region name in its title. 
    For example, the east button might indicate the movie East of Eden. 
    When the user clicks the button, display the year of the movie's release and the name of one of its stars.
 */
package teamd_lab103;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 * Lab 10.3
 * @author HWKIM
 */
public class TeamD_lab103 extends JFrame implements ActionListener {
        
    JButton nButton = new JButton("North by Northwest");
    JButton wButton = new JButton("West Side Story");
    JButton cButton = new JButton("Journey to the Center of the Earth");
    JButton eButton = new JButton("East of Eden");
    JButton sButton = new JButton("South Pacific");
    
    JLabel nLabel = new JLabel("     1959,Cary Grant");
    JLabel wLabel = new JLabel("1961,Natalie Wood");
    JLabel sLabel = new JLabel("     1958,Mary Martin");
    JLabel eLabel = new JLabel("     1955,James Dean");
    JLabel cLabel = new JLabel("     1959,Pat Boone");
    
    public TeamD_lab103() {
        super("Movies");
        setSize(700,350);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setLayout(new BorderLayout());
   
        add(nButton, BorderLayout.NORTH);
        add(sButton, BorderLayout.SOUTH);
        add(eButton, BorderLayout.EAST);
        add(wButton, BorderLayout.WEST);
        add(cButton, BorderLayout.CENTER);
        
        nButton.addActionListener(this);
        sButton.addActionListener(this);
        eButton.addActionListener(this);
        wButton.addActionListener(this);
        cButton.addActionListener(this);
        
        setVisible(true);        
    }

    public static void main(String[] args) {
        JFrame.setDefaultLookAndFeelDecorated(true);
        TeamD_lab103 window = new TeamD_lab103();
    }

    @Override
    public void actionPerformed(ActionEvent event) {

        Object source = event.getSource();
		
        if(source == nButton)
        {
            nButton.setVisible(false);
            add(nLabel,BorderLayout.NORTH);
        }     
        else if(source == sButton)
        {
            sButton.setVisible(false);
            add(sLabel,BorderLayout.SOUTH);
        }
        else if(source == eButton)
        {
            eButton.setVisible(false);
            add(eLabel,BorderLayout.EAST);
        }
        else if(source == wButton)
        {
            wButton.setVisible(false);
            add(wLabel,BorderLayout.WEST);
        }
        else if(source == cButton)
        {
            cButton.setVisible(false);
            add(cLabel,BorderLayout.CENTER);
        }
    }
}
