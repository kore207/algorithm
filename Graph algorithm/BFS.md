### 그래프 순회(Graph traversal)

* 순회(traversal)
  * 그래프의 모든 노드들을 방문하는 일
* 대표적 두 가지 방법
  * BFS(Breadth-First Search, 너비우선순회)
  * DFS(Depth-First Search, 깊이우선순회)

---

#### 큐를 이용한 너비우선순회

1. check the start node
2. insert the start node into the queue
3. while the queue is not empty do remove a node v from queue
4. for each unchecked neighbour w of v do check and insert w into th queue

* 각 노드까지의 최단 경로를 구할 수 있다.