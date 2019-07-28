### 최단 경로

* Single-source : 하나의 출발 노드로부터 다른 모든 노드까지의 최단 경로 (one-to-all)
* Single-destination : Single-source와 방향만 뒤집으면 같은 문제
* Single-pair: 주어진 하나의 출발 노드로부터 하나의 목적지 노드까지의 최단 경로
    * 최악의 경우 시간복잡도에서 single-source문제보다 나은 알고리즘이 없음
    * one-to-one
* All-pair:모든 노드에 쌍에 대해서 최단 경로를 찾아라.
    * Floyd

---

#### 최단경로와 음수 가중치

* 알고리즘에 따라 음수 가중치가 있어도 작동하는 경우도 있고 그렇지 않은 경우도 있음
* Dijecstra는 음수가 없다는 가정하에 수행
* 음수 사이클이 있으면 최단 경로가 정의되지 않음



#### 최단경로의 기본 특성

* 최단 경로의 어떤 부분경로도 역시 최단 경로이다.
* 최단 경로는 사이클을 포함하지 않는다. (음수 사이클이 없다는 가정하에서)



#### 기본연산: Relaxation

* d[u] =5 , d[v] =9 이고 d[u] - d[v] = 2 일때 d[v] = 7로 업데이트 해준다.

* ~~~ sudo
    RELAX(u,v,w)
    	if d[v] > d[u] + w(u,v)
    		then d[v] <= d[u] + w[u,v]
    			p[v]<-u
    ~~~

* 대부분의 single-source 최단경로 알고리즘의 기본구조

    1. 초기화 : d[s] =0, 노드 v=s에 대해서 d[v] = 무한, 파이[v] = NULL
    2. 에지들에 대한 반복적인 relaxation

* 알고리즘들 간의 차이는 어떤 에지에 대해서, 어떤 순서로 relaxation을 하느냐에 있음

~~~
Generic-single-source(G,w,s)
	INITIALISE-SINGLE-sOURCE(G,s)
	repeat
		for each edge(u,v) all Edge
			RELAX(u,,v,w)
	until there is no change
~~~

![img](/Users/gt/algorithm/Graph algorithm/img.png)

> (엗지의 개수가 n-1개일때 )즉, n-1번의 반복으로 충분하다.
>
> Bellman-Ford 알고리즘 (반복 횟수를 n-1로 고정 시킴)







