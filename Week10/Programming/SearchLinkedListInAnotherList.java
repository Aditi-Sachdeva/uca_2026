
class Node{
    int val;
    Node next;

    Node(int val){
        this.val = val;
        this.next = null;
    }
}

public class SearchLinkedListInAnotherList {
    public static void main(String[] args) {
        
        Node list1 = new Node(1);
        list1.next = new Node(2);
        
        Node list2 = new Node(1);
        list2.next = new Node(2);
        list2.next.next = new Node(1);
        list2.next.next.next = new Node(2);
        list2.next.next.next.next = new Node(3);
        list2.next.next.next.next.next = new Node(4);
        
        System.out.println(search(list1, list2) ? "Yes" : "No");
    }

    public static boolean search(Node list1, Node list2){

        if(list1 == null){
            return  true;
        }
        
        if(list2 == null){
            return false;
        }

        Node temp2 = list2;

        while(temp2 != null) {
            
            if(temp2.val == list1.val){

                Node temp1 = list1;
                Node curr = temp2;

                while(temp1 != null && curr != null && temp1.val == curr.val) {
                    temp1 = temp1.next;
                    curr = curr.next;
                }

                if(temp1 == null){
                    return true;
                }

            }

            temp2 = temp2.next;
        }

        return false;
    }
}
