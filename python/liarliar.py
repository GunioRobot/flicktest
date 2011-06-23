import sys

def addtotarray(ulist, tarray, larray, ruserhash, userhash, llist, tcount):
  for i in range(0 ,len(ulist)):
    if ulist[i] not in tarray:
      tcount+=1
      tarray[ulist[i]] = tcount      
      addtolarray(llist[userhash[ulist[i]]], larray, tarray, ruserhash, userhash, llist, tcount)
    else:
      print "already in tarray " +ulist[i]    
  
def addtolarray(ulist, larray, tarray, ruserhash, userhash, llist, tcount):
  for i in range(0 ,len(ulist)):
    if ulist[i] not in larray:
      tcount+=1
      larray[ulist[i]] = tcount
      addtotarray(llist[userhash[ulist[i]]], tarray, larray, ruserhash, userhash, llist, tcount)
    else:
      print "already in larray " +ulist[i]  
    
def findgroup(llist, tlist, ruserhash, userhash):
  print llist
  print tlist
  print ruserhash
  print userhash
  
  larray = {}
  tarray = {}
  nlist = []
  nlist.append(ruserhash[0])
  tcount = 0
  #addtotarray(nlist, tarray, larray, ruserhash, userhash, llist, tcount)
  #addtolarray(llist[0], larray, tarray, ruserhash, userhash, llist)
  
  print larray
  print tarray
    
def getinput(filename):
  f = open(filename, 'r')
  count = 0
  newuser = 1
  userhash = {}  
  ruserhash = {}
  iuserhash = {}
  ucount = 0
  icount = 0
  llist = []
  tlist = []
  for line in f:  
      liarscount = []
      if count == 0:
        total = line
      else: 
        if newuser == 1:
          #if its new user entry
          liarsname = []
          newuser = 0
          user = line.split()
          lcount = int(user[1])
          name = user[0]
          liarscount.append(line.split())           
        else:
          #if its continuous entry
          lname = line[:-1]
          liarsname.append(lname)
          if lname not in iuserhash:
            iuserhash[lname]=icount
            icount+=1
            if len(tlist) < icount:
              tlist.append(name)
              print "newtlist "+name
              print tlist
              print iuserhash
            else:  
              print "oldtlist "+name
              tlist[icount].append(name)
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
  print llist
  print tlist
  print ruserhash
  print userhash
  print iuserhash
  print "\n"
            
  findgroup(llist,tlist, ruserhash, userhash)
  
def main():
  #if len(sys.argv) == 2:
  #  fname = sys.argv[1]
  #else:
  #  sys.exit()    
  getinput("liarliar.txt")
  
# get main caller
if __name__ == '__main__':
  main()