const longestPalindrome = (s) => {	
	const expandFromMiddle = (ms, left, right) => {
		if(ms == null || left > right) return '';

		while(left >= 0 && right < ms.length && ms[right] == ms[left]) {
			right++; left--;	
		}
		left++; right--;
		left = Math.max(0, left); right = Math.min(right, s.length);

		return s.slice(left, right+1);
	}

	if(s == null || s.length < 1) return '';

	let smax = '';
	for (let i = 0; i < s.length; i++) {
		let options = [expandFromMiddle(s, i, i), expandFromMiddle(s, i, i+1)];	
		let ls = options.map((x)=> [x, x.length]).reduce((r, a) => {
			return a[1] > r[1] ? a : r;
		})[0];
		if(ls.length > smax.length) smax = ls;	
	}

	return smax;
}


