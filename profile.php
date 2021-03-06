<?php
session_start();
if(!$SESSION['student_roll'])
{
    header('location:LogIndex.php');
}
?>
<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>Update Profile</title>

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

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js"></script>
    <![endif]-->

</head>

<body id="page-top" class="index">

    <!-- Navigation -->
    <nav id="mainNav" class="navbar navbar-default navbar-custom navbar-fixed-top">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header page-scroll">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span> Menu <i class="fa fa-bars"></i>
                </button>
                <a class="navbar-brand page-scroll" href="index.php">Home</a>
            </div>

            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav navbar-right">
                    <li>
                        <a href="">Log out</a>
                    </li>
                    </ul>
            </div>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container-fluid -->
    </nav>


    <!-- Header -->
    <header>
        <div class="container">
            <div class="intro-text"><center>
                <div class="intro-lead-in" style="color: yellow"><b>Update Profile</b></div><br><br>
                
                <div class="col-sm-8" style="background-color: black;opacity: 0.8;border-radius: 25px; margin-left: 20%">
                <form class="form-horizontal">
  <div class="form-group">
    <label class="control-label col-sm-2" for="email" style="font-size: 25px; color: yellow;margin-top:6%;margin-left: 10%"><em>Name:</em></label>
    <div class="col-sm-6" style="margin-top:6.8%;margin-right: 5%">
      <input type="text" class="form-control" id="email" placeholder="Enter name">
    </div>
  </div>
  <div class="form-group">
    <label class="control-label col-sm-2" for="pwd" style="font-size: 25px; color: yellow;margin-top:.3%;margin-left: 10%"><em>Roll No:</em></label>
    <div class="col-sm-6"style="margin-top:1%"> 
      <input type="number" class="form-control" id="pwd" placeholder="Enter Roll No">
    </div>
  </div>
  <div class="form-group">
    <label class="control-label col-sm-2" for="pwd" style="font-size: 25px; color: yellow;margin-left: 10%"><em>Branch:</em></label>
    <div class="col-sm-6"style="margin-top:1%"> 
      <input type="text" class="form-control" id="pwd" placeholder="Enter Branch">
    </div></div>
    <div class="form-group">
    <label class="control-label col-sm-2" for="pwd" style="font-size: 25px; color: yellow;margin-left: 10%"><em>Interests:</em></label>
    <div class="col-sm-6"style="margin-top:1%"> 
      <input type="text" class="form-control" id="pwd" placeholder="Enter Interests">
    </div>
    </div>
    <div class="form-group">
    <label class="control-label col-sm-2" for="email" style="font-size: 25px; color: yellow;margin-top:0.7%;margin-left: 10%"><em>Sports:</em></label>
    <div class="col-sm-6" style="margin-top:1%;margin-right: 1%">
      <input type="text" class="form-control" id="email" placeholder="Enter sports">
    </div>
  </div>
  <div class="form-group">
    <label class="control-label col-sm-2" for="email" style="font-size: 25px; color: yellow;margin-top:0.7%;margin-left: 10%"><em>Webmail:</em></label>
    <div class="col-sm-6" style="margin-top:1%;margin-right: 1%">
      <input type="email" class="form-control" id="email" placeholder="Enter webmail">
    </div>
  </div>
  <div class="form-group">
    <label class="control-label col-sm-2" for="email" style="font-size: 25px; color: yellow;margin-top:0.7%;margin-left: 10%"><em>POR:</em></label>
    <div class="col-sm-6" style="margin-top:1%;margin-right: 1%">
      <input type="text" class="form-control" id="email" placeholder="Enter POR">
    </div>
  </div>
  <div class="form-group"> 
    <div class="col-sm-offset-2 col-sm-10">
      <button type="submit" class="btn btn-default"style="margin-bottom: 4%;font-size: 25px">Update</button>
    </div>
  </div>
</form></p>
                
            </div></center>
        </div>
    </header>

    
    
        <!-- jQuery -->
    <script src="vendor/jquery/jquery.min.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="vendor/bootstrap/js/bootstrap.min.js"></script>

    <!-- Plugin JavaScript -->
    <script src="http://cdnjs.cloudflare.com/ajax/libs/jquery-easing/1.3/jquery.easing.min.js"></script>

    <!-- Contact Form JavaScript -->
    <script src="js/jqBootstrapValidation.js"></script>
    <script src="js/contact_me.js"></script>

    <!-- Theme JavaScript -->
    <script src="js/agency.min.js"></script>

</body>

</html>
