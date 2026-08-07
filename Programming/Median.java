package Programming;

import java.util.PriorityQueue;

// Approach - We maintain two heaps - max heap (for smaller half of numbers) and min heap (for larger half of numbers). After every insertion,
//            we rebalance so that the median is at the top of the heaps.

// Time Complexity
// insert - O(log n), for n element - O(n log n)
// getMedian() - O(1)

// Space Complexity - O(n)

class RunningMedian {

    PriorityQueue<Integer> minHeap;
    PriorityQueue<Integer> maxHeap;

    RunningMedian() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>((a, b) -> b - a);
    }

    void insert(int num) {

        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.add(num);
        } else {
            minHeap.add(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.add(maxHeap.poll());
        }

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.add(minHeap.poll());
        }

    }

    float getMedian() {

        if (maxHeap.isEmpty()) {
            return 0.0f;
        }

        if (maxHeap.size() == minHeap.size()) {
            float ans = (float) (maxHeap.peek() + minHeap.peek()) / 2.0f;
            return ans;
        }

        return (float) maxHeap.peek();

    }
}

public class Median {
    public static void main(String[] args) {

        RunningMedian m  = new RunningMedian();
        int[] stream = { 5, 2, 10, 4, 8, 20, 1 };

        for (int num : stream) {
            m.insert(num);
            System.out.printf("Inserted: %d | Median: %.2f%n", num, m.getMedian());
        }
    }
}