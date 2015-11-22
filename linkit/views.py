from django.shortcuts import render_to_response
from django.http import HttpResponse
from linkit.models import Mnfc,Mgps
from django.utils import timezone
# Create your views here.
def vlogin(request):
	if request.GET:
		nfc=request.GET['pw']
		nfc.replace(" ","")
		if Mnfc.objects.filter(nfc=nfc):
			check='1'
		else:
			check='0'
		return HttpResponse(check)
	return render_to_response('login.html',locals())

def vgps(request):
	gps=Mgps.objects.all()

	return render_to_response('gps.html',locals())

def vinput(request):
	nfcs=Mnfc.objects.all()
	if 'gps_add' in request.GET:
		gps=request.GET['gps']
		Mgps.objects.create(
			gps=gps,
			time=timezone.localtime(timezone.now())
			
		)
		check="gps"	
	elif "nfc_add"  in request.GET:
		nfc=request.GET['nfc']
		nfc.replace(" ","")
		Mnfc.objects.create(
			nfc=nfc
		)
		check=nfc
	return render_to_response('input.html',locals())
