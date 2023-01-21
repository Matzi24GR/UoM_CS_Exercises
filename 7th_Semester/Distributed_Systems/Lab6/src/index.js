'use strict'
// Import the functions you need from the SDKs you need
import { initializeApp } from 'firebase/app';
import { getFirestore, query, where, collection, doc, getDocs, setDoc } from 'firebase/firestore/lite';

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyCSG7hetVFAHL5_zFNm2yvS20VMHhA_EDA",
  authDomain: "bankapp-c25cf.firebaseapp.com",
  databaseURL: "https://bankapp-c25cf-default-rtdb.europe-west1.firebasedatabase.app",
  projectId: "bankapp-c25cf",
  storageBucket: "bankapp-c25cf.appspot.com",
  messagingSenderId: "401982052055",
  appId: "1:401982052055:web:73f5f1b98199fec1fbc292",
  measurementId: "G-SJVG20LZVH"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const db = getFirestore(app);
const usersRef = collection(db, "users")

// Elements
const usernameInput = document.getElementById("username");
const passwordInput = document.getElementById("password");
const loginButton = document.getElementById("loginButton");
const logoutButton = document.getElementById("logoutButton");
const balanceText = document.getElementById("balance");
const loggedInText = document.getElementById("loggedIn");
const withdrawButton = document.getElementById("withdrawButton");
const depositButton = document.getElementById("depositButton");
const amountInput = document.getElementById("amount");

var username = "";
var password = "";
var loggedIn = false;

logoutButton.style.visibility = "hidden";
loginButton.addEventListener("click", function () {
  checkLogin().then(() => {
    console.log(loggedIn);
    if (loggedIn) {
      username = usernameInput.value;
      password = passwordInput.value;
      loggedInText.innerText = "True"
      logoutButton.style.visibility = "visible";
      loginButton.style.visibility = "hidden";
      updateBalance();
      
    } else {
      alert("Wrong username/password");
      loggedInText.innerText = "False"
      balanceText.innerHTML = "0"
    }
  })
});

logoutButton.addEventListener("click", function () {
  balanceText.innerHTML = "0";
  usernameInput.value = "";
  passwordInput.value = "";
  balanceText.innerHTML = "0";
  loggedInText.innerHTML = "False";
  loginButton.style.visibility = "visible";
  logoutButton.style.visibility = "hidden";
  loggedIn = false;
  username = "";
  password = "";
});

withdrawButton.addEventListener("click", async function() {
  if (!loggedIn) {
    alert("Not logged in");
    return;
  } 
  var amount = amountInput.value;
  var balance = parseFloat(balanceText.innerText);
  console.log(balance);
  if (amount<0 || amount>balance) {
    alert("Invalid amount");
    return;
  }
  await setDoc(doc(db, "users", username), {
    username: username,
    password: password,
    balance: balance-amount
  })
  updateBalance();
});

depositButton.addEventListener("click", async function() {
  if (!loggedIn) {
    alert("Not logged in");
    return;
  } 
  var amount = amountInput.value;
  var balance = parseFloat(balanceText.innerText);
  console.log(balance);
  if (amount<0) {
    alert("Invalid amount");
    return;
  }
  await setDoc(doc(db, "users", username), {
    username: username,
    password: password,
    balance: balance+parseFloat(amount)
  })
  updateBalance();
});

async function updateBalance() {
  const q = query(usersRef, where("username", "==", username));
  const querySnapshot = await getDocs(q);
  querySnapshot.forEach((doc) => {
    balanceText.innerHTML= doc.get("balance");
  });
}

async function checkLogin() {
  username = "";
  var usernameTemp = usernameInput.value;
  var password = passwordInput.value;
  const q = query(usersRef, where("username", "==", usernameTemp));
  const querySnapshot = await getDocs(q);
  querySnapshot.forEach((doc) => {
    loggedIn = doc.get("password") === password;
  });
}