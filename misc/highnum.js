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
