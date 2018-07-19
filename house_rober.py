'''
Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
'''


class Solution:
    def rob(self, root):
        result = self.compare_grandpa_grandson_team_or_now(root)
        return max(result)
        

    def compare_grandpa_grandson_team_or_now(self, node):
        if node is None:
            return [0, 0]

        left = self.compare_grandpa_grandson_team_or_now(node.left)
        right = self.compare_grandpa_grandson_team_or_now(node.right)
        include_root = left[1] + right[1] + node.value
        not_include_root = max(left) + max(right)
    
        return [include_root, not_include_root];


class Node:
   def __init__(self, value, left, right):
      self.value = value
      self.left = left
      self.right = right


root0 = Node(3, 
    Node(2, 
        None, 
        Node(3, None, None)), 
    Node(3, 
        None, 
        Node(1, None, None)))



root1 = Node(3, 
    Node(4, 
        Node(1, None, None),
        Node(3, None, None)), 
    Node(5, 
        None, 
        Node(1, None, None)))

s = Solution()
print(s.rob(root0)) # 7
print(s.rob(root1)) # 9
