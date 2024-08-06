func dfs(root int, i int, reachable *[][]bool, adjList *[][]int) {
  for j := 0; j < len((*adjList)[i]); j++ {
    v := (*adjList)[i][j]
    if((*reachable)[root][v]) { continue; }
    dfs(root, v, reachable, adjList)
    (*reachable)[root][v] = true
  }
}

func checkIfPrerequisite(numCourses int, prerequisites [][]int, queries [][]int) []bool {
  adjList := make([][]int, numCourses)
  for i := 0; i < len(prerequisites); i++ {
    var a, b int = prerequisites[i][0], prerequisites[i][1]
    adjList[a] = append(adjList[a], b)
  }
  ans := make([]bool, len(queries))
  reachable := make([][]bool, numCourses);
  for i := 0; i < numCourses; i++ { reachable[i] = make([]bool, numCourses) }
  for i := 0; i < numCourses; i++ { dfs(i, i, &reachable, &adjList) };
  for i := 0; i < len(ans); i++ {
    ans[i] = reachable[queries[i][0]][queries[i][1]]
  }
  return ans
}

