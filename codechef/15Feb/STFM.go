package main

import (
    "fmt"
    "os"
    "strconv"
    "bufio"
)

const M int64 = 10000005
const N int64 = 100005

var sc = bufio.NewScanner(os.Stdin)

var p [N] int64
var sum[M] int64

func init_sum(m int64) {
    sum[0] = int64(0); cur := int64(1)
    for i := int64(1); i < M; i++ {
        cur = (cur * i) % m
        sum[i] = ((cur * i) + sum[i - 1]) % m
    }
}

func main() {
    sc.Split(bufio.ScanWords)
    sc.Scan(); n, _ := strconv.ParseInt(sc.Text(), 10, 64)
    sc.Scan(); m, _ := strconv.ParseInt(sc.Text(), 10, 64)
    init_sum(m)
    var ans = int64(0)
    for i := int64(0); i < n; i++ {
        sc.Scan();
        x, _ := strconv.ParseInt(sc.Text(), 10, 64)
        p[i] = x
        var c int64
        if p[i] & 1 != 0 {
            c = ((((p[i] + 1) / 2) % m) * (p[i] % m)) % m
        } else {
            c = (((p[i] + 1) % m) * ((p[i] / 2) % m)) % m
        }
        c = (c * (p[i] % m)) % m
        if p[i] > m {
            c = (c + sum[m]) % m
        } else {
            c = (c + sum[p[i]]) % m
        }
        ans = (ans + c) % m
    }
    fmt.Println(ans)
}
