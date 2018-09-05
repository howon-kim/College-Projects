/*
    The user enters test scores one at a time and then clicks the Enter Score button.
    For each entered score, the application adds one to the number of scores, calculates the average score,
    and determines what the best score is so far. 
    Then, it displays the number of scores, average score, and best score in the three disabled text fields.
    The user can click the Clear button to reset everything to zero.
    When the user closes the frame or clicks the Close button, the application exits.
 */

import java.awt.*;
import java.awt.event.*;
import java.text.DecimalFormat;
import javax.swing.*;
import java.util.ArrayList;

/**
 * Final Exam
 * StudentScoresApp
 * @author HWKIM
 */

public class StudentScoresApp {
    public static void main(String[] args) 
    {
      StudentScoresFrame window = new StudentScoresFrame();
      window.setVisible(true);
    }
}

class StudentScoresFrame extends JFrame
{
    public StudentScoresFrame()
    {
        super("Test Scores");
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        JPanel panel = new StudentScoresPanel();
        this.add(panel);
        this.pack();
    }
}


class StudentScoresPanel extends JPanel implements ActionListener
{
        
    // Label
    public JLabel testScore = new JLabel("Test score:");
    public JLabel numScore = new JLabel("Number of scores:");
    public JLabel avgScore = new JLabel("Average score:");
    public JLabel bestScore = new JLabel("Best score:");
    
    
    // TextField
    public JTextField testScoreText = new JTextField(12);
    public JTextField numScoreText = new JTextField(12);
    public JTextField avgScoreText = new JTextField(12);
    public JTextField bestScoreText = new JTextField(12);
      
    
    // Buttons
    public JPanel button = new JPanel();
    public JButton enter = new JButton("Enter Score");
    public JButton clear = new JButton("Clear");
    public JButton exit = new JButton("Exit");
    
    
    // Data
    public ArrayList<Double> scores = new ArrayList<>();
    public int numScores = 0;
    public double avgScores = 0.0;
    public double sumScores = 0.0;
    public double bestScores = 0.0;
    
    
    StudentScoresPanel(){
        
        // Label Properties
        testScore.setFont(new Font("default", Font.BOLD,12));
        numScore.setFont(new Font("default", Font.BOLD,12));
        avgScore.setFont(new Font("default", Font.BOLD,12));
        bestScore.setFont(new Font("default", Font.BOLD,12));
        
        // TextField Properties
        testScoreText.setEditable(true);
        numScoreText.setEditable(false);
        avgScoreText.setEditable(false);
        bestScoreText.setEditable(false);
       
        
        // Layout Setting
        // Grid Layout
        setLayout(new GridBagLayout());
        Insets labelInsets = new Insets(1,5,1,5);
        Insets buttonInsets = new Insets(100,5,5,5);
        add(testScore, getConstraints(0,1,1,1, GridBagConstraints.EAST, labelInsets));
        add(testScoreText, getConstraints(1,1,1,1, GridBagConstraints.WEST, labelInsets));
        add(numScore, getConstraints(0,2,1,1, GridBagConstraints.EAST, labelInsets));
        add(numScoreText, getConstraints(1,2,1,1, GridBagConstraints.WEST, labelInsets)); 
        add(avgScore, getConstraints(0,3,1,1, GridBagConstraints.EAST, labelInsets));
        add(avgScoreText, getConstraints(1,3,1,1, GridBagConstraints.WEST, labelInsets));        
        add(bestScore, getConstraints(0,4,1,1, GridBagConstraints.EAST, labelInsets));
        add(bestScoreText, getConstraints(1,4,1,1, GridBagConstraints.WEST, labelInsets));
                
        button.add(clear);
        button.add(exit);
        add(enter, getConstraints(0,5,1,1, GridBagConstraints.CENTER,buttonInsets));
        add(button,getConstraints(1,5,1,1, GridBagConstraints.CENTER,buttonInsets));
        
        
        // ActionListener
        enter.addActionListener(this);
        clear.addActionListener(this);
        exit.addActionListener(this);

    }


private GridBagConstraints getConstraints(int gridx, int gridy, int gridwidth, int gridheight, int anchor, Insets insets)
    {
        GridBagConstraints c = new GridBagConstraints();
        // Common Value
        c.ipadx = 0;
        c.ipady = 0;
        
        // Custom Value
        c.gridx = gridx;
        c.gridy = gridy;
        c.gridwidth = gridwidth;
        c.gridheight = gridheight;
        c.anchor = anchor;
        c.insets = insets;

        return c;
    }


    @Override
    public void actionPerformed(ActionEvent event) {
        Object source = event.getSource();
        DecimalFormat df = new DecimalFormat("#.###");
		
        if(source == enter)
        {
            scores.add(Double.parseDouble(testScoreText.getText()));
            sumScores += scores.get(numScores);
            if(bestScores <= scores.get(numScores)) bestScores = scores.get(numScores);
                
            numScores++;
            avgScores = sumScores / numScores;
            numScoreText.setText(String.valueOf(numScores));
            avgScoreText.setText(String.valueOf(df.format(avgScores)));
            bestScoreText.setText(String.valueOf(df.format(bestScores)));
            
        }
        else if(source == clear)
        {
            scores.clear();
            numScores = 0;
            sumScores = 0;
            bestScores = 0;
            avgScores = 0;
            
            numScoreText.setText("");
            avgScoreText.setText("");
            bestScoreText.setText("");
            testScoreText.setText("");               
        }
        else if(source == exit)
        {
            System.exit(0);
        }
    }
}
