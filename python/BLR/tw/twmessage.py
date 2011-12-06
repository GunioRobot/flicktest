import twitter

def PostMessage(jdate, message):
    api = twitter.Api(consumer_key='ZSYhfqEqtccLBxVSivinw',consumer_secret='LBHhp2HF6ULGDYDS2QrIkQyi8vl6JielZ78FpbZq2vg', access_token_key='391348703-r09HWepnyeeqEeGwKC17IoiG7d7NyhmnUbbEXY6m', access_token_secret='uzv5pGDaJqIpbQA89ca9z0HO0O2Jb3GKfo0YKeXveDk')
    #print twitter.__file__
    
    #print message
    
    
    data = ""
    data += jdate
    i = 1
    
    for w in message:
        
        if (i % 5 == 3):
            data += ""
        elif (i % 5 == 4):
            data += "Rs. "
            data += w
            data += " "
        elif (i % 5 == 1):
            data += w[:8]
            data += " "
        else:
            data += w
            data += " "
        i += 1
        
    print data
    
    status = api.PostUpdate(data[:140])
    print status
    #messages = api.GetDirectMessages('jac099')   
    #for dm in messages:
    #    print dm 
