function comp(array1, array2) {
	if(array1 && array2) {
		let sq  = array1.map(e => e ** 2).sort();
		array2 = array2.sort();
		return sq.every((val, index) => val === array2[index]);	
	}
	return false;
}
let t = comp([121, 144, 19, 161, 19, 144, 19, 11], [121, 14641, 20736, 361, 25921, 361, 20736, 361])
console.log(t)

