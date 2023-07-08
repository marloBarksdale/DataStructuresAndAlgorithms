import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {


        List<String> res = new ArrayList<>();
        formParens(res, 0, 0, "", 3);


        System.out.println(res);

    }


    public static void formParens(List<String> res, int left, int right, String s, int n) {
        if (left == n && right == left) {
            res.add(s);
            return;
        }

        if (left < n) {
            formParens(res, left+1, right, s + "(", n);
        }

        if (right < left) {
            formParens(res, left, right+1, s + ")", n);
        }
    }


}