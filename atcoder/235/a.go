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

	var x int
	scanf("%d", &x)
	a, b, c := x/100, x/10%10, x%10
	ans := a*100 + a*10 + a + b*100 + b*10 + b + c*100 + c*10 + c
	printf("%d\n", ans)
}
