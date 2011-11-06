from crawler import yatracrawler
from DB import statdb
 


def main():
    finallist = [] 
    journyedate = "25/11/2011"
    fromcity = "BLR"
    tocity = "AMD"
    yatracrawler.getpage(finallist, journyedate, fromcity, tocity)
    
    print finallist    
    querydate = "06/11/2011"
    statdb.storeflightdata(querydate, journyedate, tocity, fromcity, finallist)


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
    main()