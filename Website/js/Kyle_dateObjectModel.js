var today = new Date();
var year = today.getFullYear();
var birthdate = new Date('may 20, 1996 20:20:00');

var age = today.getTime() - birthdate.getTime();
age = Math.floor(age / 31556900000);

msg = '<p>My age is: ' + age + ' years </p>';
var elemt = document.getElementById('info');
elemt.innerHTML = msg;

var ft = document.getElementById('foot');
ft.innerHTML = '<p>Copyright &copy ' + year + '</p>';
