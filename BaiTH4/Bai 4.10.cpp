//Nguyen Huu Dung - 20215545
#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<string>> doc; //Chua du lieu
vector<vector<string>> query; //Chua truy van
vector<int> f_max; // tan suat tu xuat hien nhieu nhat trong van ban i
map<string, int> df; // tu nam trong bao nhieu van ban
map<pair<string, int>, int> fe; // so lan xuat hien word trong van ban i 

// split string
vector<string> split(string str, string delimiter){ 
	vector<string> res; //vector chua cac tu cat ra 
    size_t pos = 0; //Vi tri dau ngan cach cac tu
    string token; //Bien luu tam tu 
    //Khi chuoi van con dau phay 
    while ((pos = str.find(delimiter)) != string::npos) { 
        token = str.substr(0, pos); //Cat chuoi thanh tu
        res.push_back(token); //push tu vao vector
        str.erase(0, pos + delimiter.length()); //Xoa tu
    }
    res.push_back(str); //Push tu cuoi cung vao vector
    return res;
}

// Nhap du lieu
void input(){
    vector<string> word_doc; //Van ban thu i
    vector<string> word_query; //Truy van thu i

    cin >> n;
    string tmp;
    getline(cin, tmp);

    for(int i=0; i<n; i++){ //Nhap Van ban thu i
        string tmp;
        getline(cin, tmp);
        word_doc.push_back(tmp);
    }

    cin >> q;
    getline(cin, tmp); 
    for(int i=0; i<q; i++){ //Nhap truy van thu i
        string tmp;
        getline(cin, tmp);
        word_query.push_back(tmp);
    }

    for(string v : word_doc){ //Cat van ban i thanh cac word va push vao doc
        vector<string> element = split(v,",");
        doc.push_back(element); 
    }

    for(string v : word_query){ //Cat truy van i thanh cac word va push vao query
        vector<string> element = split(v,",");
        query.push_back(element);
    }
}

// preprocessing
void pre_processing(){
    // tinh tan suat tu xuat hien nhieu nhat trong van ban i
    for(vector<string> tmp : doc){
        map<string, int> m;
        // thiet lap tu dien mini m voi chi so : [sotu] [tansuatxuathien]
        int max_f = 0;
        for(string word_tmp : tmp){
            map<string, int>::iterator ite = m.find(word_tmp);
            if(ite == m.end()){ // neu tu nay chua co trong tu dien mini
                m.insert({word_tmp, 1});
            } else {
                ite->second += 1;
            }
            max_f = max(m[word_tmp], max_f);
        }
        f_max.push_back(max_f);
    }
}

// so lan word xuat hien trong van ban i
int freq(string word, int i){
    if(fe.find({word, i}) != fe.end()){ // neu da co trong kho luu tru thi lay ra va tra ve
        return fe[{word, i}];
    }

    int index = 0;
    vector<string> tmp = doc[i];

    for(string v : tmp){
        if(word == v) index++;
    }

    fe.insert({{word, i}, index});
    return index;
}

// tinh xem tu word nam trong bao nhieu van ban
int count(string word){ // neu da co trong kho luu tru thi lay ket qua va tra ve
    if(df.find(word) != df.end()){
        return df[word];
    }

    int index = 0;
    for(vector<string> tmp : doc){
        vector<string>::iterator ite = find(tmp.begin(), tmp.end(), word);
        if(ite != tmp.end()){
            index++;
        }
    }

    df.insert({word,index});
    return index;
}

// du doan van ban
int search_engine(vector<string> list_word){
    double score_max = -1000;
    int predict_label = -1;
    for(int i=0; i<n; i++){
        vector<string> list_word_train_doc = doc[i];

        double score = 0;
        for(string word : list_word){
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word) == list_word_train_doc.end()){ // tu nay khong xuat hien trong van ban
                continue;
            } else {
                int ftd = freq(word, i);
                int dft = count(word);
                int maxfd = f_max[i];

                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n / dft);
                score += tf_word * idf_word;
            }
        }

        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }
    return predict_label + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    pre_processing();

    for(int i=0; i<q; i++)
        cout << search_engine(query[i]) << endl;

    return 0;
} //Nguyen Huu Dung - 20215545
