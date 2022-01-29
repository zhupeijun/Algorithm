package main

import "fmt"

func euler(n int) int {
	res, a := n, n
	for i := 2; i*i <= a; i += 1 {
		if a%i == 0 {
			res = res / i * (i - 1)
			for a%i == 0 {
				a = a / i
			}
		}
	}

	if a > 1 {
		res = res / a * (a - 1)
	}
	return res
}

func main() {
	var ans int64 = 0

	for i := 2; i <= 1000000; i += 1 {
		ans += int64(euler(i))
	}

	fmt.Println(ans)
}
