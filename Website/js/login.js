var UNID = document.getElementById("Username");
var PassWID = document.getElementById("Password");
var UlengthID = document.getElementById("Username_Warning");
var PlengthID = document.getElementById("Password_Warning");
//var PlengthID2 = document.getElementById("Special_PW_Warning");
var hasNumber = /\d/;

//alert("howdy ho");

PassWID.addEventListener("keyup", function(evt) {
	passwordValidate();
}, false);

UNID.addEventListener("keyup", function(evt) {
	userNameValidate();
}, false);

function userNameValidate() {
	//alert(UNID.value.length);
	if (UNID.value.length < 7 && UNID.value.length > 0){
		UlengthID.innerHTML = 'Username must be 7 characters long';
	} else {
		UlengthID.innerHTML = '';
	}
}
function passwordValidate() {
	//alert(PassWID.value.length);
	if (PassWID.value.length < 7 && PassWID.value.length > 0){
		PlengthID.innerHTML = 'Password must be 7 characters long';
	} else {
		PlengthID.innerHTML = '';
	}
	//alert("t");
	//alert(hasNumber.test(PassWID.value));
	//if (hasNumber.test(PassWID.value) && PassWID.value != PassWID.value.toLowerCase()){ //check for Uppercase + Number disabled
	//	PlengthID2.innerHTML = '';
	//} else {
	//	PlengthID2.innerHTML = 'Password must contain one uppercase letter and one number.';
	//}
}

function checkSubmit(){
	if (UNID.value.length > 0 && PassWID.value.length > 0 && UlengthID.innerHTML == '' && PlengthID.innerHTML == '' && PlengthID2.innerHTML == ''){
		//alert("Debug: submit OK")
	}else{
		//alert("Debug: submit blocked")
		event.preventDefault();
	}
}

window.onload = function() {
	var input = document.getElementById("Username").focus();
}

login.addEventListener('submit', function(event) {checkSubmit(event);}, false);
