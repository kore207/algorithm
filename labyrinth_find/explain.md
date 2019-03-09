## 미로찾기

> 인프런 알고리즘 강좌 recursion의 응용 미로찾기
>
> **Recursive Thinking**
>
> 현재 위치에서 출구까지 가는 경로가 있으려면
>
> 1. 현재 위치가 출구이거나
> 2. 이웃한 셀들 중 하나에서 현재 위치를 지나지 않고 출구까지 가는 경로가 있거나

* Decision Problem (답이 Yes or No)

```c
boolean findPath(x,y)
	if(x,y) is the exit
		return true;
    else
    	mark (x,y) as a visited cell; // 무한루프 방지
    	for each neighbouring cell(x', y') of (x, y) do
    		if(x',y') is on the pathway and not visited
    			if findPath(x',y')
    				return true;
    	return false;
```

