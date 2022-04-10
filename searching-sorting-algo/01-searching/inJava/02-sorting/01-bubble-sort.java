
class Example{
    public static void main(String[] args){
        // bubble sort 
        int ARRAY[] = {50, 40, 30, 20, 10};

        bubbleSort(ARRAY);

        for(int i=0; i<ARRAY.length; i++){
            System.out.print(ARRAY[i] + " ");
        }
    }

    public static void bubbleSort(int array[]){
        int size = array.length;
        for(int i=0; i<size-1; i++){
            for(int j=0; j<size-1-i; j++){
                // for ascending order '>'
                // for descending order '<'
                if(array[j] > array[j+1]){
                    int temp = array[j];
                    array[j] =  array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
}