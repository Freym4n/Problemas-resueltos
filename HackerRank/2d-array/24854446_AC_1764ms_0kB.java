import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the hourglassSum function below.
    static int hourglassSum(int[][] arr) {
        long max = Long.MIN_VALUE;
        for (int l = 1; l < 5; l++) {
            for (int r = 1; r < 5; r++) {
                max = Math.max(max, sum(l,r,arr));
            }
        }
        
        return (int)max;

    }

   static long sum(int x,int y, int arr[][]) {
        int dx[] = {1,1,1,-1,-1,-1};
        int dy[] = {-1,0,1,1,0,-1};
        int x1,y1;
        long result = arr[x][y];
        for (int i = 0; i < 6; i++) {
            x1 = x + dx[i];
            y1 = y +  dy[i];
            result += arr[x1][y1];
        }
        return result;
    }
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int result = hourglassSum(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
