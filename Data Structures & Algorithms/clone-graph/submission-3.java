/*
Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        /*
            hashmap that stores old node pointer to new node pointer
            beadth first search through graph and create a new node
            then bfs again to get all the connections
        */
        if (node == null) return null;

        Map<Node, Node> oldToNew = new HashMap<>();
        HashSet<Node> visited = new HashSet<>();
        oldToNew.put(node, new Node(node.val));
        visited.add(node);

        Deque<Node> q = new ArrayDeque<>();
        q.push(node);

        while (!q.isEmpty()) {
            Node front = q.peek();
            q.removeFirst();
            
            List<Node> neighbours = front.neighbors;
            for (int i = 0; i < neighbours.size(); ++i) {
                if (visited.contains(neighbours.get(i))) continue;
                q.push(neighbours.get(i));
                visited.add(neighbours.get(i));

                oldToNew.put(neighbours.get(i), new Node(neighbours.get(i).val));
            }
        }

        for (Map.Entry<Node, Node> entry : oldToNew.entrySet()) {
            List<Node> oldNeighbours = entry.getKey().neighbors;
            Node newNode = entry.getValue();

            for (int i = 0; i < oldNeighbours.size(); ++i) {
                newNode.neighbors.add(oldToNew.get(oldNeighbours.get(i)));
            }
        }

        return oldToNew.get(node);
    }
}