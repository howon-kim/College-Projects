/**
 * Team D
 * Lab 8.1
 * @author HWKIM
 */
public class StringLinkedList {
	private ListNode head;
        
	public StringLinkedList() {
		head = null;
	}
        
	/** Displays the data on the list. */
	public void showList() {
		ListNode position = head;
		while (position != null) {
			System.out.println(position.getData()); position = position.getLink();
		}
	}
        
	/** Returns the number of nodes on the list. */
	public int length() {
		int count = 0;
		ListNode position = head;
		while (position != null) {
			count++; position = position.getLink();
		}
		return count;
	}
        
	/** Adds a node containing the data addData at the start of the list. */
	public void addANodeToStart(String addData) {
            head = new ListNode(addData, head);
	}
        
        public void addANodeToEnd(String addData) {
          
            if(head == null) {
                addANodeToStart(addData);
            }
            else {
                ListNode tail = new ListNode(addData, null);
                ListNode current = head;
                
                while(current.getLink() != null){
                    current = current.getLink();
                }
                current.setLink(tail);
            }
        }
        
	/** Deletes the first node on the list. */
	public void deleteHeadNode() {
		if (head != null) head = head.getLink();
		else {
			System.out.println("Deleting from an empty list.");
			System.exit(0);
		}
	}
        
        
        public void deleteLastNode() {
            
            ListNode previous;
            ListNode current;
            
            if(head != null){
                if(head.getLink() == null) head = null;
                else {
                    previous = head;
                    current = head.getLink();
                    
                    while(current.getLink() != null){
                        previous = current;
                        current = current.getLink();
                    }
                    
                    previous.setLink(null);
                }
            }
        }
        

        
	/** Sees whether target is on the list. */
	public boolean onList(String target) {
		return find(target) != null;
	}
	//Returns a reference to the first node containing the
	//target data. If target is not on the list, returns null.
        
	private ListNode find(String target) {
		boolean found = false;
		ListNode position = head;
		while ((position != null) && !found) {
			String dataAtPosition = position.getData();
			if (dataAtPosition.equals(target)) found = true;
			else position = position.getLink();
		}
	return position;
	}
}
