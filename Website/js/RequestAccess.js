//Form validation vars start
var rform = document.getElementById("raform");
var fname = document.getElementById("fname");
var fnamewarn = document.getElementById("fnamewarn");
var lname = document.getElementById("lname");
var lnamewarn = document.getElementById("lnamewarn");
var email = document.getElementById("email");
//var web = //optional?
var dob = document.getElementById("dob");
var rtype1 = document.getElementById("r1");
var rtype1 = document.getElementById("r2");
//Char count vars start
var txtID = document.getElementById("txtDetails");
var remID = document.getElementById("remainingWarn");
var charCount = 180;
remID.classList.add("Hidden");

function txtAreaWarn() {	//function for counting remaining characters in "other details"
	
	if (txtID.value.length > 0){
		
		charCount = 180 - txtID.value.length
		//alert(remID.innerHTML)
		//alert(txtID.value.length)
		remID.innerHTML = charCount.toString() + " characters remaining.";
		remID.classList.remove("Hidden");
	} else {
		remID.classList.add("Hidden");
	}
}

function checkfn(event){
	//alert(fname.value.length) //debug
	if (fname.value.length < 1){
		//add warn text
		fnamewarn.innerHTML = "*First name required.";
		event.preventDefault();
	} else{
		//remove warn text
		fnamewarn.innerHTML = "";
	}
}

function checkln(event){
	//alert(lname.value.length) //debug
	if (lname.value.length < 1){
		//add warn text
		lnamewarn.innerHTML = "*Last name required.";
		event.preventDefault();
	} else{
		//remove warn text
		lnamewarn.innerHTML = "";
	}
}

rform.addEventListener('submit', function(event) {checkfn(event); checkln(event);}, false);