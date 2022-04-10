import java.util.Scanner;

class Example{
    public static void main(String[] args){

        int[] ARRAY  = {10, 45, 5, 50, 2};
        int x = 2;
        linearSearch(ARRAY, x);
    }

    public static void linearSearch(int array[], int x){
        for(int i = 0; i<array.length; i++){
            if(x == array[i]){
                System.out.println("Element Found in Array");
                return;
            }
        }

        System.out.println("Element Not Found In Array");
    }
}