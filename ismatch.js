const isMatch = function (text, pattern) {
	if (!pattern.length) return !text.length;	
	let firstMatch = !!text && (pattern[0] == text[0] || pattern[0] == '.');

	if(pattern.length >= 2  && pattern[1] == '*') {
		return (
			isMatch(text, pattern.slice(2, pattern.length)) || 
			firstMatch && isMatch(text.slice(1, text.length), pattern)
		)
	}
	return firstMatch && isMatch(text.slice(1, text.length), pattern.slice(1, pattern.length))
}

console.log(isMatch("axxbx", "a.*b"));

