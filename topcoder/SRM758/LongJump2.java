import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class LongJump2 {
    public int countNewLeaders(int N, int[] jumpLengths) {
        int update = 1;
        int leader = 0;
        for (int i = 1; i < jumpLengths.length; ++i) {
            boolean needUpdate = true;
            for (int j = 0; j < i; ++j) {
                if (jumpLengths[i] <= jumpLengths[j]) {
                    needUpdate = false;
                    break;
                }
            }
            if (needUpdate) {
                int newLeader = i % N;
                if (leader != newLeader) {
                    leader = newLeader;
                    ++update;
                }
            }
        }
        return update;
    }
}
