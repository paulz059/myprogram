# -*- coding: utf-8 -*-
"""
Created on Wed Feb  1 17:21:53 2023

@author: hk
"""
import os

import openai

# Apply the API key
openai.api_key = os.getenv("OPENAI_API_KEY")

# Define the input text
input_text = input("Enter some words: ")

text = input_text

# Request the API to perform word segmentation
response = openai.Completion.create(
    engine="text-davinci-003",
    prompt='Segment the words in this sentence: "' + text + '"',
    max_tokens=1024,
    n=1,
    stop=None,
    temperature=0.5,
)

# Extract the word segmentation from the API response
segmented_text = response["choices"][0]["text"].strip()

# Print the segmented text
print(segmented_text)