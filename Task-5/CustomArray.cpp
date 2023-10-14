package ArrayLineraDataStructure;

public class CustomArray {

    private int[] items;
    private int currentIndex ;
    public CustomArray(int initialSize){
        this.items = new int[initialSize];
        this.currentIndex = 0;
    }

    public void customInsert(int value){
        if (currentIndex == items.length){
            int[] temp = new int[currentIndex * 2];
            for (int i = 0; i < currentIndex; i++) {
                temp[i] = items[i];
            }
            items = temp;
        }
        this.items[currentIndex] = value;
        currentIndex++;
    }

    public int findIndexOf(int value){
        for (int i = 0; i < this.currentIndex; i++) {
            if(value == this.items[i]) return i;
        }
        return -1;
    }

    public void customRemoveAt(int index){
        if(index >= this.currentIndex)
            throw new IllegalArgumentException("Out of Index");
        for (int i = index; i < this.currentIndex-1; i++) {
            this.items[i] = this.items[i+1];
        }
        currentIndex--;
        this.items[currentIndex] = 0;
    }

    public int maxNumber(){
        int result = this.items[0];
        for (int i = 1; i < this.currentIndex; i++) {
            if (this.items[i] > result){
                result = this.items[i];
            }
        }
        return result;
    }
    public int minNumber(){
        int result = this.items[0];
        for (int i = 1; i < this.currentIndex; i++) {
            if (this.items[i] < result){
                result = this.items[i];
            }
        }
        return result;
    }

    public void reverse(){
        int cache;
        for (int i = 0; i < this.currentIndex/2; i++) {
            cache = this.items[currentIndex-i-1];
            this.items[currentIndex-i-1] = this.items[i];
            this.items[i] = cache;
        }
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append("[");
        for (int i= 0 ; i < currentIndex ; i++) {
            str.append(this.items[i]).append(", ");
        }
        str.append("\b").append("\b").append("]");
        return str.toString();
    }


}
