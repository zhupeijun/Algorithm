package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func solve() {
	var n, m, r, c int
	scanf("%d %d %d %d\n", &n, &m, &r, &c)
	s := make([]string, n)
	for i := 0; i < n; i++ {
		scanf("%s\n", &s[i])
	}

	r--
	c--

	if s[r][c] == 'B' {
		printf("0\n")
		return
	}

	var exist = false
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if s[i][j] == 'B' {
				exist = true
				if i == r || j == c {
					printf("1\n")
					return
				}
			}
		}
	}

	if exist {
		printf("2\n")
	} else {
		printf("-1\n")
	}
}

func main() {
	defer writer.Flush()

	var t int
	scanf("%d\n", &t)
	for t > 0 {
		solve()
		t--
	}
}
