const convert = (s, rows) => {
	let zz = [];
	for(let r = 0; r < rows; r++) zz.push([])

	if(rows <= 1) return s

	let r = 0;
	let i = 1;
	for(let c = 0; c < s.length; c++) {
		if(r == rows-1) i = -1;
		if(r == 0) i = 1;
		zz[r].push(s[c]);
		r += i;
	}

	return zz.flat().reduce((i,r) => i+r)
}

let s = convert("PAYPALISHIRING", 4)
console.log(s)


