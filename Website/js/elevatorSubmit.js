

var f1 = document.getElementById("f1");
var f2 = document.getElementById("f2");
var f3 = document.getElementById("f3");
var ht = document.getElementById("ht");

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


function db_Request(val){
  $.post("../php/EFloorSubmit.php", {pval:val}, success());
}

function db_Logger(val) {
	 $.post("../php/EdebugLogger.php", {pval:val}, success());
}


function success()
{
	//alert (test);
}

function f1_Press()
{
	db_Request("1");
	db_Logger("1");
}

function f2_Press()
{
	db_Request("2");
	db_Logger("2");
}

function f3_Press()
{
	db_Request("3");
	db_Logger("3");
}

function ht_Press()
{
	db_Request("0");
	db_Logger("0");
}
