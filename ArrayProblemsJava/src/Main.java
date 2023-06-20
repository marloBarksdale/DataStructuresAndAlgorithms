import java.util.Arrays;

public class Main {


    public static void main(String[] args) {


        int[] array = {2, 4, 6, 9, 13, 45, 35, 34, 23};
String s = "hello";
s.charAt(3);

        System.out.println(Arrays.toString(array));
        moveEvenNumbersToTheLeft(array);



    }


    public static void moveEvenNumbersToTheLeft(int[] array) {


        int nextEven = 0;
        int nextOdd = array.length - 1;


        while (nextEven < nextOdd) {

            System.out.println(Arrays.toString(array));
            if (array[nextEven] % 2 == 0) {
                nextEven++;
            } else {

                int temp = array[nextEven];
                array[nextEven] = array[nextOdd];
                array[nextOdd--] = temp;
            }
        }
        System.out.println(Arrays.toString(array));
    }
}

