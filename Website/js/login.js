var PassWID = document.getElementById("PassW");
var UNID = document.getElementById("UserN");
var PlengthID = document.getElementById("PSWLengthWarn");
var UlengthID = document.getElementById("UNLengthWarn");
PlengthID.classList.add("Hidden");
UlengthID.classList.add("Hidden");
function passwordValidate() {			
	//alert(PassWID.value.length);
	if (PassWID.value.length < 7){
		PlengthID.classList.remove("Hidden");
	} else {
		PlengthID.classList.add("Hidden");
	}
}
function userNameValidate() {			
	//alert(PassWID.value.length);
	if (UNID.value.length < 7){
		UlengthID.classList.remove("Hidden");
	} else {
		UlengthID.classList.add("Hidden");
	}
}
window.onload = function() {
	var input = document.getElementById("UserN").focus();
}