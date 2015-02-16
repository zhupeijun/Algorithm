package main

import (
  "fmt"
  "sort"
  "strconv"
  "os"
  "bufio"
)

func max(a, b int) int {
  if a > b { return a
  } else { return b }
}

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
  sc.Scan()
  v, _ := strconv.Atoi(sc.Text())
  return v
}

func main() {
  sc.Split(bufio.ScanWords)
  var t = nextInt()
  for t > 0 {
    t--
    var n = nextInt()
    a := make([]int, n)
    for i := 0; i < n; i++ {
      a[i] = nextInt()
    }
    sort.Ints(a)
    var maxv, cur int = 1, 1
    for i := 1; i < n; i++ {
      if a[i] != a[i - 1] {
        cur = 1
      } else {
        cur++
      }
      maxv = max(maxv, cur)
    }
    fmt.Printf("%d\n", n - maxv);
  }
}
