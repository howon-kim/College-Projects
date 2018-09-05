== Summary ==
Our team has created this application to instantiate a searching system 
by using the BST and Hashtable at the same time



== Description ==
This is a Class Searching program for Computer Science Department in De Anza.
Users can see the entire list of classes with its details
such as CRN number, course name, professor's name, room number and availability.

Based on CRN number, users can narrow down their choice and come up with one class
that they only want to see
or
they can use course numbers to check entire course's information

Also, this program provides few statistic values for
about professor,course and availability  



== Source Code ==
Class.h
	This is the main header file for BST and Hashtable.
	Thi header file contaions specific resoureces about the class object 
	such as professor's name, day, time and location.


Class.cpp
	This file has functions to display and list all the information 
	that the Class object contians in cerntian order.


BST.h
	This is another main header file for instantiating Binary Search Tree
	with each node as a class object.


HashTable.h
	This is another main header file for instantiating HashTable
	with each node as a class object.
	There are psuedorandom functions and chaining has used
	in order to maximize its efficiency.


Main.cpp
	This is a main application source file for Class Searching Application(program).



DBClass.txt
	This is a main source file for the classes in De Anza Computer Science Department



== Menu ==
| A |  Add new individual data from the input                                     
| L |  List data by CRN or Course     
	| 1 |  List data by sorted CRN                   
	| 2 |  List data by sorted Course                
	| 3 |  Go to the previous menu                                                              
| F |  Search the Data by CRN or Course  
	| 1 |  Search the CRN                            
	| 2 |  Search the Course                         
	| 3 |  Go to the previous menu                                                           
| D |  Delete Data by CRN                                                         
| R |  Read data from the text file                                               
| W |  Write data to the text file    
	| 1 |  Write file sorted by CRN                  
	| 2 |  Write file sorted by Course               
	| 3 |  Write file based on HashTable             
	| 4 |  Go to the previous menu                                                               
| S |  Statistics from the data      
	| 1 |  Current Class Status                      
	| 2 |  Instructor Statistics                     
	| 3 |  Course Statistics                         
	| 4 |  Go to the previous menu                                                              
| X |  Exit Program                                                               
