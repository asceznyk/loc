const lowestCommonAncestor = function(root, p, q) {
  let stack = [root];
  while(stack.length) {
    let node = stack.pop();
    if(node == null) continue;
    if (
      (p.val <= node.val && node.val <= q.val) ||
      (q.val <= node.val && node.val <= p.val)
    ) return node;
    stack.push(node.right)
    stack.push(node.left)
  }
  return root;
};
