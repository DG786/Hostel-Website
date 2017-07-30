Javascript SH
**some prev stuff in CS notebook**
&& check the single page.
some KIMs-
>Node is something enclosed in tags. document is not Node.
>

IMP objects in Javascript-
event

window- 
The window object represents an open window in a browser. If a document contain frames (<iframe> tags), 
the browser creates one window object for the HTML document, and one additional window object for each frame.

	SO it is also an element! - .blur(),.focus() work on it.
	.opener => returns window that created it.
	.closed,	.length : no of iframe elements.
	.pageYOffset = pixels scrolled down.
	.close(),   .open(url,name,specs,replace); 
					name= " _top / _self/ _parent/ _blank(default)/ anyname";
					specs="status=1|0, titlebar=1/0, width=100, height=100, left=450,top=450";
					replace= true/false.
	.moveBy(Rpx,Dpx) *DNW?* , .moveTo(L,T),;
	.resizeBy(Rpx,Dpx)		, .resizeTo(W,H);
	.alert()[OK] .confirm()[Y/N], .prompt()[UserInput].
	.getSelection() - gives selected element, its properties are seen in console.
		**When you select something on page, you actually select "HTMLcode" of the page. so multiple nodes can be selected.
					-.textContent = this text is from [x.anchorOffset,x.focusOffset);
					-.toString() = gives selected text. **CHECK
					-.anchorNode (is a baseNode*) = start of selection (can be from R to L, but doubleclicked selection is from L to R).
					-
	.location - .href =url same as .assign(url), .replace(url)[cannot go back]
					href must contain protocol- "https://fb.com", it reloads there.
				.hash,host,hostname,origin(protocol+host)	
				.search = the query after & including '?' in location bar.
					this part can be edited, & it instantly reloads there.
				.reload(0) from cache, .reload(1) from server.


document


array/strings-
	var A= new Array(10) / Array(1,2,"three"); A.push("OK"); A.reverse(); A.fill(1,~start,~end);
					 bool fn checker - A.every(fn1());"fn1 also bool", A.some(fn1()) wil stop when got 1 true
	var S= "" / new String(); S+="OK, OK2"; A= S.split(","); "returns array"

IMP function -
.getElementById
.getElementsByTagName/ClassName
encodeURI(url); decodeURI(url);

var ref= setInterval(fn1,1000); / setTimeout(function(){console.log("tick");},1000);
clearTimeout(ref_to_setTimeout),clearInterval(ref_to_setInterval) 
x=document.createElement('span');	x.setAttribute(attrname,value);	
x.innerHTML,.querySelector,.textContent **FILL


