package main

import (
  "fmt"
  "sort"
)

var res = []string{}

func backtrack(adjList map[string][]string, src string) {
  neighbors, exists := adjList[src]
  if !exists {
    res = append(res, src)
    return
  }
  fmt.Println(src, neighbors)
  for len(neighbors) > 0 {
    dst := neighbors[0]
    adjList[src] = adjList[src][1:]
    backtrack(adjList, dst)
    neighbors = adjList[src]
  }
  res = append(res, src)
}

func findItinerary(tickets [][]string) []string {
  adjList := make(map[string][]string)
  for i := range tickets {
    from, to := tickets[i][0], tickets[i][1]
    adjList[from] = append(adjList[from], to)
    sort.Strings(adjList[from])
  }
  res = []string{}
  backtrack(adjList, "JFK")
  if len(res) == len(tickets)+1 {
    for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
      res[i], res[j] = res[j], res[i]
    }
    fmt.Println("res", res)
    return res
  }
  return []string{}
}

func main() {
  findItinerary([][]string{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}})
  findItinerary([][]string{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}})
  findItinerary([][]string{{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}})
  findItinerary([][]string{{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}})
}

