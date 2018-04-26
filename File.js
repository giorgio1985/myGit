function funzione(){
$(document).ready(function(){
$("#mioform").click(function(){
var username = $("#username").val();
var email = $("#email").val();
$.ajax({
type : "POST",
url : "file.php",
data : "username=" + username + "&email=" + email,
dataType : "html",
success : function(data){
$("#risposta").html(data);
},
error : function(){
alert("Qualcosa e andato storto...");
}

});
return false;
});

});
}
