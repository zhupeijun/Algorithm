package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt64() int64 {
    sc.Scan()
    v, _ := strconv.ParseInt(sc.Text(), 10, 64)
    return v
}

func main() {
    sc.Split(bufio.ScanWords)
    var t = nextInt64()
    for t > 0 {
        t--
        var n = nextInt64()
        var s = nextInt64()
        var sum int64 = 0
        var i int64 = 1
        for ; i <= n; i++ {
            if sum + i + (n - i) > s {
                break
            } else {
                sum += i
            }
        }
        fmt.Println(n - i + 1)
    }
}
