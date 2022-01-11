function isSquare(num) {
	let root = Math.sqrt(num)
	if(!(root - Math.floor(root)) && num >= 0) {
		return true;
	}
	return false
}

console.log(isSquare(625));
console.log(isSquare(0))


