import sys
import requests
import json
def main(argv):
    q = argv[0]
    # Take + signs and replace them with %2B
    q = q.replace('+', '%2B')
    url = "http://challenge-server.code-check.io/api/hash?q=" + q
    response = requests.get(url)
    json = response.json()
    print(json["hash"])