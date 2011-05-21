import sys

def addtotarray(ulist, tarray, ruserhash, userhash, llist):
  for i in range(0 ,len(ulist)):
    if ulist[i] not in tarray:
      tarray[ulist[i]] = i
      
  
def addtolarray(ulist, larray, ruserhash, userhash, llist):
  for i in range(0 ,len(ulist)):
    if ulist[i] not in larray:
      larray[ulist[i]] = i
    
def findgroup(llist, ruserhash, userhash):
  print llist
  print ruserhash
  
  larray = {}
  tarray = {}
  nlist = []
  nlist.append(ruserhash[0])
  addtotarray(nlist, tarray, ruserhash, userhash, llist)
  addtolarray(llist[0], larray, ruserhash, userhash, llist)
  
  print larray
  print tarray
    
def getinput(filename):
  f = open(filename, 'r')
  count = 0
  newuser = 1
  userhash = {}  
  ruserhash = {}
  ucount = 0
  llist = []
  for line in f:  
      liarscount = []
      if count == 0:
        total = line
      else: 
        if newuser == 1:
          liarsname = []
          newuser = 0
          user = line.split()
          lcount = int(user[1])
          name = user[0]
          liarscount.append(line.split())           
        else:
          lname = line[:-1]
          liarsname.append(lname)
          #print line
          lcount-=1
          if lcount == 0:
            newuser = 1
            if name not in userhash:
              userhash[name]=ucount
              ruserhash[ucount]=name
              ucount+=1
              llist.append(liarsname)
            
      count+=1      
  findgroup(llist, ruserhash, userhash)
  
def main():
  #if len(sys.argv) == 2:
  #  fname = sys.argv[1]
  #else:
  #  sys.exit()    
  getinput("liarliar.txt")
  
# get main caller
if __name__ == '__main__':
  main()