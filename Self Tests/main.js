/*
Call an API as follows:
The host is http://challenge-server.code-check.io/
Endpoint: /api/hash
HTTP Method: GET
Parameters (Query): 
    - q: a string to be hashed (required)
Response: 
    a JSON object with the following properties:
    - q: the given string
    - hash: the hash of the given string
When the API is successfully invoked, 200 OK is returned in JSON format.
When the API is not invoked, 400 Bad Request is returned in JSON format.
Thw generated hash will always be the same for the same string.
Ex.
{"q":"hoge", "hash":"ac0030f68eee4280a8cff568b36dc7e8944880fcab1eadd9220c6c583939baf8"}
*/
// Node js
"use strict";
// Call the API
async function main(argv) {
    let q = argv[0]
    let url = "http://challenge-server.code-check.io/api/hash?q=" + q
    // Fetch using node js
    const fetch = require("node-fetch");
    let response = await fetch(url);
    let json = await response.json();
    console.log(json);
}
// Fetch using python
// import requests
// import json
// q = "hoge"
// url = "http://challenge-server.code-check.io/api/hash?q=" + q
// response = requests.get(url)
// json = response.json()
// print(json["hash"])
// Take in account using + signs:
// 
