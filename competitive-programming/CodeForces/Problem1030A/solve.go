package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(reader *bufio.Reader, n int) string {
	var in int
	for n > 0 {
		fmt.Fscan(reader, &in)
		if in == 1 {
			return "HARD"
		}
		n--
	}
	return "EASY"
}

func main() {
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(reader, &n)

	fmt.Println(solve(reader, n))
}
