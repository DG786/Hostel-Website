<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>Student Info</title>

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
<script>
    function insertTable(cellData,divID,black){

      var start=0;
      var tableContainer=document.getElementById(divID);
      var table1= document.createElement('table');
      table1.className="table table-bordered";
      var tableHeight=cellData.length-start,tableWidth=cellData[start+1].length;

      for(var i=start;i<tableHeight;i++){
        var current_row=table1.insertRow();
        if(i==start && black){
          current_row.style="background:black;color:white";
        }
        for(var j=0; j<tableWidth;j++){
          var current_col=current_row.insertCell();
          current_col.innerHTML='<strong>'+cellData[i%tableHeight][j%tableWidth]+'</strong>';
        }
      }
      tableContainer.appendChild(table1);
    }

  </script>
</head>

<body id="page-top" class="index" background="hostels.jpg" style="background-repeat:no-repeat;background-attachment:fixed;background-size:100%">

    <!-- Navigation -->
    <nav id="mainNav" class="navbar navbar-default navbar-custom navbar-fixed-top">
        <div class="container">
            <!-- Brand and toggle get grouped for better mobile display -->
            <div class="navbar-header page-scroll">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span> Menu <i class="fa fa-bars"></i>
                </button>
                <a class="navbar-brand page-scroll" href="index.php">HOME</a>
            </div>

            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                <ul class="nav navbar-nav navbar-right">
                    <li>
                        <a href="LogIndex.php">LogIn</a>
                    </li>
                </ul>
            </div>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container-fluid -->
    </nav>
    <div class="col-md-10">
            <div class="intro-text" >
        <center><form action="search.php" style="background:black;margin:12%0%0%18%;opacity:0.7" method="POST">
        <div class="container-1100 main-container">
<hgroup class="headline">
<h1 style="font-size:72px;color: white"><strong>Hostel Student Search</strong></h1>
<h3 style="padding-left:20%;margin-right:200px;color: white;font-size:25px">Photo, Roll Number, Branch, Contact Information</h3>
</hgroup>
<center><div id="table" class="col-md-10" style="margin:0%0%0%5%">    
</div></center>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
   <input type="submit" href="search.php" style="margin-bottom:3%;padding-left:3%;padding-right:3%;background:#3377ff;color:white">
<h6 style="padding-left:20%;margin-right:200px;color: white;font-size:10px">*Search by roll number or by name</h6>
   </div>
   </div>
   </div>
   </div>
</form>
</div>
        </div>
        </center>

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
    <script type="text/javascript">
    function makeBox(Cred){
   var but= '<label style="color:white;font-size:20px">'+Cred+'</label>';
      return but;
  }
   function makeInput(text,ex,name){
   var but= '<input type="'+text+'" maxlength="30" name="'+name+'" value="" placeholder="'+ex+'" />';
      return but;
  }
  var cellData2=[
  [makeBox("name"),makeBox("Roll Number")],
  [makeInput("text","Akash Shanker","Name"),makeInput("Number","150107004","Roll_Number")],
  ] ;
  insertTable(cellData2,"table",0);
</script>

</body>

</html>