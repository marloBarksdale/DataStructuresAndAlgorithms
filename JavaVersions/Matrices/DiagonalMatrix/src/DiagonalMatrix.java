public class DiagonalMatrix {


    private final int[] matrix;


    public DiagonalMatrix(int x) {

        matrix = new int[x];

    }

    public void set(int i, int j, int x) {


        if (i == j) {

            matrix[i - 1] = x;
        }
    }


    public int get(int i, int j) {
        if (i == j) {
            return matrix[i - 1];
        } else {
            return 0;
        }
    }


    public void display() {

        for (int i = 0; i < matrix.length; i++) {


            for (int j = 0; j < matrix.length; j++) {

                if (i == j) {
                    System.out.print(matrix[i] +" ");
                } else {
                    System.out.print(0 + " ");
                }
            }

            System.out.println("\n");
        }
    }


}
