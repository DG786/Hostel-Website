new project =django-admin.py startproject mysite
First Time => mkvirtualenv myproject 
Next time -> workon myproject 
**THIS SAVES PROXY SETTINGS TOO, DO THIS BEFORE INSTALLING STUFF WITH 'pip install'
(myproject)> then-
new app = $ python manage.py startapp [appname]
then add appName in settings.py to the INSTALLED_APPS tuple
 in our project settings.py file. [can add musicApp.apps.MusicappConfig (as defined in /music/apps.py) which contains name]

Then once you made models.py, do the Migrations(see ahead).

models.py => Blueprints of how you are storing your data.
=>Every model inherits from models.Model
in models.py,
from django.db import models

class Album(models.Model):
	artist=models.CharField(maxlength=100)
	album_title=models.CharField(maxlength=300)
	album_logo_path=CharField(maxlength=1000) #Link to the image.

class Song(models.Model):
	#Foreign key is primary key of another class' db
    #
        #An album has many songs. A god has many products => foreignKey is a One to many Field!!
	song_album = models.ForeignKey(Album,on_delete=models.CASCADE) #delete songs when the upper album is deleted
	file_type = models.CharField(maxlength=10) #extension
	song_title = models.CharField(maxlength=300)
    is_fav = models.BooleanField(default=False) #new one, now migrate.


# MIGRATIONS = TAKING ALL THE NEW CHANGES INTO AN SQL FILE
# MIGRATION = CHANGE TO YOUR DB.
# Migrations does not include adding/removing items.
# But ONLY WHEN YOU ADD/REMOVE A COLUMN requires makemigrations.
 python manage.py makemigrations music
 python manage.py sqlmigrate music 0001
 python manage.py migrate

#Create admin-
python manage.py createsuperuser

$$ check this if get errors.
# The DJANGO_SETTINGS_MODULE env variable is pointing to only single file (not common to all) currently,
# but If this variable isn’t set, the default wsgi.py sets it to mysite.settings, where mysite is the name of your project. 
#That’s how runserver discovers the default settings file by default.
In project urls.py file, add a mapping to the application and 
this info in urls.py file will be used to direct incoming URL strings to views.
In view.py, create the required views ensuring that they return a HttpResponse object.

WSGI= web server gateway interface


#   django-admin & manage.py are the admins of the files.
#   django settings are in settings.py
$ django-admin <command> [options]
$ manage.py <command> [options]
$ python -m django <command> [options]

App names¶
Many commands take a list of “app names.” 
An “app name” is the basename of the package containing your models.
For example, if your INSTALLED_APPS contains the string 
'mysite.blog', the app name is blog.
Edit urls.py
How does Django know what view to send a particular request?
Django uses a mapping file called urls.py which maps html addresses to views, 
using regular expressions- url(r '^$', view); 
The r, it tells python that a string is "raw"
 - that nothing in the string should be escaped.
The ^ is start of url (home directory), otherwise it can be accessed from any directory.
The $ is end of the url.

#Django’s primary deployment platform is WSGI, the Python standard for web servers and applications.

#A project can contain multiple apps. An app can be in multiple projects
#Your apps can live anywhere on your Python path. In this tutorial, 


templates
- update settings.py TEMPLATES = [DIRS=['FULL_PATH']]
#** above is also done thru musicAppConfig into settings

Django templates come to rescue to maintain dynamic pages easily.
Its got tags in {% script line %} & vars in {{}}
if cond 
    CODE
else 
endif

from django.shortcuts import Http404,get_object_or_404
#try-except block in PY
try:
    #regular code
    album=Album.objects.get(pk=1)
except Album.DoesNotExist:
    #code to run on error
    raise Http404("album DNE")
return render(resp,'life/god.html',{'god':god}) #not '/life/god.html' (that /)

# will be replaced by 
album=get_object_or_404(Album,pk=1)
#thats all. it replaces it by above code.


**Inheritance in templates - adding top nav bar in every.


#How Django processes a request
When a user requests a page from our Django-powered site, this is the algorithm the system follows to determine which Python code to execute:

Django loads that Python module and looks for the variable urlpatterns. This should be a python list, in the format returned by the function django.conf.urls.patterns().
Django runs through each URL pattern, in order, and stops at the first one that matches the requested URL.
Once one of the regexes matches, Django imports and calls the given view, which is a simple python function (or a class based view). The view gets passed an HttpRequest as its first argument and any values captured in the regex as remaining arguments.
If no regex matches, or if an exception is raised during any point in this process, Django invokes an appropriate error-handling view.

*/ 1.10 Goes this way-

Let’s write the first view. Open the file polls/views.py and put the following Python code in it:

polls/views.py

from django.http import HttpResponse
def index(request):    return HttpResponse("Hello, world. You're at the polls index.")

This is the simplest view possible in Django. To call the view, we need to map it to a URL - and for this we need a URLconf.
To create a URLconf in the polls directory, create a file called urls.py. Your app directory should now look like:

In the polls/urls.py file include the following code:
polls/urls.py
from django.conf.urls import url
from . import views
urlpatterns = [
    url(r'^$', views.index, name='index'),
]
*/ then in mysite/urls.py
from django.conf.urls import include, url
from django.contrib import admin
urlpatterns = [
    url(r'^polls/', include('polls.urls')),
    url(r'^admin/', admin.site.urls),
]
The include() function allows referencing other URLconfs. 
Note that the regular expressions for the include() function doesn’t have a $ (end-of-string match character) but rather a trailing slash.
Whenever Django encounters include(), it chops off whatever part of the URL matched up to that point and
 sends the remaining string to the included URLconf for further processing.

urls.py urlpatterns- including a variable : (?P<x_id>[0-9]+)
# [0-9]+ means combination of single digits around.
#/music/712/
url(r'a/([0-9]{4})/([0-9]{2})/([0-9]+)/$',) => this is passing url as UNNAMED positions(cannot be passed to view) 
url(r'^(?P<album_id>[0-9]+)$',) => this is passing url as a keyword (can be used in views)
(r'^(?P<keyword>pattern)')
url(r'a/(?P<year>([0-9]{4}))/(?P<month>([0-9]{2}))/(?P<day>([0-9]+))/$',) => this is passing url as UNNAMED positions(cannot be passed to view) 
#using named patterns with unnamed ones, only named keywords will pass the unnamed paras will not be passed to view as positions.

url(r'^(?P<album_id>[0-9]+)/$', views.detail, name='song')
$#The use of the name='song', is as a reference to this pattern as well as a variable.
 href="/music/{{album.id}}"
# will be replaced by
href={% url 'song' album.id %}
# $$ Multiple apps can have a view with a same name, so to avoid conflicts, use {% url 'music:view' album.id %}


#POST REQUEST
selected_song=album.song_set.get(pk=request.POST['song']) # song is the name of the input field





Many complex Web sites provide some combination of the two. Amazon.com, for instance, is a great example of a database-driven site. Each product page is essentially a query into Amazon’s product database formatted as HTML, and when you post a customer review, it gets inserted into the database of reviews.

Django is well suited for making database-driven Web sites, because it comes with easy yet powerful tools for performing database queries using Python. This chapter explains that functionality: Django’s database layer.


Finally, note a relationship is defined, using ForeignKey. That tells Django each Choice is related to a single Poll. Django supports all the common database relationships: many-to-ones, many-to-manys and one-to-ones.



#Django Objects API
python manage.py shell
from musicApp.models import Album,Song


Album.objects.all();
Album.objects.filter(id=1); ?
album = Albums.objects.get(id=album_id) OR (pk=album_id).

new_song =Song()
new_song.song_album = ref_to_alb
new_song.file_type ='mp3'
new_song.song_title ='Terminal Dos'
new_song.save()

**Django Cools-
    
"""
One relevant thing to mention is the "related_name" argument to ForeignKey. 
So in the PhoneNumber class youd have dude = models.ForeignKey(Dude, related_name='numbers') and then you can use 
some_dude_object.numbers.all() to get at all the related numbers (if you don't specify a "related_name" it'll default to "number_set").
"""
Django has a cool feature to access set of all songs(connected by ForeignKey) inside an album.
album1.song_set.all()
#best way
newsong= album1.song_set.create(song_title='song set create',file_type='yo')
album1.song_set.count()

** Actions on clicking buttons. ** Redirecting stuff (WITH VALIDATE()) **
view-
def fav(resp,album_id):
    album= get_object_or_404(Album,pk=album_id)
    try:
        selectedSong=album.song_set.get(pk=resp.POST['song'])
    except (KeyError,Song.DoesNotExist):
        return render(resp, 'musicApp/showAlbum.html', {'album': album,
                                                        'error_message':"You didn't select valid song",})
    else:# everything gone smoothly
        selectedSong.is_fav= True
        selectedSong.save()
        return render(resp, 'musicApp/showAlbum.html', {'album': album})
urls-
from django.conf.urls import url

from . import views

urlpatterns = [
    url(r'^$', views.showMusic, name='index'),
    #/music/<album_id>
    url(r'^(?P<album_id>[0-9]+)/$', views.detail, name='song'),
    url(r'^(?P<album_id>[0-9]+)/fav/$', views.fav, name='fav'),
]

showAlbum-

<img src="{{ album.album_logo_path }}">
<h1><a href="#">{{ album.album_title }}</a></h1>
<h3><a href="#">{{ album.artist }}</a></h3><br>

{% if error_message %}
    <p><b>{{ error_message }}</b></p>
{% endif %}

<form action="{% url 'fav' album.id %}" method="post">
    {% csrf_token %}
{% for song in album.song_set.all %}
    <input type="radio" id="song{{ forloop.counter }}" name="song" value="{{ song.id }}">
    <label for="song{{ forloop.counter }}">
    {{ song.song_title }}
        {% if song.is_fav %}
            <b> FAV</b><br>
        {% endif %}
    </label>
    
    {# value of the input is sent thru post. #}
    {%  endfor %}
<input type="submit" value="submit a Fav">
</form>



**SECURITY IN DJANGO **
Things  made easy - 
autoescape is on already
   {% csrf_token %}

** Things for repeatition : 
django.shortcuts
from 	django.views import generic


**Adding css files*
just like templates, create a folder "musicApp" in a new folder- "static"
also, for convenience u may create an images folder.

css cools- 
body{
	background: white url("images/logo.jpg");
	/*no reference to static required, it is done when loading the style*/
}

input[type=radio]:checked~label{
	color:
}

** BOOTSTRAP COOLS - NAVBAR
	<nav class="navbar navbar-default">
	<div class="container-fluid">
	<a class="navbar-brand" href="{% url 'music:index' %}">HOME</a>
	<a class="navbar-brand" href="{% url 'music:profile' %}">PROFILE</a>
	</div>
	</nav>

In the template,
{% load staticfiles%} #loads only the paths to styles.
then continue-
<link rel="stylesheet" type="TEXT/CSS" href="{% static 'music/style.css'%}"> # actually loads the style

# % static % = static directory path
#you can still use online styles.



*/AJAX DOS 


*/django-annoying will allow sending LISTS AS AN RESPONSE !
pip install django-annoying (first workon myproject)
add 'annoying' to INSTALLED_APPS.
from annoying.decorators import ajax_request
@ajax_request
def myview_form(request,god_id):
    gods = God.objects.all()
    gods_LE = [entry.player_LE for entry in gods]
    return {'gods_LE': gods_LE} #krupa of djang-anno

The ABove was the replacement for following code-
MyJS-

 setInterval(function (){
    $.ajax({
        type: "GET",
        url:"./getLE",
        success: function(data){
            data = data.split('/');
            console.log(data);
            l=parseInt(data);
            w=data[1]+'%';
            $('#curr_LE').html(l);
            $('#curr_width').css("width",w);

        },
        error: function(){
            alert("Error");
        }
    });
},1000);
// var reloader = setTimeout(function (){ $('#reloadMe').val('{{god.player_LE}}');},1000);
    
views-
def getLE(request,god_id=0):
    god=get_object_or_404(God,pk=god_id)
    LE=god.get_LE()

    if LE>0:
        god.decay()
    else:
        god.setLE()
    god.save()
    width= 100*(god.get_LE())/(god.ini_LE)
    data = []
    data.append(str(LE))
    # str (LE) is imp
    data.append(str(width))
    data = '/'.join(data)
    # data={"curr_LE" : LE,"curr_width" : width}
    return HttpResponse(data)



ModelForms-
In addition, Django applies the following rule: 
if you set editable=False on the model field, 
any form created from the model via ModelForm will not include that field.