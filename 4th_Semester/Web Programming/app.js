'use strict'
const img = document.querySelector('img');
const priceText = document.getElementById('priceText');
const baseCost = 200;

let processorCost = 0;
let graphicsCost = 0;
let ramCost = 0;
let storageCost = 0;

refreshCost();

document.querySelectorAll('input[name="color"]').forEach((elem) => {
  elem.addEventListener("change", function(event) {
    var item = event.target.value;
    console.log(item);
    img.setAttribute('src', 'img/case_'+item+'.jpeg');
  });
})

document.querySelectorAll('input[name="processor"]').forEach((elem) => {
  elem.addEventListener("change", function(event) {
    processorCost = event.target.value;
    refreshCost();
  });
})

document.querySelectorAll('input[name="graphics"]').forEach((elem) => {
  elem.addEventListener("change", function(event) {
    graphicsCost = event.target.value;
    refreshCost();
  });
})

document.querySelectorAll('input[name="ram"]').forEach((elem) => {
  elem.addEventListener("change", function(event) {
    ramCost = event.target.value;
    refreshCost();
  });
})

document.querySelectorAll('input[name="storage"]').forEach((elem) => {
  elem.addEventListener("change", function(event) {
    storageCost = event.target.value;
    refreshCost();
  });
})

function refreshCost() {
  let total = baseCost + +processorCost + +graphicsCost + +ramCost + +storageCost;
  priceText.innerText = "Price: $" + total;
}