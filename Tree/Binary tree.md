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

    #### 이진검색트리(Binary Search Tree)

    * Dynamic Set (Dictionary, Search structure)

        * 여러개의 키를 저장 
        * INSERT , SEARCH, DELETE 
        * ex)심볼 테이블

    * 정렬된 혹은 정렬되지 않은 배열 혹은 연결리스트를 사용할 경우 INSERT SEARCH DELETE 중 적어도 하나는 O(n)

    * 이진탐색트리, 레드-블랙 트리, AVL-트리 등의 트리에 기반한 구조들

    * Direct adress table, hash table

    * 검색트리

        * Dynamic set을 트리의 형태로 구현
        * 일반적으로 S, I, D 연산이 트리의 높이에 비례하는 시간복잡도를 가짐
        * 이진 검색트리, 레드-블랙트리, B-트리 등

    * 이진 검색트리(Binary Search Tree)

        * 이진 트리면서 각 노드에 하나의 키를 저장 

        * 각 노드에 대해서 그 노드의 왼쪽 부트리(subree)에 있는 키들은 key[v]보다 작거나 같고, 오른쪽 부트리에 있는 값은 크거나 같다.

        * ~~~ 
            Tree-Search(x,k) //시간 복잡도 ㅣ O(h) , h= 트리의 높이
            	if x== NULL or k = key[x]
            		then return x
            	if k< key[x]
            		then return Tree-search(left[x],k)
            		else return Tree-Search(rightp[x],k)
            		
            Iterative-tree-search(x,k) //같은 소스 while 문
            	while x != NULL and k != key[x]
            		do if k <key[x]
            			then x <= left[x]
            			else x <= right[x]
            	return x
            ~~~

        * 최소/대 값은 항상 가장 왼쪽/오른쪽 노드에 존재(시간 복잡도 O(h))

        * Successor 노드 x의 successor 란 key[x]보다 크면서 가장 작은 키를 가진 노드

            * 모든 키들이 서로 다르다고 가정
            * Predecessor 는 반대

        * INSERT

            * 기존의 노드는 변경되지 않는다.

            * x,y 포인터를 통해 이전위치와 현재위치를 기억하고 있는다.

            * ~~~
                Tree-Insert(t,z) //시간 복잡도 O(h)
                	y = null
                	x= root[t]
                	while x!=null
                		do y =x
                		if key[z] < key[x]
                			then x =left[x]
                			else x = right[x]
                	p[z] =y
                	if y =null
                		then root[t]= z
                		else if key[z] < key[z] //tree t was empty
                			then left[y] = z
                			else right[y] z			
                ~~~

        * DELETE

            * 자식 노드가 없는 경우 : 그냥 삭제
            * 자식 노드가 1개인 경우 : 자신의 자식노드를 원래 자신의 위치로
            * 자식 노드가 2개인 경우 :잘린경우를 새로 정의하거나 가장 근접한 값(successor)으로 그자리를 대체한다. 이떄 값은 자식 노드가 1개나 0개이므로 위의 방법과 동일한 방법으로 대체 한다.

        * 각종 연산의 시간 복잡도 O(h)이지만 최악의 경우 트리의 높이 h=O(n)

        * 균형 잡힌 트리

            * 레드-블랙 트리 등
            * 키의 삽입이나 삭제시 추가로 트리의 균형을 잡아줌으로써 높이를 o(log2N)으로 유지