package main

import (
    "fmt"
)

func main() {
    var n, m int
    fmt.Scanf("%d %d", &n, &m)

    for i := 0; i < n; i++ {
        if i & 1 == 0 {
            for j := 0; j < m; j++ {
                fmt.Printf("#")
            }
            fmt.Println()
        } else {
            for j := 0; j < m; j++ {
                if i % 4 == 1 && j == m - 1 {
                    fmt.Printf("#")
                } else if i % 4 == 3 && j == 0 {
                    fmt.Printf("#")
                } else {
                    fmt.Printf(".")
                }
            }
            fmt.Println()
        }
    }
}
