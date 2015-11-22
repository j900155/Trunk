from django.db import models

# Create your models here.
class Mnfc(models.Model):
	nfc=models.CharField(max_length=155555)

class Mgps(models.Model):
	gps=models.CharField(max_length=25)
	time = models.DateTimeField()	
