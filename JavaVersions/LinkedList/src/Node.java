import java.util.HashSet;

public class Node {


    Node next = null;
    int data;


    public Node(int d) {
        data = d;
    }


    Node append(int d) {
        Node end = new Node(d);

        Node n = this;

        while (n.next != null) {
            n = n.next;
        }

        n.next = end;
        return end;
    }


    void display() {

        Node n = this;
        HashSet<Node> seen = new HashSet<>();

        while (n != null) {
            if (seen.contains(n)) {
                break;
            } else {
                seen.add(n);
            }
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println();

    }


    void removeDups() {


        HashSet<Integer> set = new HashSet<>();

        Node prev = null;
        Node n = this;


        while (n != null) {
            if (set.contains(n.data)) {

                prev.next = n.next;
            } else {
                set.add(n.data);
                prev = n;
            }

            n = n.next;
        }

    }


    Node getNode(int c) {


        Node n = this;

        for (int i = 2; i <= c; i++) {


            if (n.next == null) {
                return n;
            }
            n = n.next;

        }

        return n;
    }


    void deleteMiddle(Node c) {

        if (c == null || c.next == null) {
            return;
        }


        Node next = c.next;

        c.data = next.data;

        c.next = next.next;

    }


    int printNthToLast(Node n, int k) {


        if (n == null) {
            return 0;
        }


        int index = printNthToLast(n.next, k) + 1;

        if (index == k) {
            System.out.println(n.data);
        }
        return index;


    }


    Node printNthToLast(int k) {


        Node fast = this;
        Node slow = this;

        for (int i = 0; i < k; i++) {

            if (fast != null) {
                fast = fast.next;
            } else {
                return null;
            }
        }


        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        return slow;
    }


    public Node reverseNToK(int n, int k) {


        Node dummy = new Node(0);
        dummy.next = this;
        Node sublistHead = dummy;

        int a = 1;
        while (a++ < n) {
            sublistHead = sublistHead.next;
        }


        Node current = sublistHead.next;


        while (n++ < k) {


            Node temp = current.next;

            current.next = temp.next;

            temp.next = sublistHead.next;
            sublistHead.next = temp;
        }


        return dummy.next;

    }


    public Node detectCycle() {

        Node fast = this, slow = this;


        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;


            if (slow == fast) {
                break;
            }
        }

        if (slow == null || fast == null) return null;

        slow = this;


        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }

        return slow;


    }


    public void removeDupsFromSortedList() {


        Node current = this;

        while (current != null && current.next != null) {


            if (current.data == current.next.data) {

                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
    }


    public boolean isPalindrome() {

        Node front = this;


        return checkPalindrome(front, front);
    }


    public boolean checkPalindrome(Node front, Node l) {


        if (l != null) {


            if (!checkPalindrome(front, l.next)) return false;
            Node current = l;
            while (current.next != null) {
                front = front.next;
                current = current.next;
            }
            if (l.data != front.data) return false;

        }

        return true;
    }



    public void oddEvenMerge(){
        Node odd = this, even = odd.next, evenHead = even;



        while(even!=null && even.next!=null){

            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;

        }


        odd.next = evenHead;





    }

}




