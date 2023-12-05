const lengthOfLongestSubstring = (s) => {
  const bestSubstring = (k) => {
    let ss = '';
    while(!ss.includes(s[k]) && k < s.length) {
      ss += s[k];
      k++;
    }
    return ss;
  }

  let bss = '';
  for(let i = 0; i < s.length; i++){
    let current = bestSubstring(i);
    if(current.length > bss.length) bss = current;
  }
  return bss.length;
}
