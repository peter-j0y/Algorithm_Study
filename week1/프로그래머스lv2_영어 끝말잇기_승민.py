def solution(n, words):
    answer = []
    lastAlphabet = ''
    for i in range(len(words)):
        if checkWord(words[i], lastAlphabet) and checkSame(words[i], words, i):
            lastAlphabet = words[i][-1]
            continue
        
        else:
            index = (i+1) % n
            if index == 0:
                index = n
            
            turn = i // n + 1
            answer.append(index)
            answer.append(turn)
            break
    
    if not answer:
        answer.append(0)
        answer.append(0)
    
    return answer

def checkWord(word, alphabet):
    if alphabet == '' or word[0] == alphabet:
        return True
    return False

def checkSame(word, words, index):
    for i in range(len(words)):
        if i < index and words[i] == word:
            return False
    return True