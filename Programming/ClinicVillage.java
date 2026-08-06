package Programming;

import java.util.PriorityQueue;
import java.util.Scanner;

class Pair{

    int villagePopulation;
    int clinics;

    Pair(int villagePopulation, int clinics){
        this.villagePopulation = villagePopulation;
        this.clinics = clinics;
    }
}

public class ClinicVillage{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] arr = new int[n];

        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        int k = sc.nextInt();

        double ans = minimizeLoad(arr, n, k);
        System.out.printf("%.2f",ans);

        sc.close();
        
    }

    public static double minimizeLoad(int[] population, int n, int k){

        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> Double.compare(b.villagePopulation/b.clinics, a.villagePopulation/a.clinics));

        for(int i=0;i<n;i++){
            pq.add(new Pair(population[i], 1));
        }

        int extra = k - n;

        while (extra > 0) {
            Pair pair = pq.poll();
            pair.clinics++;
            pq.add(pair);
            extra--;
        }

        double max = 0;

        while (!pq.isEmpty()) {
            Pair pair = pq.poll();
            double load = (double) pair.villagePopulation/pair.clinics;
            max = Math.max(max,load);
        }

        return max;

    }
}