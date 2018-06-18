var today = new Date();
var year = today.getFullYear();
var birthdate = new Date('October 6, 1992 20:30:00');

var age = today.getTime() - birthdate.getTime();
age = Math.floor(age / 31556900000);

msg = '<p>My age is: ' + age + ' years </p>';
var elemt = document.getElementById('info');
elemt.innerHTML = msg;

var ft = document.getElementById('foot');
ft.innerHTML = '<p>Copyright &copy ' + year + '</p>';
