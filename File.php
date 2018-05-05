<?php
// giorgio1985
include 'dbConnector.php';
//for the usual users
if(isset($_POST['username'])&&($_POST['email'])){
$username = $_POST['username'];
$email = $_POST['email'];
$sql="SELECT username, email FROM firstLogin WHERE username=$username AND $email=$email";
mysqli_query($conn,$sql);
if($sql){
echo 'Benvenuto  ' .$_POST['username'];
}else
echo 'Are you just logged?';

}

mysqli_close($conn);


?>
