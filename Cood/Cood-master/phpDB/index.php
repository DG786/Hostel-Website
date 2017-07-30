<script src="/jquery.min.js"></script>
<script>
function choiceAjax(){
		var choice=$("#choice").val();
		var query=$("#query").val();
		console.log(choice,query);
		$.ajax({
		url: "getRoll.php",
		type:"get",
		data: {"roll":1023,"choice":choice,"query":query},
		success: function(resp){
			// console.log(resp);
			if(resp.trim()=="")resp="\n No Student with this Data.";
			$("#table").html(resp);
		},
	});

}
function doAjax(proc_val){
		$("#roll").val(proc_val);
		$.ajax({
		url: "getRoll.php",
		type:"get",
		data: {"roll":proc_val},
		success: function(resp){
			// console.log(resp);
			if(resp.trim()=="")resp="\n No Student with this Roll.";
			$("#table").html(resp);
		},
	});
}
function update(val){
	var maxClassStrength=100;
	var proc_val= (parseInt(val/1000))*1000 + (val/10)%maxClassStrength;
	doAjax(proc_val);
	document.cookie="curr_roll="+proc_val; //update the cookie on change
}

function getCookieData() {
	var name = "curr_roll=";
	var ca = document.cookie.split(';');
	for(var i = 0; i <ca.length; i++) {
		var c = ca[i];
        while (c.charAt(0)==' ') { //trim
        	c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
        	return parseInt(c.substring(name.length,c.length));
        }
    }
    //else
    return 1021;
}
window.onload=function (){
	//restore data from cookie
	$("#roll").val(getCookieData());
	$("#rollslide").val(getCookieData());

}
</script>
<form action="getRoll.php" method="get">
	<pre>
		<br>
		<br>
		Last four digits: <input type="range" min="1000" step="10" oninput="update(this.value)" max="9999" id="rollslide" style="width:50%" value="1021"/>
		<br>
		Roll Number : <span style="font-size:18px">15010</span> <input type="number" id ="roll" name="roll" value="1021"/>


		Choose <select id ="choice" name="choice">
		<option  value="1"> Name</option>
		<option  value="2"> Gender</option>
		<option  value="3"> Dept</option>
		<option  value="4"> Hostel</option>
	</select>    <input type="text" id ="query" name="query" value="uday"/>  <button type="button" onclick="choiceAjax()">Search</button><br><br>	
	
<div id="table">Slide it to get a name</div>
</pre>
</form>