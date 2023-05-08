# -*- coding: utf-8 -*-
"""
Created on Tue Jan  3 14:16:05 2023

@author: hk
"""


from glob import glob
import pandas as pd

path = ""
ecode = 'utf-8-sig'

files = glob("shopeeAPIData*.csv")

df_1 = pd.concat(
    (pd.read_csv(file, encoding = ecode) for file in files), ignore_index=True)
 
df_1.to_csv( "merged1.csv",encoding = ecode)

print(df_1.shape[0])

print(df_1.shape[1])