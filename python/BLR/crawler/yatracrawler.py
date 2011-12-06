import pycurl
import httplib2
import re

def parseprice(pricetext, flightfare):
    prices = re.split("pricePerAdd=", pricetext)
    newp = re.split(">", prices[1]) 
    for p in newp:
        absp = re.split("\.",p[1:])
        flightfare.append(absp[0])
        #print absp[0]
        break

def getflightduration(flighttext,flightduration):
    temp = re.split("flt-duration-new-UI", flighttext,4)
    #name = re.split("</strong>", temp[1], 2) 
    t = re.split("<br/>", temp[1], 2)
    time = re.split("<p>", t[0], 2)
    flightduration.append(time[1])
    
    
def getflighttime(flighttext, flighttime):
    temp = re.split("<strong>", flighttext,4)
    #name = re.split("</strong>", temp[1], 2) 
    flighttime.append(temp[2][:5])
           
def getflightname(flighttext, flightname):
    temp = re.split("<strong>", flighttext,2)
    name = re.split("</strong>", temp[1], 2) 
    flightname.append(name[0])

def parseflight(flighttext,flightname, flightduration, flighttime):
    getflightname(flighttext, flightname)
    getflighttime(flighttext, flighttime)
    getflightduration(flighttext,flightduration)
    
    #print flighttext
    #print " "

def parsetable(table, flightname, flightduration, flighttime, flightfare):
    #print table
    i = 0
    rows = re.split("ActualAmt_", table)
    for r in rows:
        #print r
        if ( i == 0):
            parseflight(r, flightname, flightduration, flighttime)
        elif(i == 1):
            parseprice(r, flightfare)    
        #print i
        i = i + 1
    
def getpage(finallist, journeydate, fromcity, tocity):
    flightname = []
    flighttime = []
    flightduration = []
    flightfare = []
    
    h = httplib2.Http(".cache")
    strlist = []
    #journyedate = "25/11/2011"
    #fromcity = "BLR"
    #tocity = "AMD"
    
    
    strlist.append("http://domesticflights.yatra.com/flight/dom?depart_city_1=")
    strlist.append(fromcity)
    strlist.append("&destination_city_1=")
    strlist.append(tocity)
    strlist.append("&flight_depart_date_1=")
    strlist.append(journeydate)
    strlist.append("&class_1=E&ADT=1&CHD=0&INF=0&type=O&siteLanguage=en_IN&multiplyFactor=1&eVar45=SEM:")
    link =  "".join(strlist)
    #print strlist
    
    resp, content = h.request(link, "GET")
    tables = re.split("<table width", content)
    i = 0
    for t in tables:
        if (i > 0 and i < 6):
            parsetable(t, flightname, flightduration, flighttime, flightfare)
        i = i + 1
    
    j = 0 
    for j in range(len(flighttime)):
        finallist.append(flightname[j].rstrip())
        finallist.append(flighttime[j].rstrip())
        finallist.append(flightduration[j].rstrip())
        finallist.append(flightfare[j].rstrip())
        finallist.append("|")
    
            