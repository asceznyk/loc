type RandomizedSet struct {
  elements map[int]int
  keys []int
}

func Constructor() RandomizedSet {
  return RandomizedSet{
    elements: make(map[int]int),
  }
}

func (this *RandomizedSet) Insert(val int) bool {
  _, exists := this.elements[val]
  if exists {
    return false
  }
  this.elements[val] = len(this.keys)
  this.keys = append(this.keys, val)
  fmt.Println(this.keys)
  return true
}

func (this *RandomizedSet) Remove(val int) bool {
  i, exists := this.elements[val]
  if !exists {
    return false
  }
  n := len(this.keys)
  v := this.keys[n-1]
  this.keys[i] = v
  this.elements[v] = i
  this.keys = this.keys[:n-1]
  delete(this.elements, val)
  fmt.Println(this.keys, this.elements, v)
  return true
}

func (this *RandomizedSet) GetRandom() int {
  return this.keys[rand.Intn(len(this.keys))]
}


