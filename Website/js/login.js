var PassWID = document.getElementById("PassW");
var UNID = document.getElementById("UserN");
var PlengthID = document.getElementById("PSWLengthWarn");
var UlengthID = document.getElementById("UNLengthWarn");
PlengthID.classList.add("Hidden");
UlengthID.classList.add("Hidden");

PassWID.addEventListener("keyup", function(evt) {
	passwordValidate();
}, false);

UNID.addEventListener("keyup", function(evt) {
	userNameValidate();
}, false);


function passwordValidate() {			
	//alert(PassWID.value.length);
	if (PassWID.value.length < 7 && PassWID.value.length > 0){
		PlengthID.classList.remove("Hidden");
	} else {
		PlengthID.classList.add("Hidden");
	}
}
function userNameValidate() {			
	//alert(PassWID.value.length);
	if (UNID.value.length < 7 && UNID.value.length > 0){
		UlengthID.classList.remove("Hidden");
	} else {
		UlengthID.classList.add("Hidden");
document.getElementById("myBtn").addEventListener
	}
}
window.onload = function() {
	var input = document.getElementById("UserN").focus();
}