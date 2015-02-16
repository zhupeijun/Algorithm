package main

import "fmt"

func solve(str string, start uint8) int {
  n := len(str)
  cur := start
  ans := 0
  for i := 0; i < n; i++ {
    if cur != str[i] { ans++ }
    if cur == '-' { cur = '+'
    } else { cur = '-' }
  }
  return ans
}

func min(a int, b int) int {
  if a > b { return b
  } else { return a }
}

func main() {
  var t int
  fmt.Scanf("%d", &t)
  for t > 0 {
    t--
    var str string
    fmt.Scanf("%s", &str)
    fmt.Println(min(solve(str, '-'), solve(str, '+')))
  }
}
