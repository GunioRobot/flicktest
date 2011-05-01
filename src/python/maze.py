import sys
import random
import copy

#Approach: Start is defined as 2, end is defined as 3.
#          normal node is 1 and absent node is 0

# Define a main() function that prints a little greeting.
def main():
  # Get the name from the command line, using 'World' as a fallback.
  if len(sys.argv) >= 2:
    name = sys.argv[1]
  else:
    name = 'World'
  print 'Hello', name
  
  a = []
  
  gridsize = 5;
  #create grid of size gridsize
  creategrid(gridsize, a)
  
  #fill some random 1 and 0
  changemaze(gridsize, a)
  startend = []
  #generate start and end cell
  genstartendinmaze(gridsize, a, startend)
  
  cell_visited = copy.deepcopy(a)
  cell_left = copy.deepcopy(a)
  
  path_so_far = []
  path_so_far.append(startend[0])
  path_so_far.append(startend[1])
  
  #make sure all cells are reachable
  if (verifymaze(gridsize, a) != countvalidcellinmaze(gridsize,a)):
    print "unreachable cells"
  else:
    print "possibly valid grid"
        
  findpathinmaze(gridsize, a, startend, cell_visited, cell_left, path_so_far)    
  print a  
  print cell_visited
  
def findpathinmaze(gridsize, a, startend, cell_visited, cell_left, path_so_far):
  cell_visited[startend[0]][startend[1]] = -1
  print path_so_far
  

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
    print "invalid cell "+`row`+" "+`col`+""
    return 0


def verifymaze(gridsize, a=[]):
  validcell = 0
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      if (verifycellinmaze(gridsize, a, i, j)):
        validcell += 1
  return validcell      
      

def changemaze(gridsize, a=[]):
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      a[i][j] = random.randint(1,10)
      if (a[i][j] > 3):
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
