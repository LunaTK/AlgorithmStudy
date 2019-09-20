scale = int(input())
whole_map = []
part_map = []

count = 0
result = []

def map_search(i, j):
	global count
	if(whole_map[i][j] ==  '1'):
		count = count+1
		whole_map[i][j] = '0'

		if(j!=0) :
			map_search(i, j-1)
		if(i!=scale-1):
			map_search(i+1, j)
		if(j!=scale-1):
			map_search(i, j+1)
		if(i!=0):
			map_search(i-1, j)

	return


for i in range(scale):
	part_map = list(input())
	
	whole_map.append(part_map)


for i in range(scale):
	for j in range(scale):
		count = 0
		map_search(i, j)
		if(count!=0):
			result.append(count)

result.sort()
print(len(result))
for i in range(len(result)):
	print(result[i])
