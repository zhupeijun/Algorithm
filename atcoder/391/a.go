package main

import "fmt"

func main() {
	var D string
	fmt.Scan(&D)

	mapping := map[string]string{
		"N":  "S",
		"S":  "N",
		"E":  "W",
		"W":  "E",
		"NE": "SW",
		"NW": "SE",
		"SE": "NW",
		"SW": "NE",
	}

	fmt.Println(mapping[D])
}
