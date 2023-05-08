# -*- coding: utf-8 -*-
"""
Created on Wed Jan 11 20:37:56 2023

@author: hk
"""

import pandas as pd
df = pd.read_csv('https://raw.githubusercontent.com/datagy/data/main/insurance.csv')
#print(df.head())
#print(df.corr())
import seaborn as sns
# import matplotlib.pyplot as plt
# sns.pairplot(df)
# plt.show()
# sns.pairplot(df, hue='smoker')
# plt.show()
# sns.relplot(data=df, x='age', y='charges', hue='smoker')
# plt.show()
non_smokers = df[df['smoker'] == 'no']
non_smokers['sex']= df['sex'].map({'male' : 1,'female': 0})
non_smokers['region']= df['region'].map({'northwest' : 1,'southeast': 0})
non_smokers['smoker']= df['smoker'].map({'no' : 1,'yes': 0})
non_smokers.head()
#print(non_smokers.corr())
from sklearn.linear_model import LinearRegression
model = LinearRegression()

X = non_smokers[['age']]
y = non_smokers['charges']
print('The type of X is ', type(X))
print('The type of y is ', type(y))
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score

from sklearn.feature_selection import VarianceThreshold
# sel = VarianceThreshold(threshold=(0.8))
# print(non_smokers.corr())
# df_threshold = sel.fit_transform(non_smokers)
# print(df_threshold.corr())
# =============================================================================
# X_train, X_test, y_train, y_test = train_test_split(X, y, shuffle=True, train_size=0.3)
# model.fit(X_train, y_train)
# from sklearn.metrics import mean_squared_error, r2_score
# predictions = model.predict(X_test)
# r2 = r2_score(y_test, predictions)
# rmse = mean_squared_error(y_test, predictions, squared=False)
# 
# print('The r2 is: ', r2)
# print('The rmse is: ', rmse)
# # Creating new variables
# X = non_smokers[['age', 'bmi']]
# y = non_smokers['charges']
# 
# # Splitting the data into training and testing
# X_train, X_test, y_train, y_test = train_test_split(X, y, shuffle=True, train_size=0.3)
# 
# # Creating a new model and fitting it
# multi_model = LinearRegression()
# multi_model.fit(X_train, y_train)
# 
# # Prediction new values
# predictions = multi_model.predict(X_test)
# r2 = r2_score(y_test, predictions)
# rmse = mean_squared_error(y_test, predictions, squared=False)
# 
# print('The r2 is: ', r2)
# print('The rmse is: ', rmse)
# =============================================================================

df['smoker_int'] = df['smoker'].map({'yes':1, 'no':0})
X = non_smokers
y = df['charges']
print(X.head())
selector = VarianceThreshold(threshold=0.8)


X_train, X_test, y_train, y_test = train_test_split(X, y, shuffle=True, train_size=0.3)
X_train_high_variance = selector.fit_transform(X_train)
X_test_high_variance = selector.transform(X_test)

# Creating a new model and fitting it
multi_model = LinearRegression()
multi_model.fit(X_train_high_variance, y_train)


# Prediction new values
y_pred = multi_model.predict(X_test_high_variance)

r2 = r2_score(y_test, y_pred)
rmse = mean_squared_error(y_test, y_pred)

print('The r2 is: ', r2)
print('The rmse is: ', rmse)
print(multi_model.coef_)
print(multi_model.intercept_)
# Writing a function to predict charges
coefficients = multi_model.coef_
intercept = multi_model.intercept_
def calculate_charges(age, bmi, smoker):
  return (age * coefficients[0]) + (bmi * coefficients[1]) + (smoker * coefficients[2]) + intercept

print(calculate_charges(33, 22, 0))
