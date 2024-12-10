var dirs = [][]int {{0,1},{0,-1},{1,0},{-1,0}}

var visited = map[string]int{}

func stringify(board [][]int) string {
  s := ""
  for i := 0; i < 2; i++ {
    for j := 0; j < 3; j++ {
      s += strconv.Itoa(board[i][j])
    }
  }
  return s
}

func dfs(board [][]int, i int, j int, moves int) {
  key := stringify(board)
  v, exists := visited[key] 
  if exists && v <= moves {
    return
  }
  visited[key] = moves
  for _, dir := range dirs {
    di, dj := dir[0], dir[1]
    if i+di < 0 || i+di > 1 ||
    j+dj < 0 || j+dj > 2 {  
      continue
    }
    board[i][j], board[i+di][j+dj] = board[i+di][j+dj], board[i][j] 
    dfs(board, i+di, j+dj, moves+1)
    board[i][j], board[i+di][j+dj] = board[i+di][j+dj], board[i][j]
  }
}

func slidingPuzzle(board [][]int) int {
  si, sj := 0, 0
  visited = map[string]int{}
  for i := 0; i < 2; i++ {
    for j := 0; j < 3; j++ {
      if(board[i][j] == 0) {
        si = i
        sj = j
        break
      }
    }
  }
  dfs(board, si, sj, 0)
  v, exists := visited["123450"]
  if exists {
    return v
  }
  return -1
}

