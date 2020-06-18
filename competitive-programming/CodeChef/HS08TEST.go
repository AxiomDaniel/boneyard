package main

import (
	"fmt"
)

func solve(draw int, bal float32) string {
	result := bal - float32(draw) - 0.5
	if result < 0 || draw % 5 != 0 {
		result = bal
	}
	return fmt.Sprintf("%.2f", result)
}

func main() {
	var draw int
	var bal float32
	fmt.Scan(&draw, &bal)
	fmt.Println(solve(draw,bal))
}
