const isPalindrome = (x) => {
  let rx = '';
  x = x.toString();
  for(let i = x.length-1; i >= 0; i--) { rx += x[i];}
  rx = parseInt(rx);
  x = parseInt(x);
  if(rx == x) return true;
  return false;
} 

