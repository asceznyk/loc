const containsDuplicate = function(nums) {
	let counts = {}
	for (let i = 0; i < nums.length; i++) {
		if(counts.hasOwnProperty(nums[i])) return true;
		else counts[nums[i]] = 1
	};

	return false;
}

console.log(containsDuplicate([1,2,3,4,5,6]))



