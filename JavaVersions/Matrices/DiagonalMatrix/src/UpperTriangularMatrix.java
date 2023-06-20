public class UpperTriangularMatrix {




    private int[] array;
    private int n;

    public UpperTriangularMatrix(int n) {

        this.n = n;
        array = new int[(n * (n + 1)) / 2];
    }


    public boolean add(int i, int j, int x) {

        if (i <= j) {

            array[(n * (i - 1)-((i-2)*(i-1)/ 2)) + (j - i)] = x;
            return true;
        }

        return false;
    }

    public int get(int i, int j) {



        if (i <= j) {
            return array[(n * (i - 1)-((i-2)*(i-1)/ 2)) + (j - i)];
        } else {
            return 0;
        }
    }

    public void fill() {

        int x = 1;

        for (int i = 0; i < array.length; i++) {



              array[i]=x++;


        }


    }

    public void display() {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {



                System.out.printf( "%02d ",get(i+1,j+1));


            }

            System.out.print("\n");

        }

    }

}
