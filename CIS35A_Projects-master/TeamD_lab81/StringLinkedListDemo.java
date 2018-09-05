/*
 Revise the class StringLinkedList (from the lecture) so that it can add and remove items from the end of the list.

    public void addANodeToEnd(String addData)
    public void deleteLastNode()

 Add the following to StringLinkedListDemo.java:
 */

/**
 * Lab 8.1
 * @author HWKIM
 */

public class StringLinkedListDemo {
       public static void main(String[] args) {
            StringLinkedList list = new StringLinkedList();
            list.addANodeToStart("One");
            list.addANodeToStart("Two");
            list.addANodeToStart("Three");
            System.out.println("List has " + list.length() + " entries.");
            list.showList();
            if (list.onList("Three"))
                    System.out.println("Three is on list.");
            else System.out.println("Three is NOT on list.");
            list.deleteHeadNode();
            if (list.onList("Three"))
                    System.out.println("Three is on list.");
            else System.out.println("Three is NOT on list.");
            list.deleteHeadNode();
            list.deleteHeadNode();
            System.out.println("Start of list:");
            list.showList();
            System.out.println("End of list");
            list.addANodeToEnd("1");
            System.out.println("\nPut a string at the end of the list ");
            System.out.println("Start of list:");
            list.showList();
            System.out.println("End of list.");

            list.addANodeToEnd("2");
            list.addANodeToEnd("2");
            list.addANodeToEnd("2");
            list.addANodeToEnd("3");
            System.out.println("\nPut three 2's  and a 3 at the end of the list ");
            System.out.println("Start of list:");
            list.showList();
            System.out.println("End of list.");

            list.deleteLastNode();
            System.out.println("\nRemoved a string from the end of the list ");
            System.out.println("Start of list:");
            list.showList();
            System.out.println("End of list.");

            list.deleteLastNode();
            list.deleteLastNode();
            list.deleteLastNode();
            System.out.println("\nRemoved three strings from the end of the list ");
            System.out.println("Start of list:");
            list.showList();
            System.out.println("End of list.");

            list.deleteLastNode();
            System.out.println("\nRemoved a string from the end of the list ");
            System.out.println("Start of list:");
            list.showList();
            System.out.println("End of list.");
    }
}
