### Tree , binary tree

* 노드가 N개인 트리는 항상 N-1 개의 노드를 갖는다.
* 트리에서 루트 혹은 노드에서 노드로 가는 경로는 유일 하다. 

### 이진 트리의 표현

* 보통 연결리스트로 표현한다.

### 이진 트리의 순회

* 순회 : 이진 트리의 모든 노드를 방문하는 일

* 중순위(inorder), 선순위(preorder), 후순위(postorder) (순회). /  레벨 오더(level-order) (큐)

    * ``` 
        Inorder-tree-walk(x) //시간 복잡도 O(n)
        	if x != NULL
        		the Inorder-tree-walk(left[x])
        			print key[x]
        			Inorder-tree-walk(right[x])
        			
        Preorder-tree-walk(x)
            if x != NULL
            then print key[x]
        		Pre-order-tree-walk(left[x])
                Pre-order-tree-walk(right[x])
                
        Postorder-tree-walk(x)
            if x != NULL
            then Pre-order-tree-walk(left[x])
                 Pre-order-tree-walk(right[x])
                 print key[x]
                 
        Level-order-tree-traversal()
        	visit the root;
        	q <- root;
        	while Q is not empty do
        		v <- dequeue(Q);
        		visit children of v;
        		enqueue children of v into Q;
        	end
        end
        ```

        