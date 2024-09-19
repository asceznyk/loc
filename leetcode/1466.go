var count int = 0

func dfs(
  adjList map[int][]int, path map[string]bool,
  curr int, par int, visited []bool,
) {
  if visited[curr] {
    return 
  }
  _, exists := path[(strconv.Itoa(par) + "_" + strconv.Itoa(curr))]
  if exists {
    count++
  }
  visited[curr] = true
  for i := range adjList[curr] {
    child := adjList[curr][i] 
    dfs(adjList, path, child, curr, visited)
  }
}

func minReorder(n int, connections [][]int) int {
  adjList := make(map[int][]int)
  path := make(map[string]bool)
  for i := range connections {
    a, b := connections[i][0], connections[i][1]
    adjList[a] = append(adjList[a], b)
    adjList[b] = append(adjList[b], a)
    path[strconv.Itoa(a) + "_" + strconv.Itoa(b)] = true
  }
  visited := make([]bool, n)
  count = 0
  dfs(adjList, path, 0, -1, visited)
  fmt.Println("count =", count)
  return count
}


