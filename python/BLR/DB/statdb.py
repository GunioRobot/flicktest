from tw import twmessage

from pymongo import Connection


def storeflightdata(querydate, journyedate, tocity, fromcity, flightlist):
    connection = Connection()
    db = connection.test_database
    collection = db.test_collection

    #print db.collection_names()
    #print collection

    for i in xrange(0,len(flightlist), 5):   
        pkey = []
        pkey.append(journyedate)
        pkey.append(fromcity)
        pkey.append(tocity)
        pkey.append(flightlist[i])
        pkey.append(flightlist[i+1])
                    
        posts = db.posts
        for post in posts.find({"id": pkey}):
            if (len(post) > 0):
                break
            else:
                post = {"id":pkey,
                        "DoJ": journyedate,
                        "From": fromcity,
                        "To": tocity,
                        "Airline":flightlist[i],
                        "Time": flightlist[i+1],
                        "DoQ" : querydate,
                        "fare": flightlist[3],
                        "duration" : flightlist[2] 
                        }
                posts.insert(post)
                break
        
    #for post in posts.find():
        #print post
        
    