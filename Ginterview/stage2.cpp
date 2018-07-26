#include <iostream>
#include <list>
#include <array>
#include <queue>

using namespace std;


int main()
{
    vector<pair<string, list<string>>> vresSyns;
    vector<pair<string, string>> vsyns;
    list<string> prel_list;

    vsyns.push_back(make_pair("buy", "purchase"));
    vsyns.push_back(make_pair("buy", "something"));

    vsyns.push_back(make_pair("car", "auto"));
    vsyns.push_back(make_pair("car", "machine"));
    vsyns.push_back(make_pair("car", "vehicle"));

    vsyns.push_back(make_pair("company", "geschaft"));
    vsyns.push_back(make_pair("company", "unternehmen"));

    auto iter_word = vsyns.begin();
    string init_word_syn;

    init_word_syn = iter_word->first;
    prel_list.push_back(iter_word->second);
    iter_word++;

    while (iter_word != vsyns.end())
    {
        if (iter_word->first == init_word_syn)
        {
            prel_list.push_back("," + iter_word->second);
            iter_word++;
        }
        else
        {
            vresSyns.push_back(make_pair(init_word_syn + ",", prel_list));
            prel_list.clear();

            init_word_syn = iter_word->first;
            prel_list.push_back(iter_word->second);
            iter_word++;


        }
    }
    vresSyns.push_back(make_pair(init_word_syn + ",", prel_list));

    for (int i = 0; i < vresSyns.size(); ++i)
    {
        cout << vresSyns[i].first << " ";
        for (auto &it : vresSyns[i].second)
        {
            init_word_syn = it.data();
            cout << init_word_syn << " ";
        }
        cout << endl;
    }

    return 0;
}