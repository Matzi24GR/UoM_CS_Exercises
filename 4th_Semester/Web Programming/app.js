'use strict'
const img = document.querySelector('img');
if (document.querySelector('input[name="color"]')) {
    document.querySelectorAll('input[name="color"]').forEach((elem) => {
      elem.addEventListener("change", function(event) {
        var item = event.target.value;
        console.log(item);
        img.setAttribute('src', 'img/case_'+item+'.jpeg');
      });
    });
  }