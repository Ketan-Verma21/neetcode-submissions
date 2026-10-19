class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord)) {
            return 0;
        }

        queue<string> frontQueue;
        queue<string> backQueue;

        unordered_map<string, int> frontDist;
        unordered_map<string, int> backDist;

        frontQueue.push(beginWord);
        backQueue.push(endWord);

        frontDist[beginWord] = 1;
        backDist[endWord] = 1;

        const int wordLength = beginWord.length();

        while (!frontQueue.empty() && !backQueue.empty()) {

            if (frontQueue.size() > backQueue.size()) {
                swap(frontQueue, backQueue);
                swap(frontDist, backDist);
            }

            string current = frontQueue.front();
            frontQueue.pop();

            int currentDistance = frontDist[current];

            for (int i = 0; i < wordLength; ++i) {
                string next = current;

                for (char character = 'a'; character <= 'z'; ++character) {
                    if (character == current[i]) {
                        continue;
                    }

                    next[i] = character;

                    if (!words.count(next)) {
                        continue;
                    }

                    if (backDist.count(next)) {
                        return currentDistance + backDist[next];
                    }

                    if (!frontDist.count(next)) {
                        frontDist[next] = currentDistance + 1;
                        frontQueue.push(next);
                    }
                }
            }
        }

        return 0;
    }
};