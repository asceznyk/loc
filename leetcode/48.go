func rotate(matrix [][]int) {
  var n int = len(matrix);
  var l,r,u,d = 0, n-1, 0, n-1;
  for k := 0; k < (n/2); k++ {
    var right []int;
    for i := u; i < d; i++ {
      right = append(right, matrix[i][r])
      matrix[i][r] = matrix[u][i]
    }
    var down []int;
    for j := r; j > l; j-- {
      down = append(down, matrix[d][j]) 
      popped := right[0]
      right = right[1:]
      matrix[d][j] = popped
    }
    var left []int;
    for i := d; i > u; i-- { 
      left = append(left, matrix[i][l])
      popped := down[0]
      down = down[1:]
      matrix[i][l] = popped
    }
    for j := l; j < r; j++ {
      popped := left[0]
      left = left[1:]
      matrix[u][j] = popped 
    } 
    l++; 
    r--;
    u++; 
    d--;
  }
}

