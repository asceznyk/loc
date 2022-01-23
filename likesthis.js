function likes(names) {
	let suffix = names.length <= 1 ? 'likes' : 'like'
	let desc = ''
	if(!names.length) {
		return 'no one ' + suffix + ' this'
	} else {
		if(names.length == 1) {
			return names[0] + ' ' + suffix + ' this'
		} else if (names.length == 2) {
			return names[0] + ' and ' + names[1] + ' ' + suffix + ' this'
		} else if (names.length == 3) {
			return names[0] + ', ' + names[1] + ' and ' + names[2] + ' ' + suffix + ' this'
		} else if (names.length > 3) {
			return names[0] + ', ' + names[1] + ' and ' + (names.length-2) + ' others ' + suffix + ' this'
		}
	}
}

const reply = likes(['Peter', 'Alex', 'Max', 'Lucas', 'Toby', 'Gian', 'Sasuke']);
console.log(reply);





