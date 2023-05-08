# -*- coding: utf-8 -*-
"""
Created on Tue Jan 17 16:22:05 2023

@author: hk
"""

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

# Input data files are available in the read-only "../input/" directory
# For example, running this (by clicking run or pressing Shift+Enter) will list all files under the input directory

import os
for dirname, _, filenames in os.walk('kaggle/BABKCREDITCARD'):
    for filename in filenames:
        print(os.path.join(dirname, filename))
        
df = pd.read_csv('BANKCARDafterPD_person.csv')
df.head()

df_processed = df

df_processed.head()
dfcp = df.copy()
columns = 'attrition_flag'
columns1 = dfcp.iloc[:, :14]
#X = dfcp.drop(columns, axis=1)

X = dfcp.drop(columns, axis=1)
y = df_processed['attrition_flag']
y.value_counts()

from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score

from sklearn.feature_selection import VarianceThreshold

df_corr = df_processed.corr()
multi_model = LinearRegression()
from sklearn.utils.class_weight import compute_class_weight
class_weights = compute_class_weight(class_weight='balanced', classes=np.unique(y), y=y)
class_weights
class_weight_dict = {
    0: class_weights[0],
    1: class_weights[1]
}
class_weight_dict
from sklearn.model_selection import cross_val_score, train_test_split, GridSearchCV
from sklearn.preprocessing import MinMaxScaler

scaler = MinMaxScaler()
X = scaler.fit_transform(df_processed.drop('attrition_flag', axis='columns'))

from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.naive_bayes import MultinomialNB, GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import classification_report, confusion_matrix

model_dict = {
    'Random Forest': RandomForestClassifier(class_weight=class_weight_dict),
    'Gradient Boosting': GradientBoostingClassifier(),
    'Logistic Regression': LogisticRegression(class_weight=class_weight_dict),
    'SGD Classifier': SGDClassifier(class_weight=class_weight_dict),
    'Multinomial NB': MultinomialNB(),
    'Gaussian NB': GaussianNB(),
    'KNeighbors': KNeighborsClassifier()
}
model_dict



for name, model in model_dict.items():
    scores = cross_val_score(model, X, y)
    print(f'{name} scores: ', scores)
    print(f'{name} mean: ', scores.mean())
    
GB_optimizer = GridSearchCV(GradientBoostingClassifier(), {
    'loss': ['log_loss', 'exponential'],
    'n_estimators': [50, 100, 150, 200],
    'criterion': ['friedman_mse', 'squared_error'],
    'max_features': ['sqrt', 'log2']
})

GB_optimizer.fit(X, y)

gb_optimizer_results = pd.DataFrame(GB_optimizer.cv_results_)
gb_optimizer_results[['param_loss', 'param_n_estimators', 'param_criterion', 'param_max_features', 'mean_test_score']]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, stratify=y, random_state=2022)

gb_model = GradientBoostingClassifier(criterion='friedman_mse', loss='exponential', max_features='sqrt', n_estimators=200)


gb_model.fit(X_train, y_train)


gb_model.score(X_test, y_test)

y_predicted = gb_model.predict(X_test)
print(y_predicted)



















# print(classification_report(y_test, y_predicted))

# def traindata(X,y):
#     X_train, X_test, y_train, y_test = train_test_split(X, y, shuffle=True, train_size=0.3)
#     return X_train, X_test, y_train, y_test
# def fitmodel(X_train,y_train):
#     multi_model.fit(X_train, y_train)
# def predY(X_test,y_test):
#     y_pred = multi_model.predict(X_test)
#     r2 = r2_score(y_test, y_pred)
#     rmse = mean_squared_error(y_test, y_pred)
#     print('The r2 is: ', r2)
#     print('The rmse is: ', rmse)
# #----------------------------NO Feature selection

# X_train, X_test, y_train, y_test = traindata(X,y)
# fitmodel(X_train,y_train)
# predY(X_test,y_test)

# #print(multi_model.coef_)
# #print(multi_model.intercept_)

# coefficients = multi_model.coef_
# intercept = multi_model.intercept_

# # =============================================================================
# #----------------------------VarianceThreshold
# print("VarianceThreshold")
# selector = VarianceThreshold(threshold=0.8)

# X_train, X_test, y_train, y_test = traindata(X,y)

# X_train_high_variance = selector.fit_transform(X_train)
# X_test_high_variance = selector.transform(X_test)

# fitmodel(X_train_high_variance, y_train)

# predY(X_test_high_variance,y_test)

# #print(multi_model.coef_)
# #print(multi_model.intercept_)

# coefficients = multi_model.coef_
# intercept = multi_model.intercept_

# # =============================================================================
# # def calculate_charges(age, bmi, smoker):
# #   return (age * coefficients[0]) + (bmi * coefficients[1]) + (smoker * coefficients[2]) + intercept
# # print(calculate_charges(33, 22, 0))
# # =============================================================================

# # =============================================================================
# #----------------------------K Best
# from sklearn.feature_selection import SelectKBest
# from sklearn.feature_selection import f_regression
# X_train, X_test, y_train, y_test = train_test_split(X, y, shuffle=True, train_size=0.3)

# bestfeatures = SelectKBest(score_func=f_regression, k=10)
# X_train_top_k = bestfeatures.fit_transform(X_train, y_train)

# X_test_top_k = bestfeatures.transform(X_test)

# # Creating a new model and fitting it

# multi_model.fit(X_train_top_k, y_train)



# # Prediction new values
# predictions = multi_model.predict(X_test_top_k)
# r2 = r2_score(y_test, predictions)
# rmse = mean_squared_error(y_test, predictions)

# print('KBestThe r2 is: ', r2)
# print('KBestThe rmse is: ', rmse)
# #print(multi_model.coef_)
# #print(multi_model.intercept_)

# # =============================================================================
# #----------------------------K Best
# #--------------------------------
# # from sklearn.utils.class_weight import compute_class_weight

# # class_weights = compute_class_weight(class_weight='balanced', classes=np.unique(y), y=y)
# # class_weights
# # class_weight_dict = {
# #     0: class_weights[0],
# #     1: class_weights[1]
# # }
# # class_weight_dict

# # from sklearn.model_selection import cross_val_score, train_test_split, GridSearchCV
# # from sklearn.preprocessing import MinMaxScaler

# # scaler = MinMaxScaler()

# #X.head()
