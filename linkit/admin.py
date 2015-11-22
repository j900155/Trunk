from django.contrib import admin
from linkit.models import Mnfc,Mgps
# Register your models here.

class nfcAdmin(admin.ModelAdmin):
	list_display=('nfc',)

admin.site.register(Mnfc,nfcAdmin)

class gpsAdmin(admin.ModelAdmin):
	list_display=('gps','time')

admin.site.register(Mgps,gpsAdmin)

