//let nums = [34, 30, 3, 5, 9]
let nums = [1, 34, 3, 98, 9, 76, 45, 4, 12, 121]

function highestNum(nums) {
	let maxlen = Math.max(...nums).toString().length;	
	let total = '';
	nums.sort((a, b) => {
		let num1 = parseInt(a.toString() + b.toString())
		let num2 = parseInt(b.toString() + a.toString())
		if(num1 > num2) {return -1} 
		else if(num2 > num1) {return 1}
		else {return 0}
	})
	return nums.join('')
}


console.log(highestNum(nums))
