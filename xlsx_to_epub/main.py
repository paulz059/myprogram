# -*- coding: utf-8 -*-
"""
Created on Thu May 18 12:49:21 2023

@author: hk
"""
from xlsx_call_in import XlsxHelper
from change_epub import change_epub
# import pandas as pd
# from ebooklib import epub
xlsx_files = XlsxHelper.list_all_xlsx()


for i in xlsx_files:
    dfs_by_sheet=XlsxHelper.read_xlsx_by_label(i)

#df_content['content'] = df_content['content'].apply(remove_html_tags)


#row_A = dfs_by_sheet['df_Chapters - chapters_data_grouped']
    # column_A_dict = {}
    # for df_key, df_value in dfs_by_sheet['df_Chapters - chapters_data_grouped'].items():
    #     if isinstance(df_value, pd.DataFrame):
    #         row_A = df_value.loc[1:, ['content']].copy()
    #         row_A['content'] = row_A['content'].apply(XlsxHelper.remove_html_tags)
    #     column_A_dict[df_key] = row_A
        
#row_A['content'] = column_A_dict[df_key]['content'].apply(XlsxHelper.remove_html_tags)

# change_epub.xlsx_to_epub(dfs_by_sheet)
# for i in dfs_by_sheet.items():
#     change_epub.xlsx_to_epub(i)

# authors_df = dfs_by_sheet['df_Authors - authors_data_grouped']
    change_epub.xlsx_to_epub(dfs_by_sheet)
# 添
# 创建作者介绍
# for index, row in authors_df.items():
#     # 创建作者介绍章节
#     title='About {}'.format(row['author_name'])
#     file_name='about_author_{}.xhtml'.format(row['author_intro'])

