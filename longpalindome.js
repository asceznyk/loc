const longestPalindrome = (s) => {	
	const expandFromMiddle = (ms, left, right) => {
		if(ms == null || left > right) return '';

		while(left >= 0 && right < ms.length && ms[right] == ms[left]) {
			right++; left--;
			c++;
		}
		left++; right--;

		return s.slice(Math.max(0, left), Math.min(right, s.length)+1);
	}

	if(s == null || s.length < 1) return '';

	let smax = '';
	let c = 0;
	for (let i = 0; i < s.length; i++) {
		let options = [expandFromMiddle(s, i, i), expandFromMiddle(s, i, i+1)];	
		let ls = options.map((x)=> [x, x.length]).reduce((r, a) => {
			return a[1] > r[1] ? a : r;
		})[0];
		if(ls.length > smax.length) smax = ls;
		c++;
	}

	return smax;
}


