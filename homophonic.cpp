#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>  makeLayout(){
  vector<vector<int>> layout (26);
  layout[0]={9,12,33,47,53,67,78,92};
  layout[1]={48,81};
  layout[2]={13,41,62};
  layout[3]={1,3,45,79};
  layout[4]={14,16,24,44,46,55,57,64,74,82,87,98};
  layout[5]={10,31};
  layout[6]={6,25};
  layout[7]={23,39,50,56,65,68};
  layout[8]={32,70,73,83,88,93};
  layout[9]={15};
  layout[10]={4};
  layout[11]={26,37,51,84};
  layout[12]={22,27};
  layout[13]={18,58,59,66,71,91};
  layout[14]={0,5,7,54,72,90,99};
  layout[15]={38,95};
  layout[16]={94};
  layout[17]={29,35,40,42,77,80};
  layout[18]={11,19,36,76,86,96};
  layout[19]={17,20,30,43,49,69,75,85,97};
  layout[20]={8,61,63};
  layout[21]={34};
  layout[22]={60,89};
  layout[23]={28};
  layout[24]={21,52};
  layout[25]={2};

  return layout;
}
string checkText(string line){
  line.erase(remove(line.begin(), line.end(), ' '), line.end());
  transform(line.begin(), line.end(), line.begin(), ::tolower);
  return line;
}
vector<int> Cipher(string plainText, vector<vector<int>>  &layout){
  plainText = checkText(plainText);
  vector<int> result;

  srand(static_cast<unsigned int>(time(0)));
  int random_number;
  int selected;

  for(int i : plainText){
    i -=97;
    random_number = rand() % layout[i].size();
    result.push_back(layout[i][random_number]);
  }
  return result;

}

vector<char> Decryptor(vector<int> cipherText, vector<vector<int>>  &layout){
  vector<char> result;
  for(int letter: cipherText){
    for(int i = 0; i < layout.size(); i++){
      for(int j: layout[i]){
        if(j ==letter){
          result.push_back((char)(i+97));
          break;
        }
      }
  }
  }
  return result;
}
int main(){
  vector<vector<int>> layout = makeLayout();
  int option; cin >> option;
  if(option == 0){
    cin>>ws;
    string plainText; getline(cin, plainText);
    vector<int> values = Cipher(plainText, layout);
    for(int i: values)cout << i <<" ";
  }else{
    int l,aux; cin >> l;
    vector<int> cipherText;
    for (int i = 0; i < l; i++)
    {
      cin >> aux;
      cipherText.push_back(aux);
    }
    vector<char> values = Decryptor(cipherText, layout);

    for(auto i: values)cout << i;

  }
  
}