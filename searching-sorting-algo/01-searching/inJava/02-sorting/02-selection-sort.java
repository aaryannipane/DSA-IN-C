
class Example{
    public static void main(String[] args){
        // selection sort
        int[] ARRAY = {50, 40, 30, 20, 10};

        selectionSort(ARRAY);

        for(int i=0; i<ARRAY.length; i++){
            System.out.print(ARRAY[i] + " ");
        }
    }

    public static void selectionSort(int array[]){
        int size = array.length;
        // selection sort
        for(int i=0; i<size-1; i++){
            for(int j = i+1; j<size; j++){
                // for ascending order
                if(array[i] > array[j]){
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}