package main

import "fmt"

func find(S, T []string, N, M int) (int, int) {
	for i := 0; i+M <= N; i++ {
		for j := 0; j+M <= N; j++ {
			for k := 0; k < M; k++ {
				for l := 0; l < M; l++ {
					if S[i+k][j+l] != T[k][l] {
						goto outside
					}
				}
			}
			return i + 1, j + 1
		outside:
		}
	}
	return -1, -1
}

func main() {
	var N int
	var M int
	fmt.Scan(&N)
	fmt.Scan(&M)

	S := make([]string, N)
	T := make([]string, M)

	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	for i := 0; i < M; i++ {
		fmt.Scan(&T[i])
	}

	fmt.Println(find(S, T, N, M))
}
