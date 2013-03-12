#!/usr/bin/env python
# -*- coding: utf-8 -*- 
import urllib
import json

persos = ['Bigouden', 'Cirelia', 'Faerha', 'Nihale','Fleuri', 'Fleuris', 'Arlana', 'Arsélin', 'Cérania', 'Genola']
host='eu.battle.net'
royaume='Chants Éternels'
for perso in persos:
    path='http://'+host+'/api/wow/character/'+royaume+'/'+perso+'?fields=professions'
    u=urllib.urlopen(path)
    data=json.loads(u.read())
    print '======== {0}: {1} ========='.format(perso,data['level'])
    metiers_primaires=data['professions']['primary']
    for metier in metiers_primaires:
        print 'metier: {0} {1}/{2}'.format(metier['name'],metier['rank'],metier['max'])
#    metiers_secondaires=data['professions']['secondary']
#    for metier in metiers_secondaires:
#        print 'metier: {0} {1}/{2}'.format(metier['name'],metier['rank'],metier['max'])
    print '======================'.format(perso)
