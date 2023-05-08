# -*- coding: utf-8 -*-
"""
Created on Wed Jan  4 14:01:44 2023

@author: hk
"""

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

import matplotlib.pyplot as plt
#matplotlib inline
path = ""
ecode = 'utf-8-sig'
files = 'merged1.csv'


df = pd.read_csv(files, encoding = ecode)
#print(df.columns)

#print(df.isnull().sum())

#filled =df.fillna(0) #把null零
df[['折數']] = df[['折數']].fillna(value=0)

print(df.isnull().sum())

df.to_csv( "merged_null.csv",encoding = ecode)
