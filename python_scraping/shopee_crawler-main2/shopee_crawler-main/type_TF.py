# -*- coding: utf-8 -*-
"""
Created on Wed Jan  4 15:35:57 2023

@author: hk
"""

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

import matplotlib.pyplot as plt
#matplotlib inline
path = ""
ecode = 'utf-8-sig'
files = 'merged_null.csv'

df = pd.read_csv(files, encoding = ecode)

print(df.info())
df['是否可預購'].unique()

print(df['是否可預購'])
df['可否搭配購買'] = df['可否搭配購買'].map({'TRUE': 1, 'FALSE': 0})
df['可否大量批貨購買'] = df['可否大量批貨購買'].map({'TRUE': 1, 'FALSE': 0})
df['是否官方賣家帳號'] = df['是否官方賣家帳號'].map({'TRUE': 1, 'FALSE': 0})
df['是否可預購'] = df['是否可預購'].map({'True': 1, 'False': 0})
print(df['是否可預購'])