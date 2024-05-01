package main

func reversePrefix(word string, ch byte) string {
	bts := []byte(word)
	for i := 0; i < len(word); i++ {
		if word[i] == ch {
			j := 0
			for i > j {
				bts[i], bts[j] = bts[j], bts[i]
				i--
				j++
			}
			return string(bts)
		}
	}
	return word
}
