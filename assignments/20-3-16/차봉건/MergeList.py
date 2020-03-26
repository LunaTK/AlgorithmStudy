# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:

        if l1 == None and l2 == None:
            return None
        elif l1 == None:
            return l2        
        elif l2 == None:
            return l1
        
        if(l1.val >= l2.val):
            merged = ListNode(l2.val)
            l2 = l2.next
        else:
            merged = ListNode(l1.val)
            l1 = l1.next
            
        tmp_node = merged
        while l1 != None and l2 != None:
            if l1.val >= l2.val:
                new_node = ListNode(l2.val)
                tmp_node.next = new_node
                tmp_node = tmp_node.next
                l2 = l2.next
            else:
                new_node = ListNode(l1.val)
                tmp_node.next = new_node
                tmp_node = tmp_node.next
                l1 = l1.next
        
        while l1 != None:
            new_node = ListNode(l1.val)
            tmp_node.next = new_node
            tmp_node = tmp_node.next
            l1 = l1.next
        while l2 != None:
            new_node = ListNode(l2.val)
            tmp_node.next = new_node
            tmp_node = tmp_node.next
            l2 = l2.next
            
        return merged
        
