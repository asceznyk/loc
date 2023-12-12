const reverse = (x) => {
  let xStr = Math.abs(x).toString()
  let yStr = '';
  for(let i=xStr.length-1; i>=0; i--) { yStr += xStr[i] }
  if (x < 0) { yStr = '-' + yStr; }
  y = parseInt(yStr);
  if (y >= -(2 ** 31) && y <= (2 ** 31) - 1) { return y; }
  return 0;
}

