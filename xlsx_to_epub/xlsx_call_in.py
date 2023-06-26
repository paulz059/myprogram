# -*- coding: utf-8 -*-
"""
Created on Tue May 16 14:35:19 2023

@author: hk
"""
import os
import re

import pandas as pd
xlsx_files = ""
# 讀取 XLSX 文件

class XlsxHelper:
    def list_all_xlsx():
            # 讀取用戶輸入的資料夾路徑
        folder_path =input("請輸入資料夾路徑：")
        
        # folder_path = r"D:\IT\MLP\pandas\book_translate"
        # 列出資料夾中的所有XLSX文件
        xlsx_files = [folder_path  + '\\'+ f for f in os.listdir(folder_path) if f.endswith('.xlsx')]
        #print(xlsx_files)
        if not xlsx_files:
            print("錯誤：資料夾中沒有XLSX文件！程式即將結束。")
            exit()  # 停止程式執行
        return xlsx_files
        
    def read_xlsx_by_label(xlsx_files):
        #print(xlsx_files)
        df = pd.ExcelFile(xlsx_files)
        sheet_names = df.sheet_names
        # sheet_names = [name.replace(' ',"_") for name in sheet_names]
        dfs_by_sheet = {}
        dfs_bynew_sheet = {}
        for sheet_name in sheet_names:
            dfs_by_sheet["df_"+sheet_name] = pd.read_excel(df, sheet_name, header=1)
            dfs_by_sheet["df_"+sheet_name].reset_index(drop=True, inplace=True)
        
        # 初始化一個空的字典，用於存儲分組後的數據框
            grouped_data = {}
            try:
                for label_value in dfs_by_sheet["df_"+sheet_name]['book_label'].unique():
                    grouped_data[label_value] = dfs_by_sheet["df_"+sheet_name][dfs_by_sheet["df_"+sheet_name]['book_label'] == label_value]
            except KeyError:
                continue
            # 將 grouped_data 字典存入 dfs_by_sheet 字典中
            dfs_bynew_sheet["df_"+sheet_name+'_grouped'] = grouped_data
        return dfs_bynew_sheet
    def remove_html_tags(text):
        clean = re.compile('<.*?>')
        return re.sub(clean, '', text)
# 遍歷 label 欄的每個值，並把相同值的行存入 grouped_data 字典中
# for label in df['label'].unique():
#     grouped_data["df"+label] = df[df['label'] == label]

# 輸出每個分組的 DataFrame
# for label, group_df in grouped_data.items():
#     print(f'Label {label}:')
#     print(group_df)
# xlsx_files = list_all_xlsx()
#dfs_by_sheet=XlsxHelper.read_xlsx_by_label()