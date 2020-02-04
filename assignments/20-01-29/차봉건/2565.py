N = int(input())

rope = []
for i in range(N):
	rope_elem = list(map(int, input().split()))
	rope.append(rope_elem)

rope.sort(key = lambda x : x[0])

length_list = []

for i in range(N):
	length_elem = 0
	
	for j in range(i):
		if rope[j][1] < rope[i][1]:
			if length_elem < length_list[j]:
				length_elem = length_list[j]
	
	length_list.append(length_elem + 1)

print(N - max(length_list))
