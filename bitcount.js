const countBits = (n) => {
	for(c = 0; n; n >>= 1) c += n & 1
	return c
}

console.log(countBits(91120))

