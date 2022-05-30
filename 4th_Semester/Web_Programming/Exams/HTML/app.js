'use strict'
const score1 = document.getElementById("score1");
const score2 = document.getElementById("score2");
document.querySelectorAll('button').forEach((elem) => {
    elem.addEventListener("click", function(event) {
        if (elem.parentNode == score1.parentNode) {
            score1.innerHTML = parseInt(score1.innerHTML) + parseInt(elem.name);
        }
        if (elem.parentNode == score2.parentNode) {
            score2.innerHTML = parseInt(score2.innerHTML) + parseInt(elem.name);
        }
    });
})