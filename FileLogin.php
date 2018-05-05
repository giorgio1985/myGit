<?php
//this file is used for the first users login
//giorgio1985
include 'dbConnector.php';

if(isset($_POST['nome'], $_POST['cognome'],$_POST['username'], $_POST['email'])){
echo 'Wellcome mr mss : ' .$_POST['username'];
echo  'name is: ' .$_POST['nome'];


$nome=$_POST['nome'];
$cognome=$_POST['cognome'];
$username=$_POST['username'];
$email=$_POST['email'];

echo '  username ' .$username;
echo ' email ' .$email;

$sql="INSERT INTO firstLogin(nome,cognome,username,email)VALUES('$nome','$cognome','$username','$email')";
mysqli_query($conn,$sql);
}

mysqli_close($conn);


?>
