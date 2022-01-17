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

func main() {
	defer writer.Flush()

	var n int
	var cur = 0
	var fin = false
	scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		var x int
		scanf("%d", &x)
		if i == n-1 {
			scanf("\n")
		} else {
			scanf(" ")
		}

		if !fin {
			if x > cur {
				cur = x
			} else if x <= cur {
				fin = true
			}
		}
	}
	printf("%d\n", cur)
}
