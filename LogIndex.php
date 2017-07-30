  


<html lang = "en">

<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<meta name="description" content="">
	<meta name="author" content="">

	<title>LogIndex</title>

	<!-- Bootstrap Core CSS -->
	<link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

	<!-- Custom Fonts -->
	<link href="vendor/font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css">
	<link href="https://fonts.googleapis.com/css?family=Montserrat:400,700" rel="stylesheet" type="text/css">
	<link href='https://fonts.googleapis.com/css?family=Kaushan+Script' rel='stylesheet' type='text/css'>
	<link href='https://fonts.googleapis.com/css?family=Droid+Serif:400,700,400italic,700italic' rel='stylesheet' type='text/css'>
	<link href='https://fonts.googleapis.com/css?family=Roboto+Slab:400,100,300,700' rel='stylesheet' type='text/css'>

	<!-- Theme CSS -->
	<link href="css/agency.min.css" rel="stylesheet">

	<style type="text/css">
	.details{

        color: white; 
        margin:10%9%-5%0%;
        opacity: 1;
      }

		#main {
			width:960px;
			margin:50px auto;
			font-family:raleway
		}
		span {
			color:red
		}
		h2 {
			background-color:#FEFFED;
			text-align:center;
			border-radius:10px 10px 0 0;
			margin:-10px -40px;
			padding:15px
		}
		hr {
			border:0;
			border-bottom:1px solid #ccc;
			margin:10px -40px;
			margin-bottom:30px
		}
		#login {
			width:300px;
			float:left;
			border-radius:10px;
			font-family:raleway;
			border:2px solid #ccc;
			padding:10px 40px 25px;
			margin-top:70px
		}
		input[type=text],input[type=password] {
			width:99.5%;
			padding:10px;
			margin-top:8px;
			border:1px solid #ccc;
			padding-left:5px;
			font-size:16px;
			font-family:raleway
		}
		input[type=submit] {
			width:100%;
			background-color:#FFBC00;
			color:#fff;
			border:2px solid #FFCB00;
			padding:10px;
			font-size:20px;
			cursor:pointer;
			border-radius:5px;
			margin-bottom:15px
		}
		#profile {
			padding:50px;
			border:1px dashed grey;
			font-size:20px;
			background-color:#DCE6F7
		}
		#logout {
			float:right;
			padding:5px;
			border:dashed 1px gray
		}
		a {
			text-decoration:none;
			color:#6495ed
		}
		i {
			color:#6495ed
		}
	</style>
	<title>Login</title>
	<link href="style.css" rel="stylesheet" type="text/css">
</style>
</head>
<body id="page-top" class="index">
<?php
   if($_POST)
   {
   	$host="localhost";
   	$user="root";
   	$pass="";
   	$db="student";
   	$roll_number=$_POST['roll_number'];
   	$password=$_POST['password'];
   	$conn=mysqli_connect($host,$user,$pass,$db);
   	$querry="SELECT * from student_roll where Roll_Number='$roll_number' and password='$password'";
   	$result=mysqli_query($conn,$querry);
   	if(mysqli_num_rows($result)==1)
   	{
   		session_start();
   		$_SESSION['student_roll']='true';
   		header('location:profile.php');
   	}
   	else{echo '<center><h4 class="details">wrong roll number or password<h4></center>';}
   }
?>
<link href="style.css" rel="stylesheet" type="text/css">
 <nav id="mainNav" class="navbar navbar-default navbar-custom navbar-fixed-top">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header page-scroll">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span> Menu <i class="fa fa-bars"></i>
                </button>
                <a class="navbar-brand page-scroll" href="index.php">HOME</a>
            </div>

            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container-fluid -->
    </nav>
<div id="main" style="width:30%">
	<div id="login" style="background:black;opacity:0.7">

		<br>
		<center><img src="Dihing_logo.jpg" alt="Logo" style="width:50px;height:80px;opacity:1;"></center>
		<br>
		<center><h8 style="color:white;background:black;opacity:0.7"><b><i>Login Form</i></b></h8></center>
		<br>
		<br>
		<center><form method="POST" style="background:black;opacity:0.8">
			<input type = "text" class = "form-control" name = "roll_number" placeholder = "Roll number" required autofocus>
			<input type = "password" class = "form-control" name = "password" placeholder = "password" required>
			<br>
			<br>

			<center><button class="btn btn-xl" type = "submit" name = "login">Login</button></center>
		</form></center>
	</div>
</div>
</body>
