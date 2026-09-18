
class Node{
    int val;
    Node next;

    Node(int val){
        this.val = val;
        this.next = null;
    }
}


public class ReverseLinkedListUsingRecursion{
    public static void main(String[] args) {
        
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        
        Node newHead = reverse(head);
        
        Node curr = newHead;
        
        while (curr != null){
            System.out.print(curr.val + " -> ");
            curr = curr.next;
        }
        
        System.out.println("null");
    }

    public static Node reverse(Node head){

        if(head == null || head.next == null){
            return  head;
        }

        Node newHead = reverse(head.next);

        head.next.next = head;
        head.next = null;

        return newHead;
    }
}