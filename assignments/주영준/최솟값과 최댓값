def tMax_init(inp,tree,node,start,end):
    if start == end:
        tree[node] = inp[start]
        return tree[node]
    else:
        tree[node] = max(tMax_init(inp,tree,node*2,start,(start+end)//2),tMax_init(inp,tree,node*2+1,(start+end)//2+1,end))
        return tree[node]

def tMin_init(inp,tree,node,start,end):
    if start == end:
        tree[node] = inp[start]
        return tree[node]
    else:
        tree[node] = min(tMin_init(inp,tree,node*2,start,(start+end)//2),tMin_init(inp,tree,node*2+1,(start+end)//2+1,end))
        return tree[node]

def Max(tree,node,start,end,left,right):
    if (left > end) or (right < start):
        return -1
    if (left <= start) and (end <= right):
        return tree[node]
    
    m1 = Max(tree,node*2,start,(start+end)//2,left,right)
    m2 = Max(tree,node*2+1,(start+end)//2+1,end,left,right)
    
    if m1 == -1 : return m2
    elif m2 == -1 : return m1
    else: return max(m1,m2)

def Min(tree,node,start,end,left,right):
    if (left > end) or (right < start):
        return -1
    if (left <= start) and (end <= right):
        return tree[node]

    m1 = Min(tree,node*2,start,(start+end)//2,left,right)
    m2 = Min(tree,node*2+1,(start+end)//2+1,end,left,right)
    
    if m1 == -1: return m2
    elif m2 == -1: return m1
    else: return min(m1,m2)   

if __name__ == "__main__":
    N, M = input().split()
    N = int(N)
    M = int(M)
    inp = list()

    for i in range(N):
        temp = input()
        temp = int(temp)
        inp.append(temp)

    M_tree = [0 for i in range(N*4)]
    m_tree = [0 for i in range(N*4)]
    tMax_init(inp,M_tree,1,0,N-1)
    tMin_init(inp,m_tree,1,0,N-1)

    for i in range(M):
        a, b = input().split()
        a = int(a)
        b = int(b)
        print(Min(m_tree,1,0,N-1,a-1,b-1),Max(M_tree,1,0,N-1,a-1,b-1))

