

def step(x,y,xlim,ylim,count,grid):
    if x < xlim and y < ylim:
        if grid[x][y] != 0:
            count += grid[x][y]
        else:
            grid[x][y] = step(x + 1,y,xlim,ylim,count,grid) + step(x, y + 1,xlim,ylim,count,grid)
            count += grid[x][y]
    elif x < xlim and y == ylim:
        if grid[x][y] != 0:
            count += grid[x][y]
        else:
            grid[x][y] = step(x + 1,y,xlim,ylim,count,grid)
            count += grid[x][y]
    elif x == xlim and y < ylim:
        if grid[x][y] != 0:
            count += grid[x][y]
        else:
            grid[x][y] = step(x,y + 1,xlim,ylim,count,grid)
            count += grid[x][y]
    else:
        count += 1
    return count


def init_array(x,y):
    arr = []
    for i in range(x + 1):
        arr.append([])
        for j in range(y + 1):
            arr[i].append(0)
    return arr

h = 50
v = 50
arr = init_array(h,v)
print step(0,0,h,v,0, arr)

print arr
