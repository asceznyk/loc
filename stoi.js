const myAtoi = (s) => {	
	let max = (2**31)-1;
	let min = -(2**31);
	let digits = '-+0123456789';
	let r = '';

	s = s.trim();	
	for(let i = 0; i < s.length; i++) {
		if(digits.includes(s[i])) {
			r += s[i];
		} else { 
			break
		}
	}

	r = parseInt(r);
	if(isNaN(r)) {
		return 0;
	} else {
		if(r <= min) {
			return min
		} else if (r >= max) {
			return max
		}
		return r;
	}
}

console.log(myAtoi("    -554292"));


