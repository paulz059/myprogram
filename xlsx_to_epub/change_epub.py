# -*- coding: utf-8 -*-
"""
Created on Fri May 19 10:33:39 2023

@author: hk
"""

import pandas as pd
from ebooklib import epub
pd.set_option('display.max_colwidth', None) 
# 读取CSV文件
#csv_file = 'input.csv'
#df = pd.read_csv(csv_file)

# 创建EPUB对象
class change_epub:
    def xlsx_to_epub(dfs_by_sheet):
        # book = epub.EpubBook()
        
        # # 设置元数据
        # book.set_identifier('csv_to_epub')
        for df_key,book_name in dfs_by_sheet['df_Book Name - books_data_grouped'].items():
            book = epub.EpubBook()
            strbook_name =book_name['title'].to_string(index=False)
            # 设置元数据
            #book.set_identifier('csv_to_epub')
            if isinstance(book_name, pd.DataFrame):
                # 设置书名
                book.set_title(strbook_name)  
                #print(book_name['title'].to_string(index=False))
        # authors_df = pd.DataFrame({'Author Name': ['Author A', 'Author B', 'Author C'],
        #                            'about_author': ['About Author A', 'About Author B', 'About Author C']})
            authors_df = dfs_by_sheet['df_Authors - authors_data_grouped'][df_key]
            book.get_metadata('DC', 'title')
        
        
            
        # 作者頁面  
            book.add_author(authors_df['author_name'].to_string(index=False)) 
            
                # 创建作者介绍章节
            About_author_title ='About {}'.format(authors_df['author_name'].to_string(index=False))
            # print(About_author_title)
            # About_author_file_name ='about_author_{}.xhtml'.format(authors_df['author_name'].to_string(index=False))
            # print(About_author_file_name)
            about_author = epub.EpubHtml(title= About_author_title , file_name= 'About_author_file_name.xhtml', lang='en')
            about_author.content = '''
                <html>
                  <head></head>
                  <body>
                  <h1>有關作者 </h1>
                    {}
                  </body>
                </html>
            '''
            authors_html = ''  # 存储生成的作者姓名和简介的HTML
            
            for i in range(len(authors_df)):
                author_a = authors_df.iloc[i]['author_name']
                author_i = authors_df.iloc[i]['author_intro']
                
                author_html = '''
                    
                    <p class="author">{}</p>
                    <p class="authorp">{}</p>
                '''.format(author_a, author_i)
                authors_html += author_html
            about_author.content = about_author.content.format(authors_html)
            about_author.add_link(href='style/nav_item_style.css', rel='stylesheet', type='text/css')
            
            book.add_item(about_author)
            
            # print(authors_df['author_intro'].to_list())
            # print(about_author)
            # book.toc = [epub.Link('About_author_file_name.xhtml','About_author_title','about_author')]
            
        # intro chapter
            

            # add navigation files
            book.add_item(epub.EpubNcx())
            book.add_item(epub.EpubNav())
            nav_item = epub.EpubHtml(title= "book_name",file_name= 'book_name.xhtml' )

            # 封面 首頁
            if book_name['subtitle'].isna().any():
                book_name['subtitle'].fillna(' ', inplace=True)
                
            new_nav_content = """
            <html>
            <head></head>
            <body>
                <h1 class="centered">{}</h1>
                <h2 class="cover">{}</h2>
                <!-- 添加新的导航内容 -->
            </body>
            </html>
            """.format(book_name['title'].to_string(index=False),book_name['subtitle'].to_string(index=False))
            nav_item.content = new_nav_content
            #連接CSS
            nav_item.add_link(href='style/nav_item_style.css', rel='stylesheet', type='text/css')
            #建立CSS
            
            nav_item_style = '''
            
            body {
                font-family: Arial, sans-serif,Cambria, Liberation Serif, Bitstream Vera Serif, Georgia, Times, Times New Roman, serif;
            }
            
            a {
                    color: #000000 !important; /* 设置链接的颜色，这里为黑色 */
                    text-decoration: none !important; /* 去除链接的下划线 */
                    
}
            .chapter .backcolor{
                background-color: transparent !important;
                color: #000000 !important; /* 设置链接的颜色，这里为黑色 */
                
                }
            h1.content{
                text-align: left; 
                margin: 30 auto;
                font-size: 15pt;
                }
            h1 {
                text-align: center; 
                margin: 30 auto;
                font-size: 20pt;
                }
            h1.centered{
                text-align: center;
                  position: fixed;
                  bottom: 85%;
                  left: 20%;
                  right: 20%;
                  margin: 0;
                
                }
            .author{
                text-align: left; 
                margin: 30 auto;
                font-weight: bold;
                }
            .authorp{
                text-align: center;
                  position: relative;
                  top: 50%;
                  transform: translateY(-50%);
                  
                }
            h2.cover{
                text-align: center;
                  position: fixed;
                  bottom: 20%;
                  left: 20%;
                  right: 20%;
                  margin: 0;
                  }
            .chapter{
                /*line-height: 1 !important;*/
                padding-left: 10px; /* 左内边距 */
                padding-right: 10px; /* 右内边距 */
                margin-top: 0px;
                margin-bottom: -3px;
                line-height: 1.2;
                background-color: transparent !important;
                }
            .content_p.magin5{
                margin-top: 5% !important;
                }
            
            '''
            nav_css = epub.EpubItem(uid="style_nav", file_name="style/nav_item_style.css", media_type="text/css", content=nav_item_style)
            # ADD item
            book.add_item(nav_css)
            book.add_item(nav_item)
            #目錄 :章節
            content_chapter_df = dfs_by_sheet['df_Chapters - chapters_data_grouped'][df_key]
            
            content_chapter_title = epub.EpubHtml(title= "content_chapter_title",file_name= 'content_chapter_title.xhtml' )
            content_chapter_title_content = """
            <html>
            <head></head>
            <body>
                <h1>目錄</h1>
                {}
                <!-- 添加新的导航内容 -->
            </body>
            </html>
            """.format('<br> '.join(['<p class = "chapter"><a class = "backcolor" href="chapter_content_{}.xhtml">{}</a></p>'
            .format(i +1 , row) for i,row in content_chapter_df['chapter_title'].items()]))
            content_chapter_title.content = content_chapter_title_content
            book.add_item(content_chapter_title)
            #連接CSS
            content_chapter_title.add_link(href='style/nav_item_style.css', rel='stylesheet', type='text/css')
            
            
            book.spine = [nav_item, about_author,content_chapter_title]
            #章節: content
            chapter_contents = {}
            for index, row in dfs_by_sheet['df_Chapters - chapters_data_grouped'][df_key].iterrows():
                chapter_title = "Chapter {} - {}".format(index + 1, row['chapter_title'])
                chapter_file_name = 'chapter_content_{}.xhtml'.format(index + 1)
                chapter_content = epub.EpubHtml(title=chapter_title, file_name=chapter_file_name)
                chapter_content_content = """
                <html class='content_p magin5'>
                <head></head>
                <body >
                <div >
                    <h1 class='content'>{}</h1>
                    <p>{}</p>
                    <!-- 添加新的导航内容 -->
                    </div>
                </body>
                </html>
                """.format(row['chapter_title'], row['content'])
                chapter_content.content = chapter_content_content
                chapter_contents["chapter_content{}".format(index + 1)] = chapter_content
                
            # add spine chapter_content
            for chapter_content in chapter_contents.values():
                book.add_item(chapter_content)
                chapter_content.add_link(href='style/nav_item_style.css', rel='stylesheet', type='text/css')
                book.spine.append(chapter_content)
            
            
            style = '''
        @namespace epub "http://www.idpf.org/2007/ops";

        body {
            font-family: Arial, sans-serif,Cambria, Liberation Serif, Bitstream Vera Serif, Georgia, Times, Times New Roman, serif;
        }
        h1 {
            text-align: center;
            
        }

        h2 {
             text-align: left;
             text-transform: uppercase;
             font-weight: 200;     
        }

        ol {
                list-style-type: none;
        }

        ol > li:first-child {
                margin-top: 0.3em;
        }


        nav[epub|type~='toc'] > ol > li > ol  {
            list-style-type:square;
        }


        nav[epub|type~='toc'] > ol > li > ol > li {
                margin-top: 0.3em;
        }

        '''

            # add css file
            nav_css = epub.EpubItem(uid="style_nav", file_name="style/nav.css", media_type="text/css", content=style)
            book.add_item(nav_css)

            # create spine
           


            epub_file = 'test_output'+df_key+'.epub'
            epub.write_epub(epub_file, book, {})
            print('EPUB文件已生成：{}'.format(epub_file))
        
        # 创建章节
        # for index, row in df.iterrows():
        #     chapter = epub.EpubHtml(title=row['chapter_title'], file_name='chapter_{}.xhtml'.format(index + 1))
        #     chapter.content = '''
        #     <html>
        #       <head></head>
        #       <body>
        #         <h1>{}</h1>
        #         <p>{}</p>
        #       </body>
        #     </html>
        #     '''.format(row['chapter_title'], row['content'])
        #     book.add_item(chapter)
        
            # 将章节添加到目录
             # book.toc.append(epub.Link('chapter_{}.xhtml'.format(index + 1), row['chapter_title'], 'chapter_{}'.format(index + 1)))
       
        # 将作者介绍和章节添加到书籍中
        #book.add_item(about_author)
        
        # 设置封面（可根据需要进行调整）
        #book.set_cover('cover.jpg', open('cover.jpg', 'rb').read())
        
        # 生成EPUB文件
        # epub_file = 'test_output'+'.epub'
        # epub.write_epub(epub_file, book, {})
        # print('EPUB文件已生成：{}'.format(epub_file))
