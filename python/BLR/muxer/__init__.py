from crawler import yatracrawler
from DB import statdb
from dateutil import *
import time 
import datetime
from tw import twmessage


def main():
    one_month = datetime.timedelta(days=30)
    
    jdate = datetime.date.today() + one_month 
    yr =  jdate.year
    mo =  jdate.month
    da = jdate.day
    
    finallist = [] 
    journyedate = ""
    journyedate += str(da) + "/" + str(mo) + "/" + str(yr) 
    
    fromcity = "BLR"
    tocity = "AMD"
    yatracrawler.getpage(finallist, journyedate, fromcity, tocity)
    
    #print finallist    
    querydate = "06/11/2011"
    statdb.storeflightdata(querydate, journyedate, tocity, fromcity, finallist)
    
    twmessage.PostMessage(journyedate, finallist)
    


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
    main()