function squareDigits(num) {
  let squared = ''
  let digits = ('' + num).split('')
  digits.forEach((item, index) => {
    squared += (parseInt(item)**2)  
  })
  return parseInt(squared);
}

let sq  = squareDigits(9239)
console.log(sq)
