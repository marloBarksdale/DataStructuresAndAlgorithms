import java.util.Scanner;

public class StringPermutations {

    static char[] results;
    static int[] availability;

    public static void main(String[] args) {


        Scanner scanner = new Scanner(System.in);

        String word = scanner.nextLine();


        char[] characters = word.toCharArray();

        results = new char[characters.length];
        availability = new int[characters.length];

        perm2(characters, 0);
        System.out.println("-------------");
        perm(characters,0);
    }


    public static void perm(char[] s, int l) {


        if (l == s.length) {
            System.out.println(new String(results));

        } else {


            for (int i = 0; i < s.length; i++) {

                if (availability[i] == 0) {
                    availability[i] = 1;

                    results[l] = s[i];

                    perm(s, l + 1);

                    availability[i] = 0;

                }
            }
        }


    }


    public static void perm2(char[] s, int l) {


        if (l == s.length) {

            System.out.println(new String(s));
        } else {

            for (int i = l; i < s.length; i++) {


                swap(s, i, l);
                perm2(s, l + 1);
                swap(s, i, l);

            }

        }

    }


    public static void swap(char[] s, int i, int j) {


        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

    }

}
