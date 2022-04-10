
class Example{
    public static void main(String[] args){
        // binary search (works only on sorted array)
        int[] ARRAY  = {2, 10, 34, 56, 76};
        int x = 34;

        binarySearch(ARRAY, x);
    }

    public static void binarySearch(int array[], int x){
        int low = 0;
        int high = array.length-1;
        int mid = (low + high) / 2;

        while(low <= high){
            
            if(x == array[mid]){
                System.out.println("Element Found");
                return;
            }

            if(x > array[mid]){
                low = mid+1;
                mid = (low + high)/2;
            }else{
                high = mid - 1;
                mid = (low + high)/2;
            }

        }

        System.out.println("Element Not Found");
        
    }
}