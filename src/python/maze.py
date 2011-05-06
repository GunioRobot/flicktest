import random
import copy

#Approach: Start is defined as 2, end is defined as 3.
#          normal node is 1 and absent node is 0

def main():
  loop = 100
  for i in xrange(loop):
    
    a = []
    gridsize = i/33 + 3;
    #create grid of size gridsize
    creategrid(gridsize, a)
    
    #fill some random 1 and 0
    changemaze(gridsize, a)
    startend = []
    #generate start and end cell
    genstartendinmaze(gridsize, a, startend)
    
    cell_visited = {}
    cell_left = []
    
    cell_left.append(startend[2])
    cell_left.append(startend[3])
    
    path_so_far = []
    
    
    #make sure all cells are reachable
    if (verifymaze(gridsize, a) != countvalidcellinmaze(gridsize,a)):
      continue
    else:
      findpathinmaze(gridsize, a, startend[0], startend[1], cell_visited, cell_left, path_so_far)    
  
  
def findpathinmaze(gridsize, a, row, col, cell_visited_in, cell_left, path_so_far_in):
  #cell_visited[startend[0]][startend[1]] = -1
  
  
  if a[row][col] == 0:
    return
  
  if row == cell_left[0] and col == cell_left[1]:
    if (len(cell_visited_in) == countvalidcellinmaze(gridsize,a)-1):
      #path_so_far_in.append(row*10 + col)
      #cell_visited_in[row*10 + col] = 1
      print a
      print "solution "+`path_so_far_in`+`row`+`col`
      print "list " + `sorted(cell_visited_in)`+`row`+`col`
      print "------------"
      return
      
    else:
      return
      
  
  path_so_far_in.append(row*10 + col)
  cell_visited_in[10*row + col] = 1
  points = []
  
  
  #traverse again
  if row > 0:
    points.append(row -1)
    points.append(col)
    cell_visited = copy.deepcopy(cell_visited_in)
    path_so_far = copy.deepcopy(path_so_far_in)
    if (points[0]*10+points[1] not in cell_visited_in):
      findpathinmaze(gridsize, a, points[0], points[1], cell_visited, cell_left, path_so_far)
  
  points = []
  if col > 0:
    points.append(row)
    points.append(col-1) 
    cell_visited = copy.deepcopy(cell_visited_in)
    path_so_far = copy.deepcopy(path_so_far_in)
    if (points[0]*10+points[1] not in cell_visited):
      findpathinmaze(gridsize, a, points[0], points[1], cell_visited, cell_left, path_so_far)
  
  points = []
  if row < gridsize - 1:
    points.append(row + 1) 
    points.append(col)
    cell_visited = copy.deepcopy(cell_visited_in)
    path_so_far = copy.deepcopy(path_so_far_in)
    if (points[0]*10+points[1] not in cell_visited_in):
      findpathinmaze(gridsize, a, points[0], points[1], cell_visited, cell_left, path_so_far)
  
  points = []
  
  if col < gridsize - 1:
    points.append(row)
    points.append(col+1)
    cell_visited = copy.deepcopy(cell_visited_in)
    path_so_far = copy.deepcopy(path_so_far_in)
    if (points[0]*10+points[1] not in cell_visited):
      findpathinmaze(gridsize, a, points[0], points[1], cell_visited, cell_left, path_so_far)
  
  

def genstartendinmaze(gridsize, a, startend):
  #generate start point
  startend.append(random.randint(0, gridsize-1))
  startend.append(random.randint(0, gridsize-1))
  a[startend[0]][startend[1]] = 2
  #generate end point
  startend.append(random.randint(0, gridsize-1))
  startend.append(random.randint(0, gridsize-1))
  a[startend[2]][startend[3]] = 3
   
def countvalidcellinmaze(gridsize, a=[]):
  validcells = 0
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      if (a[i][j] >= 1):
        validcells += 1     
  return validcells      

  
def verifycellinmaze(gridsize, a, row, col):
  if a[row][col] < 1:
    return 0
  elif (row > 0 and  a[row-1][col] >= 1) or (col > 0 and  a[row][col-1] >= 1) or (row < gridsize-1 and  a[row+1][col] >= 1) or (col < gridsize-1 and  a[row][col+1] >= 1):
    return 1
  else:
    #print "invalid cell "+`row`+" "+`col`+""
    return 0


def verifymaze(gridsize, a=[]):
  validcell = 0
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      if (verifycellinmaze(gridsize, a, i, j)):
        validcell += 1
  return validcell      
      

def changemaze(gridsize, a=[]):
  prob = 3
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      a[i][j] = random.randint(1,10)
      if (a[i][j] > prob):
        a[i][j] = 1
      else:
        a[i][j] = 0
            
def creategrid(gridsize, a=[]):
  for i in xrange(gridsize):
    a.append([])
    for j in xrange(gridsize):
      a[i].append(i+j)
      #print "a["+`i`+"]["+`j`+"]"
      #print a[i][j]
               
# get main caller
if __name__ == '__main__':
  main()
