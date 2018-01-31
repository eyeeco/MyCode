class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        sentenceList = sentence.split(" ");
        for i in range(len(sentenceList)):
            for j in dict:
                if sentenceList[i].startswith(j):
                    sentenceList[i] = j
        return " ".join(sentenceList)
