# Convert to modified goat latin
# Rules:
#   1. If a word begins with a consonant (i.e. not a vowel), remove the first
#      letter and append it to the end, then add 'ma'.
#      For example, the word 'goat' becomes 'oatgma'.
#
#   2. If a word begins with a vowel (a, e, i, o, or u), append 'ma' to the end of the word.
#      For example, the word 'I' becomes 'Ima'.
#   3. Add one letter "a" to the end of each word per its word index in the
#      sentence, starting with 1. That is, the first word gets "a" added to the
#      And, the second word gets "aa" added to the end, the third word in the
#      Sentence gets "aaa" added to the end, and so on.
#
#

vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
newword  = []

def convert(word):
    #Check if vowel
    if word[0] in vowels:
       newword = word + "ma"
    else:
        newword = word[1:] + word[0] + "ma"

    return newword

def string_to_goat_latin(sentence):
    new_sent = ""
    sent1 = sentence.split(" ")
    count = 0
    for word in sent1:
        count += 1
        new_sent = new_sent + convert(word) + "a" * count
        new_sent = new_sent + " "

    print new_sent


if __name__ == '__main__':
    sentence = raw_input("Enter the sentence\n")
    string_to_goat_latin(sentence)


