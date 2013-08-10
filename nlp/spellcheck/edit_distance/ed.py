f = open('words.txt')
lines = f.readlines()
f.close()

# Line format in words.txt :
# wrong_word;correct_word1,correct_word2\n


# Initializing the dictionary where the key is an incorrect word and
# the value is list of given corresponding correct words in words.txt
# w_c_mapping = {}

w_list = [] # Initializing the list of incorrect words
c_list = [] # Initializing the list of incorrect words

for l in lines:
	if len(l[:-1].split(';')) == 2:
		w, c = l[:-1].split(';')
	correct_words = c.split(',')
	for correct_word in correct_words:
		if correct_word not in c_list:
			c_list.append(correct_word)
	w_list.append(w)
	#w_c_mapping[w] = correct_words


def edit_dist(s1, s2):
    d = {}
    lenstr1 = len(s1)
    lenstr2 = len(s2)
    for i in xrange(-1,lenstr1+1):
        d[(i,-1)] = i+1
    for j in xrange(-1,lenstr2+1):
        d[(-1,j)] = j+1

    for i in xrange(lenstr1):
        for j in xrange(lenstr2):
            if s1[i] == s2[j]:
                cost = 0
            else:
                cost = 1
            d[(i,j)] = min(
                           d[(i-1,j)] + 1, # deletion
                           d[(i,j-1)] + 1, # insertion
                           d[(i-1,j-1)] + cost, # substitution
                          )
            if i and j and s1[i]==s2[j-1] and s1[i-1] == s2[j]:
                d[(i,j)] = min (d[(i,j)], d[i-2,j-2] + cost) # transposition
 
    return d[lenstr1-1,lenstr2-1]


def correct_the_wrong(w, c_list):

    min_ed = 1000

    for c in c_list:
        current_ed = edit_dist(w, c)
        if current_ed < min_ed:
            min_ed = current_ed
            predicted_c = []
            predicted_c.append(c)
        elif current_ed == min_ed:
            predicted_c.append(c)
    return predicted_c

# print correct_the_wrong(w_list, c_list)


"""
def correct_all_the_wrongs(w_list, c_list):
	predicted_w_c_mapping = {}

	for w in w_list:
		min_ed = 100
		for c in c_list:
			if c[0] == w[0]:
				current_ed = edit_dist(w, c)
			if current_ed < min_ed:
				min_ed = current_ed
				predicted_c = c
		predicted_w_c_mapping[w] = predicted_c

	return predicted_w_c_mapping

print correct_the_wrong(w_list, c_list)
"""
