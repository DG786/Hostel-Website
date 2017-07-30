<?php
$file = fopen("btechhostelcsv.csv","r");
$offset=150100000;
$index = 0 ;
$DATA="";
$OpenLine="";
$finished="<BR>Search finished.<BR>";
if(!isset($_GET['roll']))$input=150101021;
else  $input=$_GET['roll']+$offset;

if(isset($_GET['query']) && isset($_GET['choice'])){
	$choice=$_GET['choice'];
	if($choice!=0){
		$input=$_GET['query'];
		$index=(int)$choice;
	}
}	

//reach that line
$line=fgetcsv($file);
$i=0;while(array_key_exists($i,$line))$OpenLine.= $line[$i++]." &emsp;";$OpenLine.= "<BR>";

while(!(feof($file) )){
	if (strpos(strtoupper($line[$index]), strtoupper($input)) !== false){
		//print matching lines
		$i=0;while(array_key_exists($i,$line))$DATA.= $line[$i++]." ";$DATA.= "<BR>";
	}
	$line=fgetcsv($file);
}
fclose($file);
echo $OpenLine;
echo $DATA;
echo $finished;
?>