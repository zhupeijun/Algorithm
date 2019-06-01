import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class CentipedeSocks
{
    public int fewestSocks(int C, int F, int[] sockCounts)
    {
        PriorityQueue<Integer> q = new PriorityQueue<>((Integer a, Integer b) -> b - a);
        Arrays.stream(sockCounts).forEach(v -> q.add(v));    
        int total = 0;
        while (C > 1) {
            int t = q.poll();
            if (t < F) {
                return -1;
            }
            t -= F;
            total += F;
            q.add(t);
            --C;
        }
        if (q.peek() < F) {
            return -1;
        } else {
            total += Math.min(F, q.poll());
        }
        
        while (!q.isEmpty()) {
            total += (Math.min(q.poll(), F - 1));
        }
        return total;
    }
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
