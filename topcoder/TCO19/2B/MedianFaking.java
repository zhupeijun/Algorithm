import java.util.*;
import java.math.*;
import static java.lang.Math.*;

class Node implements Comparable<Node> {
	public int value;
	public int index;

	public Node(int value, int index) {
		this.value = value;
		this.index = index;
	}

	@Override
	public int compareTo(Node o) {
		return value - o.value;
	}
}

public class MedianFaking {
	
	public int[] minimize(int F, int M, int[] data, int goal) {
		List<Node> nodes = new ArrayList<>();
		for (int i = 0; i < data.length; ++i) {
			nodes.add(new Node(data[i], i / M));
		}

		Collections.sort(nodes);

		int N = F * M;
		int mid = (N - 1) / 2;
		int x = 0, y = 0;
		if (nodes.get(mid).value > goal) {
			int[] count = new int[1005];
			int total = 0;
			for (int j = 0; j < N; ++j) {
				if (nodes.get(j).value > goal) {
					++count[nodes.get(j).index];
					++total;
				}
			}
			Arrays.sort(count);
			y = total - (N - mid - 1);
			int cur = 0;
			for (int i = 1004; i >= 0; --i) {
				cur += count[i];
				++x;
				if (cur >= y) {
					break;
				}
			}
		} else if (nodes.get(mid).value < goal) {
			int[] count = new int[1005];
			int total = 0;
			for (int j = 0; j < N; ++j) {
				if (nodes.get(j).value < goal) {
					++count[nodes.get(j).index];
					++total;
				}
			}
			Arrays.sort(count);
			y = total - mid;
			int cur = 0;
			for (int i = 1004; i >= 0; --i) {
				cur += count[i];
				++x;
				if (cur >= y) {
					break;
				}
			}
		}
		return new int[] {x, y};
	}
}
