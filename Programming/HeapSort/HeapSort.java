package Programming.HeapSort;

public class HeapSort {
    public static void main(String[] args) {

        int sizes[] = { 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

        for (int n : sizes) {

            int random[] = new int[n];

            for (int i = 0; i < n; i++) {
                random[i] = (int) (Math.random() * 100000);
            }

            long start = System.nanoTime();

            heapSort(random);

            long end = System.nanoTime();

            long randomTime = end - start;

            int ascending[] = new int[n];

            for (int i = 0; i < n; i++) {
                ascending[i] = i + 1;
            }

            start = System.nanoTime();

            heapSort(ascending);

            end = System.nanoTime();

            long ascendingTime = end - start;

            int descending[] = new int[n];

            int value = n;

            for (int i = 0; i < n; i++) {
                descending[i] = value--;
            }

            start = System.nanoTime();

            heapSort(descending);

            end = System.nanoTime();

            long descendingTime = end - start;

            System.out.println("--------------------------------------------");
            System.out.println("Input Size : " + n);
            System.out.println("Random Time     : " + (randomTime / 1_000_000.0) + " ms");
            System.out.println("Ascending Time  : " + (ascendingTime / 1_000_000.0) + " ms");
            System.out.println("Descending Time : " + (descendingTime / 1_000_000.0) + " ms");

        }
    }

    static void heapSort(int[] arr) {

        buildHeap(arr);

        int n = arr.length;

        for (int i = n - 1; i > 0; i--) {

            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);

        }

    }

    static void buildHeap(int[] arr) {

        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    static void heapify(int[] arr, int n, int i) {

        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }
}
