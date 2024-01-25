#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string.h>
#include <string>
#include <strings.h>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2);

int main() {
  // string text1("abcde");
  // string text2("ace");
  string text1(
      "fcvafurqjylclorwfoladwfqzkbebslwnmpmlkbezkxoncvwhstwzwpqxqtyxozkpgtgtsjo"
      "bujezgrkvevklmludgtyrmjaxyputqbyxqvupojutsjwlwluzsbmvyxifqtglwvcnkfsfglw"
      "jwrmtyxmdgjifyjwrsnenuvsdedsbqdovwzsdghclcdexmtsbexwrszihcpibwpidixmpmxs"
      "hwzmjgtadmtkxqfkrsdqjcrmxkbkfoncrcvoxuvcdytajgfwrcxivixanuzerebuzklyheze"
      "vonqdsrkzetsrgfgxibqpmfuxcrinetyzkvudghgrytsvwzkjulmhanankxqfihenuhmfsfk"
      "fepibkjmzybmlkzozmluvybyzsleludsxkpinizoraxonmhwtkfkhudizepyzijafqlepcbi"
      "hofepmjqtgrsxorunshgpazovuhktatmlcfklafivivefyfubunszyvarcrkpsnglkduzaxq"
      "rerkvcnmrurkhkpargvcxefovwtapedaluhclmzynebczodwropwdenqxmrutuhehadyfspc"
      "puxyzodifqdqzgbwhodcjonypyjwbwxepcpujerkrelunstebopkncdazexsbezmhynizsva"
      "rafwfmnclerafejgnizcbsrcvcnwrolofyzulcxaxqjqzunedidulspslebifinqrchyvapk"
      "zmzwbwjgbyrqhqpolwjijmzyduzerqnadapudmrazmzadstozytonuzarizszubkzkhenaxi"
      "vytmjqjgvgzwpgxefatetoncjgjsdilmvgtgpgbibexwnexstipkjylalqnupexytkradwxm"
      "lmhsnmzuxcdkfkxyfgrmfqtajatgjctenqhkvyrgvapctqtyrufcdobibizihuhsrsterozo"
      "tytubefutaxcjarknynetipehoduxyjstufwvkvwvwnuletybmrczgtmxctuny");
  string text2(
      "nohgdazargvalupetizezqpklktojqtqdivcpsfgjopaxwbkvujilqbclehulatshehmjqhy"
      "fkpcfwxovajkvankjkvevgdovazmbgtqfwvejczsnmbchkdibstklkxarwjqbqxwvixavkhy"
      "lqvghqpifijohudenozotejoxavkfkzcdqnoxydynavwdylwhatslyrwlejwdwrmpevmtwpa"
      "hatwlaxmjmdgrebmfyngdcbmbgjcvqpcbadujkxaxujudmbejcrevuvcdobolcbstifedcvm"
      "ngnqhudixgzktcdqngxmruhcxqxypwhahobudelivgvynefkjqdyvalmvudcdivmhghqrelu"
      "rodwdsvuzmjixgdexonwjczghalsjopixsrwjixuzmjgxydqnipelgrivkzkxgjchibgnqbk"
      "nstspujwdydszohqjsfuzstyjgnwhsrebmlwzkzijgnmnczmrehspihspyfedabotwvwxwps"
      "pypctizyhcxypqzctwlspszonsrmnyvmhsvqtkbyhmhwjmvazaviruzqxmbczaxmtqjexmdu"
      "dypovkjklynktahupanujylylgrajozobsbwpwtohkfsxeverqxylwdwtojoxydepybavwhg"
      "dehafurqtcxqhuhkdwxkdojipolctcvcrsvczcxedglgrejerqdgrsvsxgjodajatsnixuti"
      "hwpivihadqdotsvyrkxehodybapwlsjexixgponcxifijchejoxgxebmbclczqvkfuzgxsbs"
      "hqvgfcraxytaxeviryhexmvqjybizivyjanwxmpojgxgbyhcruvqpafwjslkbohqlknkdqji"
      "xsfsdurgbsvclmrcrcnulinqvcdqhcvwdaxgvafwravunurqvizqtozuxinytafopmhchmxs"
      "xgfanetmdcjalmrolejidylkjktunqhkxchyjmpkvsfgnybsjedmzkrkhwryzan");
  //   string text1("oxcpqrsvwf");
  //   string text2("shmtulqrypy");

  cout << "ret : " << longestCommonSubsequence(text1, text2) << endl;
}

void matchOccurences(int occurences[1000][1000], string &needle,
                     string &haystack) {
  size_t pos;
  // cout << needle[0] << endl;
  // return;
  for (int i = 0; i < needle.size(); i++) {
    pos = 0;
    while (1) {
      pos = haystack.find(needle[i], pos);
      if (pos != string::npos)
        occurences[i][pos++] = 1;
      else
        break;
    }
  }
}

void printOccurences(int occurences[1000][1000], string &needle,
                     string &haystack) {

  cout << endl << "----------------------------------" << endl;
  cout << "    ";
  for (int i = 0; i < haystack.size(); i++) {
    cout << haystack[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < needle.size(); i++) {
    cout << needle[i] << "   ";
    for (int j = 0; j < haystack.size(); j++) {
      cout << occurences[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl << "----------------------------------" << endl;
}

bool isInArea(vector<vector<int>> &candidates, int x, int y) {
  for (int i = 0; i < candidates.size(); i++) {
    if (x >= candidates[i][0] && y >= candidates[i][1])
      return true;
  }
  return false;
}

bool compare(vector<int> c1, vector<int> c2) {
  //   cout << endl;
  //   for (int i = 0; i < c1.size(); i++)
  //     cout << c1[i] << " ";
  //   cout << endl;
  return c1[2] < c2[2];
}

// struct myclass {
//   bool operator()(vector<int> c1, vector<int> c2) { return c1[2] < c2[2]; }
// } compare;

int calculateLongestSequence(int occurences[1000][1000], size_t n, size_t m,
                             int offsetx, int offsety) {
  int ret;
  vector<vector<int>> candidates;

  ret = 0;
  for (int i = offsety; i < n; i++) {
    for (int j = offsetx; j < m; j++) {
      if (isInArea(candidates, j, i))
        continue;
      if (occurences[i][j]) {
        vector<int> candidate;

        ret = 1;
        candidate.push_back(j);
        candidate.push_back(i);
        candidates.push_back(candidate);
      }
    }
  }
  if (candidates.empty())
    return 0;
  for (int i = 0; i < candidates.size(); i++) {
    candidates[i].push_back(calculateLongestSequence(
        occurences, n, m, candidates[i][0] + 1, candidates[i][1] + 1));
  }
  vector<vector<int>>::iterator it =
      max_element(candidates.begin(), candidates.end(), compare);
  return ret + it->at(2);
}

int longestCommonSubsequence(string text1, string text2) {
  int occurences[1000][1000];

  string *needle;
  string *haystack;

  needle = text1.size() < text2.size() ? &text1 : &text2;
  haystack = text1.size() < text2.size() ? &text2 : &text1;

  bzero(occurences, sizeof(occurences));

  matchOccurences(occurences, *needle, *haystack);
  printOccurences(occurences, *needle, *haystack);
  return calculateLongestSequence(occurences, needle->size(), haystack->size(),
                                  0, 0);
}