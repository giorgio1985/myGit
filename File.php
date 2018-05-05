<?php
// giorgio1985
include 'dbConnector.php';
//for the usual users
if(isset($_POST['username'])&&($_POST['email'])){
$username = $_POST['username'];
$email = $_POST['email'];
$sql="SELECT username, email FROM firstLogin; # WHERE username=$username AND email=$email";
$result=mysqli_query($conn,$sql);
if($result){
echo 'Benvenuto  ' .$_POST['username'];
}
else {    echo 'Are you just logged?';   }

//if (mysqli_num_rows($out)>0) {

if (mysqli_num_rows($result) > 0) {
while ($row=mysqli_fetch_assoc($result)) {
	echo $row['username']; 
	echo '<br>';
	echo $row['email'];
	echo '<br>';
   }
}
}
//mysqli_free_result($out);
mysqli_close($conn);
?>
