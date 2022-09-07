document.addEventListener('DOMContentLoaded', function () {

  document.querySelector("#submit").addEventListener("click", function () {
    var input = document.getElementById("name").value;
    document.querySelector("#feedback1").innerHTML = "Hello, " + input + ". Thank you for visiting my homepage :) My name is Louisa and i like playing soccer so this page is about women soccer.";
  });
});
