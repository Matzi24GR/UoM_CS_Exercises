'use strict'
fetch("http://localhost:81/users").then( response=> {
  return response.json()
}).then( data=> {
  console.log(data)
})

function login() {
  var username = document.getElementById("username").value
  var password = document.getElementById("password").value
  fetch("http://localhost:81/login", {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      'username': username,
      'password': password
    })
  })
  .then( response => response.text() )
  .then( data => {
    if (data.length==0) {
      document.getElementById("loggedIn").innerHTML= "True"
      updateBalance()
    }
  })
  return false
}

function updateBalance() {
  var username = document.getElementById("username").value
  fetch("http://localhost:81/check", {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      'username': username
    })
  })
  .then( response => response.text() )
  .then( data => {
      document.getElementById("balance").innerHTML= data
  })
}

function withdraw() {
  var username = document.getElementById("username").value
  var amount = document.getElementById("withdrawAmount").value
  fetch("http://localhost:81/withdraw", {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      'username': username,
      'amount': amount
    })
  })
  .then( response => response.text() )
  .then( data => {
      console.log(data)
      updateBalance()
  })
}

function deposit() {
  var username = document.getElementById("username").value
  var amount = document.getElementById("depositAmount").value
  fetch("http://localhost:81/deposit", {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      'username': username,
      'amount': amount
    })
  })
  .then( response => response.text() )
  .then( data => {
      console.log(data)
      updateBalance()
  })
}