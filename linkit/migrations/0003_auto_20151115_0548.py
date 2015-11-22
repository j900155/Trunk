# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('linkit', '0002_auto_20151109_2010'),
    ]

    operations = [
        migrations.AlterField(
            model_name='mnfc',
            name='nfc',
            field=models.CharField(max_length=155555),
            preserve_default=True,
        ),
    ]
