### 멱집합(powerset)

* {a,b,c,d,e,f}의 모든 부분집합을 나열하려면 a를 제외한 {b,c,d,e,f}의 모든 부분집합들을 나열하고 {b,c,d,e,f,}의 모든 부분집합에 {a}를 추가한 집합들을 나열한다.
* {b,c,d,e,f}의 모든 부분집합에 {a}를 추가한 집합들을 나열하려면 {c,d,e,f}의 모든 부분집합들에 {a}를 추가한 집합들을 나열하고 {c,d,e,f,}의 모든 부분집합에 {a, b}를 추가한 집합들을 나열 -->다음 과정도 동일 반복

~~~ c
powerSet(S) //s의 멱집합 출력
if S is an empty set
	print nothing;
else
    let t be the first element of S;
	find all subsets of S-{t} by calling powerSet(S-{t});
print the subsets;
print the subsets with adding t;

//return all of them;
~~~

``` c
pwerSet(P,S) // s의 멱집합을 구한 후 각각에 집합 P를 합집합하여 출력
    if S is an empty set
    	print P;
	else
        let t be the first element of S;
		powerSet(P,S-{t});
		powerSet(P U {t}, S-{t});
//recursion 함수가 두 개의 집합을 매개변수로 받도록 설계해야한다는 의미, 두번쨰 집합의 모든 부분집합들에 첫번째 집합을 합집합 하여 출력
```

---

~~~java
private static char data[] = {'a','b','c','d','e','f'};
private static int n = data.length;
private static boolean [] include = new boolean [n];
//data[k], ... data[n-1]의 멱집합을 구한 후 각각에 include[i]=true, i= 0,...,k-1 인 원소를 추가하여 출력
//처음 이 함수를 호출할 때는 powerSet(0)로 호출한다. 즉 P는 공집합이고 S는 전체집합이다.
public static void powerSet(int K){
    if(k==n){
        for(int i=0; i<n; i++)
            if(include[i]) System.out.print(data[i] + " ");
        System.out.println();
        return;
    }
    include[k]=false;
    powerSet(k+1);
    include[k]=true;
    powerSet(k+1);
}
~~~

* 상태공간 트리
  * 해를 찾기 위해 탐색할 필요가 있는 모든 후보들을 포함하는 트리
  * 트리의 모든 노드들을 방문하면 해를 찾을 수 있다.
  * 루ㅊ트에서 출발하여 체계적으로 모든 노드를 방문하는 절차를 기술한다.

