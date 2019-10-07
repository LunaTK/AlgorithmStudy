N = int(input())
gfield = [list(map(int, input().split())) for _ in range(N)]

max_num = 0


def copy_field(field):
    return [field[i].copy() for i in range(N)]


def update_max(field):
    global max_num
    for row in field:
        for val in row:
            if max_num < val:
                max_num = val


def slide_left(field):
    global max_num
    for i in range(N):
        before = -1
        merged = False
        for j in range(N):
            if field[i][j] != 0:
                field[i][before+1] = field[i][j]
                if before+1 != j:
                    field[i][j] = 0
                if before > -1 and not merged and field[i][before] == field[i][before+1]:
                    field[i][before] *= 2
                    field[i][before+1] = 0
                    merged = True
                else:
                    merged = False
                    before += 1
    return field


def slide_right(field):
    global max_num
    for i in range(N):
        before = N
        merged = False
        for j in range(N-1, -1, -1):
            if field[i][j] != 0:
                field[i][before-1] = field[i][j]
                if before-1 != j:
                    field[i][j] = 0
                if before < N and not merged and field[i][before] == field[i][before-1]:
                    field[i][before] *= 2
                    field[i][before-1] = 0
                    merged = True
                else:
                    merged = False
                    before -= 1
    return field


def slide_up(field):
    global max_num
    for j in range(N):
        before = -1
        merged = False
        for i in range(N):
            if field[i][j] != 0:
                field[before+1][j] = field[i][j]
                if before+1 != i:
                    field[i][j] = 0
                if before > -1 and not merged and field[before][j] == field[before+1][j]:
                    field[before][j] *= 2
                    field[before+1][j] = 0
                    merged = True
                else:
                    merged = False
                    before += 1
    return field


def slide_down(field):
    global max_num
    for j in range(N):
        before = N
        merged = False
        for i in range(N-1, -1, -1):
            if field[i][j] != 0:
               #     print(f'before : {before}')
                field[before-1][j] = field[i][j]
                if before-1 != i:
                    field[i][j] = 0
                if before < N and not merged and field[before][j] == field[before-1][j]:
                    field[before][j] *= 2
                    field[before-1][j] = 0
                    merged = True
                else:
                    merged = False
                    before -= 1
    return field


def dfs(field, depth):
    if depth == 5:
        update_max(field)
        return
    dfs(slide_left(copy_field(field)), depth+1)
    dfs(slide_right(copy_field(field)), depth+1)
    dfs(slide_up(copy_field(field)), depth+1)
    dfs(slide_down(copy_field(field)), depth+1)


dfs(gfield, 0)
print(max_num)
