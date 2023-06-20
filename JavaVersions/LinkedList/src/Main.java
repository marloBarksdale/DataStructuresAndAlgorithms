import java.util.Arrays;

public class Main {
    public static void main(String[] args) {


        Node head = new Node(1);


//        head.append(5);
//        head.append(5);
        head.append(2);
        head.append(3);
        head.append(4);
        head.append(5);
        head.append(6);

//        head.append(23);
//        head.append(23);
//        head.append(23);
//        head.append(4);
//        head.append(4);
//        head.append(4);
//        head.append(287);
//        head.append(287);
//        head.append(287);
//        head.append(287);
//        head.append(5);
//        head.append(5);
//        head.append(5);
//        head.append(5);
//        head.append(234);
//        head.append(234);
//        head.append(234);
//        head.append(6943);
//        head.append(6943);
//        head.append(6943);
//        head.append(6943);

        head.display();
        System.out.println(head.isPalindrome());


        head.oddEvenMerge();
        head.display();
        head = sortList(head);


//        head.removeDupsFromSortedList();
        head.display();


    }


    public static Node sortList(Node head) {


        if (head == null || head.next == null) {
            return head;
        }


        Node mid = getMid(head);

        Node left = sortList(head);
        Node right = sortList(mid);


        return merge(left, right);

    }


    public static Node getMid(Node head) {


        Node midPrev = null;

        while (head != null && head.next != null) {

            midPrev = (midPrev == null) ? head : midPrev.next;

            head = head.next.next;
        }


        Node mid = midPrev.next;

        midPrev.next = null;

        return mid;
    }


    public static Node merge(Node left, Node right) {


        Node dummyHead = new Node(0);
        Node current = dummyHead;

        while (left != null && right != null) {

            if (left.data < right.data) {
                current.next = left;
                left = left.next;


            } else {
                current.next = right;
                right = right.next;
            }
            current = current.next;
        }

        current.next = left == null ? right : left;


        return dummyHead.next;

    }


}