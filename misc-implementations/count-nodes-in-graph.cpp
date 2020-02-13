
// count the number of nodes in a graph
if (node == nullptr) {
    return nullptr;
}

// count nodes in the graph
unordered_set<Node*> visited;
queue<Node*> nodes;
nodes.push(node);
int num_nodes = 0;
while (!nodes.empty()) {
    Node* top = nodes.front();
    nodes.pop();
    if (visited.find(top) != visited.end()) {
        continue;
    }
    visited.insert(top);
    cout << top->val << endl;
    num_nodes++;
    
    for (Node* neighbor : top->neighbors) {
        cout << "\t" << neighbor->val << endl;
        if (visited.find(neighbor) == visited.end()) {
            nodes.push(neighbor);
        }
    }
}