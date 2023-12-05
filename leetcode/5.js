const longestPalindrome = (s) => {	
  let bss = '';
  let palintab = [];
  for(let f = 0; f < 2; f++) {
    for(let y = 0; y < s.length; y++) {
      palintab[y] = new Array(s.length).fill(0);
      palintab[y][y] = 1;
      if(s[y] == s[y+f]) {
        bss = s.slice(y, y+f+1);
        palintab[y][y+f] = 1;
      } 
    }
  }
  for(let d = 2; d < s.length; d++) {	
    for(let k = 0; k < (s.length-d)+1; k++) {		
      if(s[k] == s[k+d] && palintab[k+1][k+d-1]) {	
        palintab[k][k+d] = 1;
        bss = s.slice(k, k+d+1);
      }
    }
  }
  return bss;
}


