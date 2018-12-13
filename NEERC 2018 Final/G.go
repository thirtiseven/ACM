package main

import "fmt"

func main() {
	var T int
	var k int64
	var a [10] int
	fmt.Scanln(&T)
	for T > 0 {
		T--
		fmt.Scanln(&k)
		var cnt int64 = 0
		for i := 0; i < 7; i++ {
			fmt.Scanln(&a[i])
			if a[i] > 0 {
				cnt++
			}
		}
		var ans int64 = 0
		if k > cnt*2 {
			ans = (k / cnt - 1) * 7;
			k %= cnt
			k += cnt
		}
		var now int64 = 200000000
		var tot int64
		for i := 0; i < 7; i++ {
			cnt = 0
			tot = 0
			for  j := i; cnt < k; j = (j+1)%7 {
				tot++
				if a[j] == 1 {
					
					cnt++
				}
			}
			if now > tot {
				now = tot
			}
		}
		if now == 200000000 {
			now = 0
		}
		ans += now
		fmt.Println(ans)
	}
}
