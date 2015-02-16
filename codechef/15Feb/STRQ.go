//Same solution with c++
//But got TLE
package main

import (
    "bufio"
    "os"
    "strconv"
    "strings"
)

const N int = 1000005
const T int = 4

var bn[N][T]int64
var an[N][T][T]int64
var cnt[N][T]int64

var lbr = bufio.NewReaderSize(os.Stdin, N)
var lbw = bufio.NewWriterSize(os.Stdout, N)

func index(a uint8) int {
    switch a {
    case 'c':
        return 0;
    case 'h':
        return 1;
    case 'e':
        return 2;
    case 'f':
        return 3;
    default:
        return 0;
    }
}

func init_cnt(str string) {
    n := len(str)
    for i := n - 1; i >= 0; i-- {
        for k := 0; k < T; k++ {
            bn[i][k] = 0
            if i < n - 1 {
                bn[i][k] = bn[i + 1][k]
            }
        }
        idx := index(str[i])
        bn[i][idx]++
    }
    for i := 0; i < n; i++ {
        idx := index(str[i])
        for j := 0; j < T; j++ {
            for k := 0; k < T; k++ {
                an[i][j][k] = 0
                if i > 0 {
                    an[i][j][k] = an[i - 1][j][k]
                }
            }
        }
        for j := 0; j < T; j++ {
            an[i][idx][j] += bn[i][j]
            cnt[i][j] = 0
            if i > 0 {
                cnt[i][j] = cnt[i - 1][j]
            }
        }
        cnt[i][idx]++
    }
}

func readline() string {
    buf, _, _ := lbr.ReadLine()
    return string(buf)
}

func main() {
    str := readline()
    m, _ := strconv.Atoi(readline())
    init_cnt(str)
    for q := 0; q < m; q++ {
        qs := strings.Split(readline(), " ")
        ai := index(qs[0][0])
        bi := index(qs[1][0])
        l, _ := strconv.Atoi(qs[2])
        r, _ := strconv.Atoi(qs[3])
        l--; r--
        t1 := an[r][ai][bi]; t2 := cnt[r][ai]
        if l - 1 >= 0 {
            t1 -= an[l - 1][ai][bi]
            t2 -= cnt[l - 1][ai]
        }
        t3 := int64(0); n := len(str)
        if r + 1 < n {
            t3 = bn[r + 1][bi]
        }
        ans := t1 - t2 * t3
        lbw.WriteString(strconv.FormatInt(ans, 10) + "\n")
    }
    lbw.Flush()
}
