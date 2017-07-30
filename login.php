<?php
$link=mysql_connect("localhost","root","");
mysql_select_db("student",$link);
$result=mysql_query("SELECT * FROM student_roll",$link);
for($i=0;$i!='\0';$i++)
{
    if((mysql_result($result, $i, 3))==$_POST['roll_number'])
    {
        if((mysql_result(($result), $i, 10))==$_POST['password'])
           header('Location: ./profile.php');
       else
        echo "incorrect password";
}
else
{
    echo "incorrect roll number";
}
}

?>