
class Node{
    int val;
    Node next;

    Node(int val){
        this.val = val;
        this.next = null;
    }
}

public class IntersectionOfTwoSortedLinkedLists {
    public static void main(String[] args) {
        
        Node head1 = new Node(1);
        head1.next = new Node(2);
        head1.next.next = new Node(2);
        head1.next.next.next = new Node(3);
        head1.next.next.next.next = new Node(4);
        
        Node head2 = new Node(2);
        head2.next = new Node(2);
        head2.next.next = new Node(2);
        head2.next.next.next = new Node(4);
        
        Node result = intersection(head1, head2);
        
        Node curr = result;
        
        while (curr != null) {
            System.out.print(curr.val + " -> ");
            curr = curr.next;
        }
        
        System.out.println("null");
    }

    public static Node intersection(Node head1, Node head2){

        if(head1 == null || head2 == null){
            return null;
        }

        Node dummyNode = new Node(-1);
        Node curr = dummyNode;

        Node temp1 = head1;
        Node temp2 = head2;

        while(temp1 != null && temp2 != null){

            if(temp1.val == temp2.val){
                curr.next = new Node(temp1.val);
                curr = curr.next;
                temp1 = temp1.next;
                temp2 = temp2.next;
            }
            else if(temp1.val < temp2.val){
                temp1 = temp1.next;
            }
            else{
                temp2 = temp2.next;
            }
        }

        return dummyNode.next;
    }
}
