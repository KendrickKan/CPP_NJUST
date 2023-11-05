from transformers import BartTokenizer, BartForSequenceClassification

# 模型名称
model_name = 'facebook/bart-large-mnli'

# 下载并保存分词器
tokenizer = BartTokenizer.from_pretrained(model_name)
tokenizer.save_pretrained('E:/bart/tokenizer/')

# 下载并保存模型
model = BartForSequenceClassification.from_pretrained(model_name)
model.save_pretrained('E:/bart/model/')
