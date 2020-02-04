N = int(input())
A = list(map(int, input().split()))
B = []

for i in range(len(A)):
	max_num = 0
	for j in range(i):
		if A[j] < A[i]:
			if max_num < B[j]:
				max_num = B[j]
	
	B.append(max_num+1)

print(max(B))
