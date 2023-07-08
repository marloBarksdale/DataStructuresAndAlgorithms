import java.util.EmptyStackException;

public class Stack<T>  {




    private static class StackNode<T> {

        private T data;
        private StackNode<T> next;


        public StackNode(T data) {

            this.data = data;
        }

    }

    private StackNode<T> top;


    public T pop() {


        if (top == null) throw new EmptyStackException();


        T item = top.data;
        top = top.next;
        return item;
    }


    public void push(T val) {

        StackNode<T> r = new StackNode<T>(val);

        r.next = top;

        top = r;


    }


    public T peek() {

        if (top == null) throw new EmptyStackException();

        return top.data;

    }


    public boolean isEmpty() {

        return top == null;
    }


    public void display() {

        if (top == null)
            System.out.println("Stack is empty");


        StackNode p = top;

        while (p != null) {
            if (p.data instanceof StackWithMin.NodeWithMin) {
                System.out.print(((StackWithMin.NodeWithMin) p.data).value + " ");
            } else {
                System.out.print(p.data + " ");
            }

            p = p.next;
        }

        System.out.println();
    }


}



