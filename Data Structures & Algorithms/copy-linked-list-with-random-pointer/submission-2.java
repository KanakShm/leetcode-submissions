/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        /*
            hashmap with old to new mapping
            iterate through the linked list and create new pointers
                based off of old ones
            
            iterate through linked list again
                go into hashmap and link the nexts and random pointers
        */
        Map<Node, Node> oldToNew = new HashMap<>();
        Node curr = head;
        while (curr != null) {
            oldToNew.putIfAbsent(curr, new Node(curr.val));
            curr = curr.next;
        }

        curr = head;
        while (curr != null) {
            Node newNode = oldToNew.get(curr);
            newNode.next = oldToNew.get(curr.next);
            newNode.random = oldToNew.get(curr.random);
            curr = curr.next;
        }

        return oldToNew.get(head);
    }
}
