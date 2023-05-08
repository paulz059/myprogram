# -*- coding: utf-8 -*-
"""
Created on Wed Feb  1 14:20:45 2023

@author: hk
"""
import time
import os
import openai
ecode = 'utf-8-sig'
start_time = time.time()

openai.organization = "org-ZQI4m1BhqKCawAfaecMjRFLs"
openai.api_key = os.getenv("OPENAI_API_KEY")
#openai.api_key = "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"

# Prompt the user to input a question
import pandas as pd
df = pd.read_csv('char_count.csv',encoding = ecode)
# df.head()

df_processed = df['content'][6:9]

# df_processed.head()
# dfcp = df.copy()
df["word_segmentation"] = ""
model_engine = "gpt-3.5-turbo"
df_out = pd.DataFrame()
segmented_words = []

#columns = df.iloc[:, start_index:end_index + 1]
# Get the input words from the user
#input_text = input("Enter some words: ")
for i, text in enumerate(df_processed):

    completion = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "user", "content":"分词：您好，我是ChatGPT。ChatGPT 将返回以下响应：您好,，我,是,ChatGPT,。分詞: '"+ text + "'"
             }
            ],
        
        #temperature=0
        )
# Start the conversation
    # response = openai.Completion.create(
    #     model="gpt-3.5-turbo",
    #     messages=[
    #         {"role": "user", "content": "Hello!"}
    #                             ]
    #     #prompt="為這段文字分詞 : " + text,
        
    #     max_tokens=4068,
    #     n=1,
    #     stop=None,
    #     top_p=1,
    #     temperature=0,
    #     frequency_penalty=0,
    #     presence_penalty=0,
    # )
    
    answer = completion['choices'][0]['message']['content']
    print("Answer: ", answer)
    df_out.at[i, "word_segmentation"] = answer.strip()
    #segmented_words.append = response["choices"][0]["text"].strip()
# Save the DataFrame to a new CSV file
df_out.to_csv("output.csv", encoding = ecode, index=False)
end_time = time.time()
running_time = end_time - start_time
print(f"Program running time: {running_time:.2f} seconds")