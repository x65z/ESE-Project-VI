var f1 = document.getElementById("f1");
var f2 = document.getElementById("f2");
var f3 = document.getElementById("f3");
var ht = document.getElementById("ht");
//var f1 = document.getElementById("b1");
//var f2 = document.getElementById("b2");
//var f3 = document.getElementById("b3");
//var ht = document.getElementById("bt");
var test ="ok";

alert("howdy ho");

f1.addEventListener("click", function(evt) {
	f1_Press();
}, false);

f2.addEventListener("click", function(evt) {
	f2_Press();
}, false);

f3.addEventListener("click", function(evt) {
	f3_Press();
}, false);

ht.addEventListener("click", function(evt) {
	ht_Press();
}, false);

function db_GetFloor(){
	var resp = 'wtf';
	echo $resp;

}

function return_Floor(data){
	alert(data);
}

function db_Submit(val){	
	/*
	var xmlhttpShow = new XMLHttpRequest();
	xmlhttpShow.onreadystatechange = function() {
	if(this.readyState == 4 && this.status == 200) {
	  
	 //var resp = this.responseText;   // Text string returned from server in 'echo' statement    
	  //document.getElementById('floor').innerHTML = resp;	  
	}
  };*/
  //xmlhttp.open("POST","EFloorSubmit.php?q="val,true);
  //xmlhttp.send();
  //alert("posted");
  $.post("../php/EFloorSubmit.php", {pval:val}, success());
}

function success()
{
	//alert (test);
}

function f1_Press()
{
	db_Submit("1");
}

function f2_Press()
{
	db_Submit("2");
}

function f3_Press()
{
	db_Submit("3");
}

function ht_Press()
{
	db_Submit("0");
}

setInterval(db_GetFloor(), 3000);
