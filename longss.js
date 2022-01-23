const lengthOfLongestSubstring = (s) => {
	let bss = '';
	for(let i = 0; i < s.length; i++){
		let ss = '';
		let k = i;
		while(!ss.includes(s[k]) && k < s.length) {
			ss += s[k];
			k++;
		}
		if(ss.length > bss.length) bss = ss;
	}
	console.log(bss)
	return bss.length;
}

lengthOfLongestSubstring("pwwkew")
lengthOfLongestSubstring("aabbccabccdd")
lengthOfLongestSubstring("dvdf")
lengthOfLongestSubstring("ckilbkd")
