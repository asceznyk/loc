const groupAnagrams = function(strs) {
	let group = [];
	let sortedD = {};
	for (let i = 0; i < strs.length; i++) {
		let s = strs[i];
		let k = s.split('').sort().join('');
		if (k in sortedD) { sortedD[k].push(s) }
		else { sortedD[k] = [s]; }
	}
	for (const k in sortedD) { group.push(sortedD[k]); }
	return group;
}


