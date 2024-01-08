function comp(array1, array2) {
  if(array1 && array2) {
    let sq  = array1.map(e => e ** 2).sort();
    array2 = array2.sort();
    return sq.every((val, index) => val === array2[index]);	
  }
  return false;
}

