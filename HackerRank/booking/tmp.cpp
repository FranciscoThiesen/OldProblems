bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

string to_lower(string& s){
    int sz = (int) s.size();
    for(int i = 0; i < sz; ++i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
    }
    return s;
}
/*
 * Complete the function below.
 */
vector <int> sort_hotels(string keywords, vector <int> hotel_ids, vector <string> reviews) {
    set<string> dict;
    string tmp;
    int t = (int) keywords.size();
    for(int i = 0; i < t; ++i){
        if(keywords[i] == ' '){
            if(tmp.empty()) continue;
            dict.insert(tmp);
            tmp = "";
        }
        else{
            if(keywords[i] >= 'A' && keywords[i] <= 'Z') keywords[i] += 32;
            tmp += keywords[i];
        }
    }
    dict.insert(tmp); // inserting the last word

    vector<int> scorePerHotel(10000, -1);
    int bound = (int) reviews.size();
    for(int i = 0; i < bound; ++i){
        string tmp;
        int tam = (int) reviews[i].size();
        for(int j = 0; j < tam; ++j){
            if(reviews[i][j] >= 'A' && reviews[i][j] <= 'Z') reviews[i][j] += 32;
            if(reviews[i][j] == ' '){
                if(dict.find(tmp) != dict.end()){
                    scorePerHotel[hotel_ids[i]]++;
                }
                tmp = "";
            }
            else if(reviews[i][j] == '.' || reviews[i][j] == ',') continue;
            else tmp += reviews[i][j];
        }
        if(dict.find(tmp) != dict.end()){
            scorePerHotel[hotel_ids[i]]++;
        }
    }
    vector<pair<int, int> > perHotel;
    vector<int> aux;
    for(const auto& v : hotel_ids){
        if(scorePerHotel[v] == -1) continue;
        perHotel.push_back(make_pair(scorePerHotel[v], v));
        scorePerHotel[v] = -1;
    }
    sort(perHotel.begin(), perHotel.end(), cmp);
    vector<int> ans;
    for(const pair<int, int>& x : perHotel) ans.push_back(x.second);
    return ans;
    
}
