<?php
	$link=mysql_connect("localhost","root","");
	mysql_select_db("student",$link);
	$r=mysql_query("SELECT Serial_Number * FROM student_roll WHERE password='$_POST[password]' OR Roll_Number='$_POST[roll_number]'",$link);
	$result=mysql_query("SELECT * FROM student_roll WHERE password='$_POST[password]' OR Roll_Number='$_POST[roll_number]'",$link);
	?>