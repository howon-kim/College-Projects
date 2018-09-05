/*
    Create an application with a JFrame and at least five labels that contain interesting historical facts.
    Every time the user clicks a JButton, remove one of the labels and add a different one.
 */

package teamd_lab94;
import java.awt.FlowLayout;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;

/**
 * Lab 9.4
 * @author HWKIM
 */
public class TeamD_lab94{

    public static void main(String[] args) {

        HistoricalFacts window = new HistoricalFacts();
        window.setSize(700,400);
        window.setResizable(false);
        window.setVisible(true);

        
    }

    public static class HistoricalFacts extends JFrame implements ActionListener {

        public JButton change = new JButton("Press to change fact");        
        public ArrayList<JLabel> facts = new ArrayList<>();
        public int count = 0;
       

        public HistoricalFacts(){
            super("Facts");
            facts.add(new JLabel("Jamestown, the first permanent English settlement, was founded in 1607."));
            facts.add(new JLabel("The Declaration of Independence was signed on July 4, 1776."));
            facts.add(new JLabel("The Constitution of the United States was written in 1787."));
            facts.add(new JLabel("President Thomas Jefferson purchased the Louisiana Territory from France in 1803."));
            facts.add(new JLabel("The Civil War was fought from 1861-1865."));

            setLayout(new FlowLayout());
            add(change);
            add(new JLabel("*******************************************************************************************************"));
            add(facts.get(count));

            change.addActionListener(this);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

        }

        @Override
        public void actionPerformed(ActionEvent e){

                remove(facts.get(count));
                
                                
                if(count == 4){
                    count = 0;
                }  
                else{
                    count++;
                }
               
                add(facts.get(count));
                revalidate();
                repaint();
        }
    }
    
}
