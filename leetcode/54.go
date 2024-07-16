func spiralOrder(matrix [][]int) []int {
  var m int = len(matrix);
  var n int = len(matrix[0]);
  var res []int;
  var left, right, up, down = 0, n-1, 0, m-1;
  for k := 0; k < (m/2)+1; k++ {
    if((down-up) <= 0 || (right-left) <= 0) { break } 
    for j := left; j < right; j++ { res = append(res, matrix[up][j]) }
    for i := up; i < down; i++ { res = append(res, matrix[i][right]) }
    for j := right; j > left; j-- { res = append(res, matrix[down][j]) }
    for i := down; i > up; i-- { res = append(res, matrix[i][left]) }
    left++;
    right--;
    up++;
    down--;
  }
  if(up == down) {
    for j := left; j < right+1; j++ { res = append(res, matrix[up][j]) } 
  } else if(left == right) {
    for i := up; i < down+1; i++ { res = append(res, matrix[i][left]) }
  }
  return res;
}
