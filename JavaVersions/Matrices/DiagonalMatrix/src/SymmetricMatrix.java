public class SymmetricMatrix extends LowerTriangularMatrix{




    public SymmetricMatrix(int n){

        super(n);

    }


    @Override
    public boolean add(int i, int j, int x) {
        if(j>i){

            int temp =i;
            i=j;
            j=temp;

        }

        return super.add(i, j, x);
    }


    @Override
    public int get(int i, int j) {

        if(j>i){

            int temp =i;
            i=j;
            j=temp;

        }

        return super.get(i, j);
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
