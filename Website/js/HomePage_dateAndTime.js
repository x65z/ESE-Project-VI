var today = new Date(); //By default takes todays date and time populated into it

msg = '<p>Todays date and current time is: </p>'; // message that will take over the text feild in the HTML file with ID "date"
var elemt = document.getElementById('date');      // Creates the variable that will take the location of the text feild
elemt.innerHTML = msg;                            // places the message and overrides the text hardcoded in with the HTML file

var elemt1 = document.getElementById('info');
elemt1.innerHTML = today;

var ft = document.getElementById('foot');
ft.innerHTML = '<p>Copyright &copy ' + year + '</p>';
