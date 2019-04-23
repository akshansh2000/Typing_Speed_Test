#include <bits/stdc++.h>
#include <termios.h>

static struct termios old, new1;

/* Initialize new1 terminal i/o settings */
void initTermios(int echo) {
  tcgetattr(0, &old);      /* grab old terminal i/o settings */
  new1 = old;              /* make new1 settings same as old settings */
  new1.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
    new1.c_lflag |= ECHO; /* set echo mode */
  } else {
    new1.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &new1); /* use these new1 terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) {
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) {
  return getch_(1);
}

using namespace std;

string test[] = {
    "drop", "back", "village", "men", "subject", "tell", "old", "guess", "can",
    "fit", "thought", "govern", "up", "path", "hour", "engine", "while",
    "general", "build", "tire", "syllable", "strange", "steel", "condition",
    "market", "young", "answer", "flower", "me", "center", "continue", "verb",
    "ice", "trade", "sudden", "touch", "get", "fruit", "tool", "pick", "triangle",
    "five", "live", "then", "mount", "cross", "group", "kept", "shop", "rain",
    "all", "happen", "level", "cook", "color", "for", "read", "broke", "love",
    "iron", "see", "as", "square", "so", "meet", "station", "strong", "heart",
    "evening", "day", "page", "here", "sell", "climb", "second", "other",
    "string", "break", "shoulder", "have", "word", "in", "fine", "rail", "hair",
    "turn", "current", "shore", "little", "season", "out", "material", "thick",
    "sound", "distant", "cool", "region", "enter", "complete", "earth", "well",
    "stone", "multiply", "hope", "danger", "claim", "decimal", "create", "set",
    "chick", "arrange", "dog", "middle", "table", "swim", "fast", "machine",
    "fall", "start", "children", "write", "won't", "afraid", "atom", "parent",
    "forward", "modern", "six", "smile", "boat", "sun", "thing", "die", "think",
    "direct", "watch", "person", "face", "past", "company", "process", "suffix",
    "colony", "animal", "serve", "such", "perhaps", "gone", "wheel", "decide",
    "soft", "way", "we", "hold", "under", "meant", "he", "learn", "slow", "plant",
    "grand", "race", "fill", "look", "heard", "about", "win", "paper", "course",
    "our", "money", "rub", "took", "rest", "war", "happy", "minute", "view",
    "room", "true", "wood", "egg", "gather", "hundred", "horse", "son", "chance",
    "were", "character", "whether", "case", "especially", "tube", "best", "often",
    "problem", "base", "twenty", "mother", "skill", "gas", "could", "round",
    "your", "sentence", "which", "count", "her", "good", "black", "try", "hot",
    "spot", "top", "ocean", "notice", "team", "major", "sign", "pattern", "skin",
    "deal", "people", "probable", "element", "there", "million", "on", "grass",
    "result", "stand", "that", "figure", "agree", "want", "warm", "branch",
    "method", "two", "you", "listen", "stood", "effect", "tall", "only", "much",
    "crowd", "river", "seed", "double", "proper", "half", "electric", "type",
    "sat", "doctor", "small", "save", "section", "care", "opposite", "imagine",
    "fly", "close", "truck", "lake", "play", "indicate", "dead", "control", "end",
    "leave", "support", "solve", "wrote", "area", "property", "receive", "ground",
    "head", "of", "full", "led", "find", "tail", "liquid", "busy", "clean",
    "believe", "would", "by", "range", "correct", "cow", "mountain", "those",
    "line", "sugar", "stead", "ball", "told", "degree", "hard", "follow", "spell",
    "form", "held", "few", "no", "power", "baby", "spoke", "draw", "leg", "off",
    "pretty", "brought", "total", "bank", "woman", "require", "kind", "hat",
    "question", "human", "stream", "lie", "hear", "year", "night", "one", "show",
    "yard", "expect", "oh", "fish", "shoe", "wall", "burn", "clear", "smell",
    "fear", "written", "why", "depend", "energy", "trip", "late", "soldier",
    "sheet", "chief", "ago", "represent", "far", "finish", "snow", "wind", "roll",
    "eye", "silver", "his", "sharp", "numeral", "game", "cut", "put", "band",
    "arrive", "join", "are", "sail", "weather", "rule", "blow", "three", "tone",
    "friend", "know", "letter", "corner", "print", "last", "favor", "silent",
    "scale", "with", "broad", "industry", "success", "she", "pull", "beat",
    "both", "time", "sit", "them", "laugh", "practice", "part", "shape", "pair",
    "cloud", "subtract", "nose", "shine", "over", "map", "rose", "run", "send",
    "locate", "drive", "block", "above", "supply", "enough", "knew", "month",
    "him", "brother", "poem", "next", "deep", "fact", "note", "apple", "able",
    "how", "equate", "spend", "blood", "bone", "yellow", "salt", "fat", "lot",
    "determine", "substance", "gave", "suggest", "several", "a", "bell", "root",
    "separate", "throw", "temperature", "oil", "also", "air", "right", "hole",
    "cold", "speak", "noun", "bar", "once", "row", "down", "mind", "surprise",
    "force", "west", "suit", "either", "kill", "poor", "more", "reply",
    "position", "collect", "travel", "has", "been", "began", "again", "cent",
    "is", "reason", "yes", "crop", "master", "sleep", "house", "soil", "joy",
    "own", "search", "never", "nor", "divide", "land", "describe", "bright",
    "prove", "ran", "wire", "new", "insect", "carry", "light", "world", "lay",
    "consonant", "coast", "island", "short", "dollar", "system", "sense", "field",
    "chart", "near", "red", "said", "fresh", "they", "be", "idea", "life",
    "wrong", "bread", "clothe", "wide", "dream", "jump", "quotient", "appear",
    "to", "bought", "just", "sky", "ring", "step", "green", "dad", "any", "very",
    "ride", "same", "bad", "law", "eat", "basic", "connect", "valley", "mine",
    "hurry", "come", "age", "fair", "captain", "cause", "equal", "edge", "wear",
    "and", "plane", "term", "except", "column", "seem", "these", "done", "piece",
    "finger", "quiet", "should", "fight", "contain", "lift", "charge",
    "continent", "wait", "molecule", "lady", "front", "south", "excite", "allow",
    "stop", "against", "meat", "pitch", "four", "must", "will", "ear", "death",
    "bottom", "moon", "bed", "planet", "sister", "crease", "compare",
    "particular", "speed", "milk", "large", "simple", "always", "city", "track",
    "pose", "test", "whose", "original", "rope", "duck", "am", "spread", "still",
    "wish", "felt", "capital", "from", "symbol", "many", "possible", "cell",
    "vary", "plan", "desert", "eight", "fell", "my", "buy", "develop", "summer",
    "neck", "main", "or", "between", "week", "heat", "push", "cover", "cost",
    "go", "work", "division", "child", "visit", "thin", "dictionary", "chord",
    "dark", "might", "hand", "phrase", "voice", "let", "country", "it", "reach",
    "rock", "during", "consider", "sure", "tree", "ten", "melody", "wild", "camp",
    "remember", "left", "family", "don't", "great", "door", "grew", "book",
    "raise", "us", "first", "inch", "exercise", "born", "final", "ever", "sand",
    "corn", "though", "pass", "the", "was", "flow", "fraction", "offer", "store",
    "floor", "mark", "gold", "present", "better", "prepare", "place", "bear",
    "arm", "until", "dear", "check", "low", "organ", "open", "call", "spring",
    "metal", "stretch", "school", "shout", "produce", "include", "oxygen",
    "winter", "does", "east", "third", "century", "cotton", "glad", "dress",
    "ask", "mile", "box", "invent", "tiny", "body", "shell", "copy", "self",
    "protect", "feel", "food", "space", "at", "number", "toward", "need", "shall",
    "where", "brown", "party", "what", "wave", "trouble", "dry", "move", "magnet",
    "sing", "soon", "operate", "saw", "morning", "some", "nothing", "history",
    "mouth", "through", "common", "begin", "act", "list", "famous", "hill",
    "card", "job", "miss", "instant", "design", "but", "plural", "huge",
    "science", "street", "quite", "stick", "story", "post", "radio", "usual",
    "found", "experiment", "event", "before", "least", "pay", "paint", "boy",
    "lost", "after", "high", "rich", "order", "straight", "window", "foot",
    "song", "take", "sea", "cat", "differ", "thus", "may", "wonder", "loud",
    "circle", "guide", "pound", "dance", "town", "solution", "object", "state",
    "whole", "motion", "lead", "their", "ease", "water", "forest", "record",
    "this", "experience", "moment", "single", "keep", "bit", "bird", "free",
    "product", "every", "mix", "similar", "thank", "office", "now", "mass",
    "flat", "difficult", "match", "car", "clock", "grow", "ship", "beauty",
    "feet", "when", "hunt", "blue", "special", "came", "quick", "key", "fire",
    "an", "cry", "class", "settle", "instrument", "each", "together", "seat",
    "thousand", "matter", "teeth", "I", "bring", "train", "anger", "fun", "do",
    "real", "like", "slave", "music", "art", "glass", "bat", "press", "use",
    "name", "slip", "select", "rise", "caught", "coat", "women", "share",
    "discuss", "noise", "early", "star", "observe", "girl", "steam", "change",
    "noon", "surface", "yet", "say", "garden", "sent", "heavy", "help", "than",
    "long", "drink", "too", "ready", "rather", "speech", "nation", "chair",
    "weight", "example", "natural", "home", "road", "exact", "among", "stay",
    "else", "add", "study", "quart", "repeat", "board", "gray", "wing", "nine",
    "fig", "enemy", "wash", "went", "had", "language", "lone", "sight", "hot",
    "log", "farm", "feed", "who", "size", "measure", "made", "talk", "neighbor",
    "side", "king", "unit", "catch", "if", "provide", "necessary", "mean", "port",
    "paragraph", "seven", "since", "big", "gun", "man", "safe", "nature",
    "length", "student", "plain", "score", "got", "father", "picture", "hit",
    "behind", "please", "certain", "value", "period", "white", "did", "choose",
    "walk", "north", "even", "interest", "occur", "point", "less", "segment",
    "gentle", "give", "populate", "most", "make", "teach", "tie", "wife", "vowel"};

string ans, print;
char temp;

int main() {
  srand(time(NULL));
start:
  int size = sizeof(test) / sizeof(test[0]);
  print = test[(rand()) % size];
  fflush(stdout);
  system("clear");
  cout << '\r' << print << endl;
  ans.clear();
  chrono::steady_clock::time_point end = chrono::steady_clock::now() + chrono::seconds(4);

  while (ans != print && chrono::steady_clock::now() < end) {
    temp = getch();
    if ((int)temp == 127 && ans.length())
      ans.erase(ans.end() - 1);
    else if ((int)temp != 127)
      ans += temp;
    system("clear");
    fflush(stdout);
    cout << print << "\n\r" << ans;
  }

  if (ans == print)
    goto start;

  else {
    fflush(stdout);
    system("clear");
    cout << "Game over!" << endl;
  }
}
