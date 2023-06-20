public class Main {

    public static void main(String[] args) {




        LowerTriangularMatrix matrix = new LowerTriangularMatrix(6);
        UpperTriangularMatrix matrix2 = new UpperTriangularMatrix(6);
        SymmetricMatrix matrix13 = new SymmetricMatrix(6);



        matrix.fill();

        matrix2.fill();
        matrix13.fill();
        
//        matrix.display();
        System.out.println();
        matrix2.display();
        System.out.println();
//        matrix13.display();


    }
}
