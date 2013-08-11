from numpy import genfromtxt
import re, collections


def words(text): return re.findall('[a-z]+', text.lower()) 
def train(features):
    model = collections.defaultdict(lambda: 1)
    for f in features:
        model[f] += 1
    return model

# Get big.txt from Norvig's spell checker webpage
NWORDS = train(words(file('/home/ankit/Downloads/big.txt').read()))


f = open('words.txt')
lines = f.readlines()
f.close()

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


DT = genfromtxt('deletiontable.csv', delimiter=',')
dt = DT[1:, 1:]

IT = genfromtxt('insertionstable.csv', delimiter=',')
it = IT[1:, 1:]

ST = genfromtxt('substitutionstable.csv', delimiter=',')
st = ST[1:, 1:]

TT = genfromtxt('transpositionstable.csv', delimiter=',')
tt = TT[1:, 1:]



def get_best_candidate(w, candidates):
    maximum = - 1000
    best_candidate = 'dummy-crap'

    for i in candidates:
        score = NWORDS[i] * get_error_model_prob(w, i)
        print "Unnormalized P(c|w) where c is " + i + " : " + str(score)
        if score > maximum:
            maximum = score
            best_candidate = i
    return best_candidate


def get_error_model_prob(w, c):
    w = w.replace(" ", "{")
    c = c.replace(" ", "{")
    if len(w) == len(c) + 1:
        if w[0] != c[0]:
            return it[26][ord(w[0]) % 97]
        for i in range(1, len(c)):
            if w[i] != c[i]:
                return it[ord(c[i - 1]) % 97][ord(w[i]) % 97]
        return it[ord(c[-1]) % 97][ord(w[-1]) % 97]

    elif len(w) == len(c):
        wl = list(w)
        cl = list(c)
        count = 0
        for i in range(len(w)):
            if wl[i] != cl[i]:
                count += 1
                if i + 1 < len(w):
                    if wl[i + 1] != cl[i + 1]:
                        return tt[ord(cl[i]) % 97][ord(cl[i + 1]) % 97]
                return st[ord(cl[i]) % 97][ord(wl[i]) % 97]

    elif len(c) == len(w) + 1:
        if c[0] != w[0]:
            return dt[26][ord(c[0]) % 97]
        for i in range(1, len(w)):
            if c[i] != w[i]:
                return dt[ord(c[i - 1]) % 97][ord(c[i]) % 97]
        return dt[ord(w[-1]) % 97][ord(c[-1]) % 97]


def _edit_dist(s1, s2):
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


def get_candidates(w):
    predicted_c =[]
    for c in c_list:
        current_ed = _edit_dist(w, c)
        if current_ed == 1:
            predicted_c.append(c)
    return predicted_c

