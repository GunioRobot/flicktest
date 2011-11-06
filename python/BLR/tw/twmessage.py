import twitter
def PostMessage(message):
    api = twitter.Api(consumer_key='ZSYhfqEqtccLBxVSivinw',consumer_secret='LBHhp2HF6ULGDYDS2QrIkQyi8vl6JielZ78FpbZq2vg', access_token_key='391348703-r09HWepnyeeqEeGwKC17IoiG7d7NyhmnUbbEXY6m', access_token_secret='uzv5pGDaJqIpbQA89ca9z0HO0O2Jb3GKfo0YKeXveDk')
    print twitter.__file__
    status = api.PostUpdate(message)
    print status
