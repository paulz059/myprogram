#!/usr/bin/env python
# coding: utf-8

# In[ ]:



import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)

# Input data files are available in the read-only "../input/" directory
# For example, running this (by clicking run or pressing Shift+Enter) will list all files under the input directory

import os
for dirname, _, filenames in os.walk('kaggle/BABKCREDITCARD'):
    for filename in filenames:
        print(os.path.join(dirname, filename))


# In[ ]:


df = pd.read_csv('kaggle/BABKCREDITCARD/BankChurners.csv')
df.head()


# In[ ]:


df.iloc[:,:10].head()


# In[ ]:


df.iloc[:,:10].describe(include='all')


# In[ ]:


df.iloc[:,10:].head()


# In[ ]:


df.iloc[:,10:].describe(include='all')


# In[ ]:


df.duplicated().sum()


# In[ ]:


df_processed = pd.DataFrame()


# In[ ]:


df['Attrition_Flag'].unique()


# In[ ]:


df_processed['attrition_flag'] = df['Attrition_Flag'].map({'Existing Customer': 0, 'Attrited Customer': 1})
df_processed.head()


# In[ ]:


df_processed['age'] = df['Customer_Age']
df_processed.head()


# In[ ]:


df_processed['gender'] = df['Gender'].map({'F': 0, 'M': 1})
df_processed.head()


# In[ ]:


df_processed['dependent_count'] = df['Dependent_count']
df_processed.head()


# In[ ]:


df['Education_Level'].unique()


# In[ ]:


education_unknown_indexes = df[df['Education_Level'] == 'Unknown'].index


# In[ ]:


df = df[~df.index.isin(education_unknown_indexes)]
df_processed = df_processed[~df_processed.index.isin(education_unknown_indexes)]
df_processed.describe(include='all')


# In[ ]:


education_level_dict = {
    'Uneducated': 0,
    'High School': 1,
    'College': 2,
    'Graduate': 3,
    'Post-Graduate': 4,
    'Doctorate': 5
}


# In[ ]:


df_processed['education'] = df['Education_Level'].map(education_level_dict)
df_processed.head()


# In[ ]:


df['Marital_Status'].unique()


# In[ ]:


unknown_marital_indexes = df[df['Marital_Status'] == 'Unknown'].index


# In[ ]:


df = df[~df.index.isin(unknown_marital_indexes)]
df_processed = df_processed[~df_processed.index.isin(unknown_marital_indexes)]
df_processed.describe(include='all')


# In[ ]:


marital_dummies = pd.get_dummies(df['Marital_Status'], prefix='status', drop_first=True)
marital_dummies.head()


# In[ ]:


df_processed = pd.concat([df_processed, marital_dummies], axis='columns')
df_processed.head()


# In[ ]:


df['Income_Category'].unique()


# In[ ]:


unknown_income_indexes = df[df['Income_Category'] == 'Unknown'].index


# In[ ]:


df = df[~df.index.isin(unknown_income_indexes)]
df_processed = df_processed[~df_processed.index.isin(unknown_income_indexes)]
df_processed.describe(include='all')


# In[ ]:


income_dict = {
    'Less than $40K': 0,
    '$40K - $60K': 1,
    '$60K - $80K': 2,
    '$80K - $120K': 3,
    '$120K +': 4
}


# In[ ]:


df_processed['income_category'] = df['Income_Category'].map(income_dict)
df_processed.head()


# In[ ]:


df['Card_Category'].unique()


# In[ ]:


card_dummies = pd.get_dummies(df['Card_Category'], prefix='card', drop_first=True)
card_dummies.head()


# In[ ]:


df_processed = pd.concat([df_processed, card_dummies], axis='columns')
df_processed.head()


# In[ ]:


rest_of_data = df.iloc[:,9:21]
rest_of_data.head()


# In[ ]:


df_processed = pd.concat([df_processed, rest_of_data], axis='columns')
df_processed.head()


# In[ ]:


df_processed.describe()


# In[ ]:


df_processed.columns


# In[ ]:


dfcp = df_processed.copy()
columns = 'attrition_flag'
columns1 = dfcp.iloc[:, :14]
#X = dfcp.drop(columns, axis=1)
X = dfcp.iloc[:, 1:10]
Y = dfcp.iloc[:, 0:1]


# In[ ]:


X.head()


# In[ ]:


Y.head()


# In[ ]:


#df_processed.to_csv('BANKCARDafterPD_person.csv')


# In[ ]:


from sklearn.model_selection import train_test_split


# In[ ]:


X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state=12)


# In[ ]:


X_train.columns


# In[ ]:





# In[ ]:


len(X_train)


# In[ ]:


from sklearn.tree import DecisionTreeClassifier


# In[ ]:


#建立空的決策樹分類器
clf = DecisionTreeClassifier(max_depth = 3, random_state = 0)

#用訓練資料訓練模型
clf.fit(X_train, Y_train)

#用測試資料預測模型分類，印出結果
clf.predict(X_test)


# In[ ]:


clf.score(X_test, Y_test)


# In[ ]:


from sklearn.metrics import accuracy_score
y_predict = clf.predict(X_test)
accuracy_score(Y_test, y_predict)


# In[ ]:


from sklearn import tree
import matplotlib.pyplot as plt


# In[ ]:


plt.figure(figsize=(6,6), dpi=300)
tree.plot_tree(clf, max_depth=3,fontsize=6)


# In[ ]:


#df.columns


# In[ ]:


fn=X_train.columns
fig, axes = plt.subplots(nrows=1, ncols=1, figsize = (6,6), dpi=750) #建立多個子圖表
tree.plot_tree(clf, max_depth=4, feature_names=fn, filled=True,fontsize=6)
fig.savefig('Credit Card Customers2.png')


# In[ ]:


import seaborn as sns


# In[ ]:


fn1=X.columns  #擷取特徵名稱
feature_imp = pd.Series(clf.feature_importances_, index=fn1).sort_values(ascending=False)
# Creating a bar plot
fig, ax = plt.subplots(figsize=(5, 5), dpi=160, constrained_layout=True)  #調整圖形大小
fig = sns.barplot(x=feature_imp, y=feature_imp.index, ax=ax)
plt.savefig("feature_importances_2.png")
# Add labels to your graph
plt.xlabel('feature_importances score')
plt.ylabel('features')
plt.title("visualize feature_importances")
plt.savefig('visualize feature_importances.png')
plt.show()


# In[ ]:





# In[ ]:





# In[ ]:


import seaborn as sn
import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')


# In[ ]:


sn.pairplot(data=df_processed)


# In[ ]:


from sklearn.utils.class_weight import compute_class_weight


# In[ ]:


y = df_processed['attrition_flag']
y.value_counts()


# In[ ]:


class_weights = compute_class_weight(class_weight='balanced', classes=np.unique(y), y=y)
class_weights


# In[ ]:


class_weight_dict = {
    0: class_weights[0],
    1: class_weights[1]
}
class_weight_dict


# In[ ]:


from sklearn.model_selection import cross_val_score, train_test_split, GridSearchCV
from sklearn.preprocessing import MinMaxScaler


# In[ ]:


scaler = MinMaxScaler()


# In[ ]:


X = scaler.fit_transform(df_processed.drop('attrition_flag', axis='columns'))


# In[ ]:


from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.linear_model import LogisticRegression, SGDClassifier
from sklearn.naive_bayes import MultinomialNB, GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import classification_report, confusion_matrix


# In[ ]:


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


# In[ ]:


for name, model in model_dict.items():
    scores = cross_val_score(model, X, y)
    print(f'{name} scores: ', scores)
    print(f'{name} mean: ', scores.mean())


# In[ ]:


GB_optimizer = GridSearchCV(GradientBoostingClassifier(), {
    'loss': ['log_loss', 'exponential'],
    'n_estimators': [50, 100, 150, 200],
    'criterion': ['friedman_mse', 'squared_error'],
    'max_features': ['auto', 'sqrt', 'log2']
})


# In[ ]:


GB_optimizer.fit(X, y)


# In[ ]:


feature_importance=pd.DataFrame(search.best_estimator_[2].feature_importances_, columns=['importance'])
feature_importance['features'] = X_train.columns

plt.figure(figsize=(10,8))
sns.barplot(x='importance', y='features', data=feature_importance.sort_values(by='importance', ascending=False))
plt.title('Feature importances')
plt.show()


# In[ ]:




