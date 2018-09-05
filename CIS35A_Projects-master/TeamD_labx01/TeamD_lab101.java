/*
    Write an application that allows the user to choose insurance options in JCheckBoxes. 
    Use a ButtonGroup to allow the user to select only one of two insurance types-HMO (health maintenance organization) 
    or PPO (preferred provider organization). 
    Use regular (single) JCheckBoxes for dental insurance and vision insurance options; 
    the user can select one option, both options, or neither option. 
    As the user selects each option, display its name and price in a text field; 
    the HMO costs $200 per month, the PPO costs $600 per month, 
    the dental coverage adds $75 per month, and the vision care adds $20 per month. 
    When a user deselects an item, make the text field blank.
 */
package teamd_lab101;

import javax.swing.*;
import java.awt.event.*;

/**
 * Lab 10.1
 * @author HWKIM
 */

public class TeamD_lab101 {
    
    public static void main(String[] args) {
        // Variables
        JFrame frame = new JFrame("Insurance");
        JPanel pane = new JPanel();
        JPanel pane2 = new JPanel();
        
        JCheckBox HMO = new JCheckBox("HMO", false);
        JCheckBox PPO = new JCheckBox("PPO", false);
        JCheckBox Dental = new JCheckBox("Dental", false);
        JCheckBox Vision = new JCheckBox("Vision", false);
         
        ButtonGroup group = new ButtonGroup();
        group.add(HMO);
        group.add(PPO);
        
        final JTextField description = new JTextField(22);
        description.setEditable(false);
        
        // Properties
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 100);
        frame.setResizable(false);
        

        // Add properties
        pane.add(HMO);
        pane.add(PPO);
        pane.add(Dental);
        pane.add(Vision);
        pane.add(description);
        frame.add(pane);
        frame.add(pane);
        
        // Event properties
        HMO.addItemListener(new ItemListener(){
            @Override
            public void itemStateChanged(ItemEvent event)
            {
                if(event.getStateChange() == ItemEvent.SELECTED){
                    description.setText("hmo $200");
                }
                else{
                description.setText("");
                }
            } 
        });
        
        PPO.addItemListener(new ItemListener(){
            @Override
            public void itemStateChanged(ItemEvent event)
            {
                if(event.getStateChange() == ItemEvent.SELECTED){
                    description.setText("ppo $600");
                }
                else{
                description.setText("");
                }
            } 
        });
       Dental.addItemListener(new ItemListener(){
            @Override
            public void itemStateChanged(ItemEvent event)
            {
                if(event.getStateChange() == ItemEvent.SELECTED){
                    description.setText("dental $75 additional");
                }
                else{
                description.setText("");
                }
            } 
        });
       Vision.addItemListener(new ItemListener(){
            @Override
            public void itemStateChanged(ItemEvent event)
            {
                if(event.getStateChange() == ItemEvent.SELECTED){
                    description.setText("vision $20 additional");
                }
                else{
                description.setText("");
                }
            } 
        });
        frame.setVisible(true);
    }
}
