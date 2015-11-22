from django.conf.urls import patterns, include, url
from django.contrib import admin
from linkit.views import *
urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'Trunk.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^admin/', include(admin.site.urls)),
    url(r'^login/$',vlogin),
    url(r'^gps/$',vgps),
    url(r'^input/$',vinput)
)
