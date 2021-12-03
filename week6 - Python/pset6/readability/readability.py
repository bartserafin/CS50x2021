from cs50 import get_string

text = get_string('Text: ')
text = text.upper()
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
sentences = ['.', '!', '?']
omit = ['..']
count_letters = 0
count_words = 0
count_sentences = 0
i = 0

for character in text:

    #  Count letters in text
    if character in alphabet:
        count_letters += 1

    #  Count sentences in text
    if character in sentences:
        count_sentences += 1
        # this doesnt consider ..... <- this would be 4 sentences!

    #  Count words in text
    if character == ' ':
        count_words += 1

    i += 1

count_words += 1

# print('Letters:', count_letters, '\nSentences:', count_sentences, '\nWords:', count_words)

#  Count Coleman-Liau index.
# average numbers of letters per 100 words
L = float(count_letters * 100.0 / count_words)

# average number of sentences per 100 words
S = float(count_sentences * 100.0 / count_words)
index = round(0.0588 * L - 0.296 * S - 15.8)

#  Display Grade result
if index <= 1:
    print('Before Grade 1')
elif index >= 16:
    print('Grade 16+')
else:
    print('Grade:', index)