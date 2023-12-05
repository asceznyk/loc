const isAnagram = function(s, t) {
  let sSort = Array.from(s).sort();
  let tSort = Array.from(t).sort();
  if(sSort.length != tSort.length) return false;
  for(let i=0; i < sSort.length; i++) {
    if(sSort[i] != tSort[i]) return false;
  }
  return true;
}
