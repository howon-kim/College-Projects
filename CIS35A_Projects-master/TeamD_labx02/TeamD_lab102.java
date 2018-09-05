/*
    Create an application for Paula's Portraits, a photography studio. 
    The application allows users to compute the price of a photography session. 
    Paula's base price is $40 for an in-studio photo session with one person. 
    The in-studio fee is $75 for a session with two or more subjects, and $95 for a session with a pet. 
    A $90 fee is added to take photos on location instead of in the studio. 
    Include a set of mutually exclusive check boxes to select the portrait subject 
    and another set of mutually exclusive check boxes for the session location. 
    Include labels as appropriate to explain the application's functionality.
 */

/**
 * Lab 10.2
 * @author HWKIM
 */

import java.awt.*;
import java.awt.Font;
import javax.swing.*;
import java.awt.event.*;

public class TeamD_lab102 extends JFrame implements ItemListener {
    
    final int ONE_HUMAN = 40;
    final int TWO_HUMAN = 75;
    final int PET = 95;
    final int ON_LOCATION = 90;
    final int IN_STUDIO = 0;
    int totalPrice = 0;
    
    JLabel title = new JLabel("Paula's Portraits");
    JLabel option = new JLabel("Select options");
    JLabel fee = new JLabel("Portrait fee");
    
    JCheckBox oneHuman = new JCheckBox("One human subject",false);
    JCheckBox twoHuman = new JCheckBox("Two or more human subjects",false);
    JCheckBox pet = new JCheckBox("Pet subject",false);
    JCheckBox onLocation = new JCheckBox("On location",false);
    JCheckBox inStudio = new JCheckBox("In studio",false);
    
    JTextField total = new JTextField("$0",10); 
    
    public TeamD_lab102()
    {
        super("Portrait option");
        setSize(250,280);
        setResizable(false);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	title.setFont(new Font("Arial", Font.ITALIC, 25));
        JPanel pane = new JPanel();
        
        total.setEditable(false);
        
        pane.add(title);
        pane.add(option);

        
        ButtonGroup type = new ButtonGroup();
        type.add(oneHuman);
        type.add(twoHuman);
        type.add(pet);
        ButtonGroup location = new ButtonGroup();
        location.add(onLocation);
        location.add(inStudio);
        pane.add(oneHuman);
        pane.add(twoHuman);
        pane.add(pet);
        pane.add(onLocation);
        pane.add(inStudio);
        pane.add(fee);
        pane.add(total);
        add(pane);

        oneHuman.addItemListener(this);
        twoHuman.addItemListener(this);
        pet.addItemListener(this);
        onLocation.addItemListener(this);
        inStudio.addItemListener(this);

        setVisible(true);
        
    }


    @Override
    public void itemStateChanged(ItemEvent event) {

        Object source = event.getSource();
        int select = event.getStateChange();
		
        if(source == oneHuman)
            if(select == ItemEvent.SELECTED) totalPrice += ONE_HUMAN;
            else totalPrice -= ONE_HUMAN;
        else if(source == twoHuman)
        {
            if(select == ItemEvent.SELECTED) totalPrice += TWO_HUMAN;
            else totalPrice -= TWO_HUMAN;
        }
        else if(source == pet) 
        {
            if(select == ItemEvent.SELECTED) totalPrice += PET;
            else totalPrice -= PET; 
        }
        else if(source == onLocation)
        {
            if(select == ItemEvent.SELECTED) totalPrice += ON_LOCATION;
            else totalPrice -= ON_LOCATION;
        }
        else
        {
            if(select == ItemEvent.SELECTED) totalPrice += IN_STUDIO;
            else totalPrice -= IN_STUDIO;
        }
        
                total.setText(totalPrice + ".0");        

    }	
        
    public static void main(String[] args)
    {
        TeamD_lab102 window = new TeamD_lab102();
    }
}
