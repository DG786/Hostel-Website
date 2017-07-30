<?php 
$link=mysql_connect("localhost","root","");
mysql_select_db("student",$link);

$result=mysql_query("SELECT * FROM student_roll",$link);

for($i=0;$i<5;$i++)
{	echo "<h1>Student</h1>";
	for($j=0;$j<=2;$j++)
{echo mysql_result($result, $i, $j);
	echo "<br>";
}echo "<br>";
}

?>