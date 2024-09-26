package main

import (
  "fmt"
  "sort"
)

var res = []string{}

func dfs(
  adjList map[string][]string, vedges map[string]bool,
  curr string, par string,
) {
  vedges[par + "_" + curr] = true
  if len(res) == 0 || curr != res[len(res)-1] {
    res = append(res, curr)
  }
  fmt.Println(par, curr)
  for _, child := range adjList[curr] {
    visited := vedges[curr + "_" + child]
    if visited {
      continue
    }
    dfs(adjList, vedges, child, curr)
  } 
}

func findItinerary(tickets [][]string) []string {
  adjList := make(map[string][]string)
  vedges := make(map[string]bool)
  for i := range tickets {
    from, to := tickets[i][0], tickets[i][1]
    adjList[from] = append(adjList[from], to)
    sort.Strings(adjList[from])
    vedges[from + "_" + to] = false 
  }
  fmt.Println(adjList)
  fmt.Println(vedges)
  res = []string{}
  dfs(adjList, vedges, "JFK", "")
  fmt.Println("res", res)
  return res
}

func main() {
  findItinerary([][]string{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}})
  findItinerary([][]string{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}})
  findItinerary([][]string{{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}})
}

