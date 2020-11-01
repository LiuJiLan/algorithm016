学习笔记
双向BFS模板
void bibfs(Node* start, Node* end) {
    set<Node*> front {start};
    set<Node*> back {end};
    set<int> visited;
    while (!front.empty()) {
        set<Node*> newset;
        for (const auto& node : front) {
            for (const auto& val : generate_new_nodes(node->val)) {
                if (visited.find(val) != visited.end()) {
                    newset.insert(val);
                }
            }
        }
        front = newset;
        if (front.size() > back.size()) {
            swap(front, back);
        }
    }
    return 0;
}
