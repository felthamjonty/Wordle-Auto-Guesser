WORDLE AUTO WORD GUESSER
----------------------------------
This small script made with C++. This script looks for the most
likely word to guess for the game "Wordle"
(https://www.nytimes.com/games/wordle), while following the results
of previous guesses.
This script has much room to improve/ be optimized and may have a
few issues still lying around.

To run it, just Execute "Wordle Auto Word Guesser.exe" and follow
the in-terminal instructions.

----------------------------------
OTHER TOOLS
----------------------------------
In the "data" folder various other exes can be found:
-WordValidCheck.exe tells you weather a word has already been done in a previous wordle (false) or not (true) when you input a word

to be adjusted in a code editor/ide:
-InvalidatePastWords.exe checks the dictionary against the past wordles and adds all the available words to valid-wordsAdjusted.txt
-AlphabetWeightDistribution.exe takes valid-wordsAdjusted.txt and measures how common each letter is and returns a "value"
-WordsWeightDistribution.exe when the alphbet valuability is given in the cpp file, it weighs all the valid words and inputs it to weighted-wordle-words.txt

the main exe:
-WordleBestGuesser.exe

Aswell as text files:
-past-wordles.txt contains all the past wordles as of 25/11/25
Feel free to update pass that if desired
-valid-wordle-words.txt is the entire worlde dictionary
-valid-wordsAdjusted.txt is the wordle dictionary without all the past wordles
-weighted-wordle-words.txt is the weighted words from valid-wordsAdjusted.txt with the higher number showing the "value"
