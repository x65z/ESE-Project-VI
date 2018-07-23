
function showFloor() {
  var xmlhttpShow = new XMLHttpRequest();

  xmlhttpShow.onreadystatechange = function() {
    if(this.readyState == 4 && this.status == 200) {

      var resp = this.responseText;

      document.getElementById('floor').innerHTML = resp;

    }
  };
  xmlhttpShow.open("GET", "../php/showFloor.php?q=", true);
  xmlhttpShow.send();
}


function showFloorInterval(millisec) {
    setInterval(showFloor, millisec);
}
