#!/bin/bash

echo "📚 Downloading NLP Demystified notebooks..."

mkdir -p notebooks/nlp-demystified
cd notebooks/nlp-demystified

# List of (filename, URL) pairs
declare -A notebooks=(
  ["02_Tokenization.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_preprocessing.ipynb"
  ["03_Basic_Preprocessing.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_preprocessing.ipynb"
  ["04_Advanced_Preprocessing.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_preprocessing.ipynb"
  ["05_BoW_Document_Similarity.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_vectorization.ipynb"
  ["06_TF_IDF_Search.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_vectorization.ipynb"
  ["08_Naive_Bayes_Classification.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_classification_naive_bayes.ipynb"
  ["09_Topic_Modeling_LDA.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_topic_modelling_lda.ipynb"
  ["10_Neural_Networks_Basics.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_neural_networks_foundations.ipynb"
  ["11_Neural_Networks_Training.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_neural_networks_foundations.ipynb"
  ["12_Word_Vectors.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_word_vectors.ipynb"
  ["13_RNN_and_Language_Models.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_recurrent_neural_networks.ipynb"
  ["14_Seq2Seq_and_Attention.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_seq2seq_and_attention.ipynb"
  ["15_Transformers_and_Pretraining.ipynb"]="https://raw.githubusercontent.com/futuremojo/nlp-demystified/main/notebooks/nlpdemystified_transformers_and_pretraining.ipynb"
)

# Download notebooks with proper filenames
for filename in "${!notebooks[@]}"; do
  url="${notebooks[$filename]}"
  echo "⬇️  Downloading $filename..."
  curl -sSL "$url" -o "$filename"
done

echo "✅ All notebooks downloaded in order with clear names."
